/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Implementation of Player Class         *
 ***********************************************************/

#include <iostream>
#include <sstream>
#include <string>
#include <math.h>

#include "Player.h"
#include "GoalKeeper.h"
#include "Defender.h"
#include "MidFielder.h"
#include "Forward.h"

#define PI 3.14159265

/****************************************************************************************************
 * function name: convertToString                                                                   *
 * The Input: T type (template)                                                                     *
 * The output: string                                                                               *
 * The Function Opertion: Returns the string version of the input type.                             *
 * *************************************************************************************************/

template <typename T>
inline std::string convertToString(T tType) {
    
    std::ostringstream oss;
    
    oss << tType;
    
    // Return the resulting string
    return oss.str();
    
}

double cotan(double i) { return(1 / tan(i * PI / 180.0)); }

//  ---                         PRIVATE FUNCTIONS                       ---   //

/****************************************************************************************************
 * function name: execute                                                                           *
 * The Input: none                                                                                  *
 * The output: none                                                                                 *
 * The Function Opertion: Performs in a loop. Gets an available State from the ConnectionHandler,   *
 *                        and calls to update the appropriate functions on the inherited class.     *
 *                        After all States have been updated, calls endAct to send the instructions *
 *                        made by the called act functions to the server.                           *
 * *************************************************************************************************/

void Player::execute() {
    
    /*
     * Remove an object from the queue and act by it.
     * This will hold the calling thread (player) from continuing execution
     * and continue once a state has been recieved.
     */
    
    //Perform act in a loop (this is a threaded action)
    while (true) {
        
        //Get the current field state
        State *cState = m_qStateQueue.pop();
        
        m_cMutualExclusion.lock();

        switch (cState->eType) {
            case StateTypeBody:
                
                //Indicated behaviour change, act by it (each inherited object will have it's list of instructions filled)
                if (m_cBodyState != NULL)
                    delete m_cBodyState;
                
                m_cBodyState = static_cast<BodyState*>(cState);
                
                m_cMutualExclusion.unlock();
                
                m_cBrain.updateState(*m_cBodyState);
                
                break;
                
            case StateTypeTeam:
                
                //Update the stored GameState
                if (m_cTeamState != NULL)
                    delete m_cTeamState;
                
                m_cTeamState = static_cast<TeamState*>(cState);
                
                m_cMutualExclusion.unlock();

                actPlayMode(m_cTeamState->playMode);
                m_cBrain.updateState(*m_cTeamState);
                
                break;
                
            case StateTypePlayer:
                
                //Add to the stored PlayerState
                m_vcPlayerStates.push_back(static_cast<const PlayerState*>(cState));
                
                m_cMutualExclusion.unlock();

                break;
                
                case StateTypeServer:
                
                //Update the stored GameState
                if (m_cServerState != NULL)
                    delete m_cServerState;
                
                m_cServerState = static_cast<ServerState*>(cState);
                
                m_cMutualExclusion.unlock();

                break;
                
            case StateTypeSee:
                
                //Update the stored GameState
                if (m_cSeeState != NULL)
                    delete m_cSeeState;
                
                m_cSeeState = static_cast<SeeState*>(cState);
                
                m_cMutualExclusion.unlock();

                m_cBrain.updateState(*m_cSeeState);

                break;
                
            case StateTypeHear:
                
                //Update the stored GameState
                if (m_cHearState != NULL)
                    delete m_cHearState;
                
                m_cHearState = static_cast<HearState*>(cState);
                
                //Update the team value (play mode)
                m_cTeamState->convert(*m_cHearState);

                m_cMutualExclusion.unlock();

                //We use the PlayMode variable only in TeamState
                actPlayMode(m_cTeamState->playMode);
                m_cBrain.updateState(*m_cTeamState);
                
                break;
                
            //Shouldnt reach here
            default:
                
                //Unlock just in case
                m_cMutualExclusion.unlock();
                break;
        }
        
        //Dont update until has body and sight states
        if (m_cSeeState != NULL && m_cBodyState != NULL) {
        
            //Update the brain that an act has been started
            m_cBrain.startAct();
            
        }
        
    }
    
}

