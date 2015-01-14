/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Declaration of Player Class            *
 ***********************************************************/

#ifndef __Ex3__Player__
#define __Ex3__Player__

#include <stdio.h>
#include "Threadable.h"
#include "ThreadQueue.h"
#include "Vector.h"
#include "Coordinate.h"
#include "ConnectionHandler.h"
#include "Instruction.h"
#include "ServerState.h"
#include "PlayerState.h"
#include "TeamState.h"
#include "HearState.h"
#include "SeeState.h"
#include "Brain.h"

typedef enum {
    PlayerTypeGoalKeeper,
    PlayerTypeDefender,
    PlayerTypeMidFielder,
    PlayerTypeForward
} PlayerType;

class Brain;

/**********************************************************************************
 * Player Class: Represents the player. Recives states (parsed server information)*
 *               from the State queue and acts according to it, sending it's      *
 *               commands via the instructions queue.                             *
 *********************************************************************************/

class Player : public Threadable {
    
    friend class Brain;
    
private:
    
    //  ---                         PRIVATE VARIABLES                       ---   //

    
    //The queue is shared by all the players, thus can have several threads accessing it at once so its needs to be safe
    ThreadQueue<std::string*> m_qInstructionQueue;
    
    //Holds the States recieved from the ConnectionHandler (created by the Parser in that class)
    ThreadQueue<State*> m_qStateQueue;
    
    //The ConnectionHandler that handles the connection with the server
    ConnectionHandler m_cConnectionHandler;
    
    //Holds the last recieved BodyState from the State queue
    BodyState* m_cBodyState;
    
    //Holds the last recieved TeamState from the State queue
    TeamState* m_cTeamState;
    
    //Holds the last recieved ServerState from the State queue
    ServerState* m_cServerState;
    
    //Holds all of the recieved PlayerState from the State queue
    std::vector<const PlayerState*> m_vcPlayerStates;
    
    //Holds the last recieved HearState from the State queue
    HearState* m_cHearState;
    
    //Holds the last recieved SeeState from the State queue
    SeeState* m_cSeeState;
    
    //Holds the player's location
    Coordinate* m_cPlayerOrigin;
    
    //Holds the player's brain
    Brain m_cBrain;
    
    
    //  ---                         PRIVATE FUNCTIONS                       ---   //
    
    
    /****************************************************************************************************
     * function name: convertDirectionVector                                                            *
     * The Input: const Vector object (reference)                                                       *
     * The output: double                                                                               *
     * The Function Opertion: Returns the server result of confomed Vector                              *
     * *************************************************************************************************/
    
    double convertDirectionVector(const Vector& cDirection) const;
    
    void updateOrigin(const SeeState& cSeeState);

    /****************************************************************************************************
     * function name: execute                                                                           *
     * The Input: none                                                                                  *
     * The output: none                                                                                 *
     * The Function Opertion: Executes the operations required from this class (it's the 'main' thread  *
     *                        of this object), in a loop.                                               *
     * *************************************************************************************************/
    
    virtual void execute();
    
protected:
    
    /****************************************************************************************************
     * function name: getBrain                                                                          *
     * The Input: none                                                                                  *
     * The output: Brain object (reference)                                                             *
     * The Function Opertion: Returns the player's brain.                                               *
     * *************************************************************************************************/
    
    Brain& getBrain();
    
    virtual void actTeamState(const TeamState& cTeamState) = 0;
    
public:
    
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: Player Constructor                                                            *
     * The Input: const Connection object (pointer), const char (pointer), const Vector (reference) *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input client connection and position.     *
     * *********************************************************************************************/
    
    Player(const Connection* cConnection, const char* chTeamName);
    
    /**********************************************************************************************
     * function name: Player Destructor                                                           *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    virtual ~Player();
    
    /****************************************************************************************************
     * function name: getLastSeeState                                                                   *
     * The Input: none                                                                                  *
     * The output: const SeeState object (pointer)                                                      *
     * The Function Opertion: Returns the last recieved SeeState (may return NULL).                     *
     * *************************************************************************************************/
    
    const SeeState* getLastSeeState() const;
    
    /****************************************************************************************************
     * function name: getLastHearState                                                                  *
     * The Input: none                                                                                  *
     * The output: const HearState object (pointer)                                                     *
     * The Function Opertion: Returns the last recieved HearState (may return NULL).                    *
     * *************************************************************************************************/
    
    const HearState* getLastHearState() const;
    
    /****************************************************************************************************
     * function name: getLastServerState                                                                *
     * The Input: none                                                                                  *
     * The output: const ServerState object (pointer)                                                   *
     * The Function Opertion: Returns the last recieved ServerState (may return NULL).                  *
     * *************************************************************************************************/
    
    const ServerState* getLastServerState() const;
    
    /****************************************************************************************************
     * function name: getLastTeamState                                                                  *
     * The Input: none                                                                                  *
     * The output: const TeamState object (pointer)                                                     *
     * The Function Opertion: Returns the last recieved TeamState (may return NULL).                    *
     * *************************************************************************************************/
    
    const TeamState* getLastTeamState() const;
    
    /****************************************************************************************************
     * function name: getPlayerStates                                                                   *
     * The Input: none                                                                                  *
     * The output: const vector<PlayerState> object (reference)                                         *
     * The Function Opertion: Returns all of the recieved PlayerStates.                                 *
     * *************************************************************************************************/
    
    const std::vector<const PlayerState*>& getPlayerStates() const;
    
    /****************************************************************************************************
     * function name: getLastBodyState                                                                  *
     * The Input: none                                                                                  *
     * The output: const BodyState object (pointer)                                                     *
     * The Function Opertion: Returns the last recieved BodyState (may return NULL).                    *
     * *************************************************************************************************/
    
    const BodyState* getLastBodyState() const;
    
    /****************************************************************************************************
     * function name: getLastOrigin                                                                     *
     * The Input: none                                                                                  *
     * The output: const Coordinate object (pointer)                                                    *
     * The Function Opertion: Returns the last known origin (may return NULL).                          *
     * *************************************************************************************************/
    
    const Coordinate* getLastOrigin() const;

    /**********************************************************************************************
     * function name: createPlayer                                                                *
     * The Input: PlayerType, const Connection object (pointer), const char (pointer), const      *
     *            Vector object (reference)                                                       *
     * The output: Player object (pointer)                                                        *
     * The Function Opertion: Returns a new player from the input parameters, that has the        *
     *                        client connection specified, with the team name and the starting    *
     *                        position.                                                           *
     * *******************************************************************************************/
    
    static Player* createPlayer(PlayerType eType, const Connection* cConnection, const char* chTeamName);

};

#endif 