//  ---                         PROTECTED FUNCTIONS                       ---   //


/****************************************************************************************************
 * function name: getBrain                                                                          *
 * The Input: none                                                                                  *
 * The output: Brain object (reference)                                                             *
 * The Function Opertion: Returns the player's brain held in a member variable.                     *
 * *************************************************************************************************/

Brain& Player::getBrain() {
    
    //Return the held brain
    return m_cBrain;
    
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: Player Constructor                                                            *
 * The Input: const Connection object (pointer), const char (pointer), const Vector (reference) *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the member variables to default valies, tries to enlist   *
 *                        to the Robocup server. If successful start the connection hander      *
 *                        and moves to the appropriate place, otherwise stops.                  *
 * *********************************************************************************************/

Player::Player(const Connection* cConnection, const char* chTeamName) :
m_cConnectionHandler(*cConnection, m_qInstructionQueue, m_qStateQueue), m_cBrain(m_qInstructionQueue) {

    //Initialise the member variables
    m_cTeamState = NULL;
    m_cBodyState = NULL;
    m_cServerState = NULL;
    m_cSeeState = NULL;
    m_cHearState = NULL;
    
    //First enlist the robot to the server - if not successful then this is fatal, so dont start the player
    if(!m_cConnectionHandler.enlistRobocup(chTeamName))
        return;
    
    //Once the player is enlisted - start running the internal ConnectionHandler - it will work with the shared queues
    m_cConnectionHandler.start();
    
}

/**********************************************************************************************
 * function name: Player Destructor                                                           *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Deletes the states that were stored in the player.                  *
 * *******************************************************************************************/

Player::~Player() {

    //No more need for states
    if (m_cTeamState != NULL)
        delete m_cTeamState;
    
    if (m_cServerState != NULL)
        delete m_cServerState;
    
    if (m_cBodyState != NULL)
        delete m_cBodyState;
    
    if (m_cSeeState != NULL)
        delete m_cSeeState;
    
    if (m_cHearState != NULL)
        delete m_cHearState;

    //Delete all the PlayerStates
    for (std::vector<const PlayerState*>::iterator iter = m_vcPlayerStates.begin() ; iter != m_vcPlayerStates.end() ; iter++)
        delete *iter;
    
}

/****************************************************************************************************
 * function name: getLastSeeState                                                                   *
 * The Input: none                                                                                  *
 * The output: const SeeState object (pointer)                                                      *
 * The Function Opertion: Returns the appropriate pointer from the member variable.                 *
 * *************************************************************************************************/

SeeState* Player::getLastSeeState() {

    SeeState *cSeeState = NULL;
    
    //Lock to prevent multiple access
    m_cMutualExclusion.lock();

    if (m_cSeeState != NULL)
        cSeeState = new SeeState(*m_cSeeState);
    
    //Unlock to proceed
    m_cMutualExclusion.unlock();
    
    return cSeeState;
    
}

/****************************************************************************************************
 * function name: getLastHearState                                                                  *
 * The Input: none                                                                                  *
 * The output: const HearState object (pointer)                                                     *
 * The Function Opertion: Returns the appropriate pointer from the member variable.                 *
 * *************************************************************************************************/

HearState* Player::getLastHearState() {
    
    HearState *cHearState = NULL;
    
    //Lock to prevent multiple access
    m_cMutualExclusion.lock();
    
    if (m_cHearState != NULL)
        cHearState = new HearState(*m_cHearState);
    
    //Unlock to proceed
    m_cMutualExclusion.unlock();
    
    return cHearState;
    
}

/****************************************************************************************************
 * function name: getLastServerState                                                                *
 * The Input: none                                                                                  *
 * The output: const ServerState object (pointer)                                                   *
 * The Function Opertion: Returns the appropriate pointer from the member variable.                 *
 * *************************************************************************************************/

ServerState* Player::getLastServerState() {
    
    ServerState *cServerState = NULL;
    
    //Lock to prevent multiple access
    m_cMutualExclusion.lock();
    
    if (m_cServerState != NULL)
        cServerState = new ServerState(*m_cServerState);
    
    //Unlock to proceed
    m_cMutualExclusion.unlock();
    
    return cServerState;
    
}

/****************************************************************************************************
 * function name: getLastTeamState                                                                  *
 * The Input: none                                                                                  *
 * The output: const TeamState object (pointer)                                                     *
 * The Function Opertion: Returns the appropriate pointer from the member variable.                 *
 * *************************************************************************************************/

TeamState* Player::getLastTeamState() {
    
    TeamState *cTeamState = NULL;
    
    //Lock to prevent multiple access
    m_cMutualExclusion.lock();
    
    if (m_cTeamState != NULL)
        cTeamState = new TeamState(*m_cTeamState);
    
    //Unlock to proceed
    m_cMutualExclusion.unlock();
    
    return cTeamState;
    
}

/****************************************************************************************************
 * function name: getPlayerStates                                                                   *
 * The Input: none                                                                                  *
 * The output: const vector<PlayerState> object (reference)                                         *
 * The Function Opertion: Returns the appropriate member variable.                                  *
 * *************************************************************************************************/

std::vector<const PlayerState*>* Player::getPlayerStates() {
    
    std::vector<const PlayerState*>* vcPlayerStates = NULL;
    
    //Lock to prevent multiple access
    m_cMutualExclusion.lock();
    
    if (!m_vcPlayerStates.empty())
        vcPlayerStates = new std::vector<const PlayerState*>;

    for (std::vector<const PlayerState*>::const_iterator iter = m_vcPlayerStates.begin() ;
         iter != m_vcPlayerStates.end() ;
         iter++) {
        
        vcPlayerStates->push_back(new PlayerState(**iter));
        
    }
    
    //Unlock to proceed
    m_cMutualExclusion.unlock();
    
    return vcPlayerStates;
    
}

/****************************************************************************************************
 * function name: getLastBodyState                                                                  *
 * The Input: none                                                                                  *
 * The output: const BodyState object (pointer)                                                     *
 * The Function Opertion: Returns the appropriate pointer from the member variable.                 *
 * *************************************************************************************************/

BodyState* Player::getLastBodyState() {
    
    BodyState *cBodyState = NULL;
    
    //Lock to prevent multiple access
    m_cMutualExclusion.lock();
    
    if (m_cBodyState != NULL)
        cBodyState = new BodyState(*m_cBodyState);
    
    //Unlock to proceed
    m_cMutualExclusion.unlock();
    
    return cBodyState;
    
}

/**********************************************************************************************
 * function name: createPlayer                                                                *
 * The Input: PlayerType, const Connection object (pointer), const char (pointer), const      *
 *            Vector object (reference)                                                       *
 * The output: Player object (pointer)                                                        *
 * The Function Opertion: Returns a new player from the input parameters, that has the        *
 *                        client connection specified, with the team name and the starting    *
 *                        position.                                                           *
 * *******************************************************************************************/

Player* Player::createPlayer(PlayerType eType, const Connection* cConnection, const char* chTeamName){
    
    switch (eType) {
        case PlayerTypeGoalKeeper:
            
            //Create and return a GoalKeeper
            return new GoalKeeper(cConnection, chTeamName);
            break;
            
        case PlayerTypeDefender:
            
            //Create and return a Defender
            return new Defender(cConnection, chTeamName);
            break;

        case PlayerTypeMidFielder:
            
            //Create and return a Defender
            return new MidFielder(cConnection, chTeamName);
            break;
            
        case PlayerTypeForward:
            
            //Create and return a Defender
            return new Forward(cConnection, chTeamName);
            break;
            
        //Shouldnt reach here
        default:
            break;
            
    }
    
    
}
