/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Implementation of Forward Class        *
 ***********************************************************/

#include <iostream>
#include "Forward.h"
#include "Behavior.h"


#define ROTATION_SEARCH_SPEED 20
#define LOCK_WIDTH 1
#define KICK_DISTANCE 1

using namespace std;
using namespace behavior;

//  ---                         PRIVATE FUNCTIONS                       ---   //


/****************************************************************************************************
 * function name: actSight                                                                          *
 * The Input: const SeeState object (reference)                                                     *
 * The output: none                                                                                 *
 * The Function Opertion: Checks if the mode is valid for play, then iterates over all of the       *
 *                        observed objects, and once a ball is found, calls the approachBall func,  *
 *                        otherwise calls the searchForBall function.                               *
 * *************************************************************************************************/
/*
void Forward::act() {
    
    switch (getLastTeamState()->playMode) {
        case PlayModePlayOn:
            m_bCanPlay = true;
            break;
        default:
            m_bCanPlay = false;
            break;
    }
    
    
    if (m_bCanPlay) {
        
        bool bFoundBall = false;
        
        //iterate over all the objects until one can be found
        for (vector<Observable*>::const_iterator iter = cSeeState.getObservables().begin() ;
             iter != cSeeState.getObservables().end() ;
             iter++) {
            
            //Find the ball
            if ((*iter)->type == ObservableTypeBall) {
                
                changeView(WidthTypeNarrow, QualityTypeHigh);
                approachBall(**iter);
                bFoundBall = true;
                
            }
            
            
        }
        
        if (!bFoundBall && !m_bSearchingGoal) {
            
            changeView(WidthTypeWide, QualityTypeLow);
            searchForBall(cSeeState.getObservables());
            
        }
        
    }
    
    
}
*/
/****************************************************************************************************
 * function name: actHearing                                                                        *
 * The Input: const HearState object (reference)                                                    *
 * The output: none                                                                                 *
 * The Function Opertion: Nothing.                                                                  *
 * *************************************************************************************************/
/*
void Forward::actHearing(const HearState& cHearState) {
    
}
*/
/****************************************************************************************************
 * function name: actTeam                                                                           *
 * The Input: const TeamState object (reference)                                                    *
 * The output: none                                                                                 *
 * The Function Opertion: Checks if the mode is playon, if yes then the play flag is true,          *
 *                        false otherwise.                                                          *
 * *************************************************************************************************/
/*
void Forward::actTeam(const TeamState& cTeamState) {
    
}
*/
/****************************************************************************************************
 * function name: actSensing                                                                        *
 * The Input: const BodyState object (reference)                                                    *
 * The output: none                                                                                 *
 * The Function Opertion: Nothing.                                                                  *
 * *************************************************************************************************/
/*
void Forward::actSensing(const BodyState& cBodyState) {
    
}
*/
/****************************************************************************************************
 * function name: searchForBall                                                                     *
 * The Input: const vector<Observable> object (reference)                                           *
 * The output: none                                                                                 *
 * The Function Opertion: Checks the last rotation direction, and continues to rotate in that       *
 *                        direction but in a specified speed.                                       *
 * *************************************************************************************************/
/*
void Forward::searchForBall(const vector<Observable*>& vcObservable) {
    
    //Make a rotation until found
    double dTurn = (m_bPositiveTurn) ? ROTATION_SEARCH_SPEED : -1 * ROTATION_SEARCH_SPEED;
    turn(dTurn);
    
}
*/
/****************************************************************************************************
 * function name: approachBall                                                                      *
 * The Input: const Observable object (reference)                                                   *
 * The output: none                                                                                 *
 * The Function Opertion: Turns towards the input observable object. Once locked in, checks the     *
 *                        distance. If the distance is lower than a constant, it kicks it in the    *
 *                        direction of the goal, otherwise it dashes towards it.                    *
 * *************************************************************************************************/
/*
void Forward::approachBall(const Observable& cObservable) {
    
    double dDirection = cObservable.direction;
    
    if (!m_bSearchingGoal && (dDirection > LOCK_WIDTH || dDirection < -1 * LOCK_WIDTH)) {
        
        turn(dDirection/2);
        
        if (dDirection > 0)
            m_bPositiveTurn = true;
        else
            m_bPositiveTurn = false;
        
    }
    else if (cObservable.distance < KICK_DISTANCE) {
        
        m_bSearchingGoal = true;
        
        //If close enough to the ball, find the goal
        if (findGoal()) {
            kickBall(getLastServerState()->maxPower, m_dGoalDirection);
            m_bSearchingGoal = false;
            m_bFoundGoal = false;
        }
        
    }
    else {
                
        dash(getLastServerState()->maxDashPower);
        m_bFoundGoal = false;
        m_bSearchingGoal = false;
        
    }
    
}
*/
/****************************************************************************************************
 * function name: findGoal                                                                          *
 * The Input: none                                                                                  *
 * The output: bool                                                                                 *
 * The Function Opertion: Iterates over all of the observed objects and tries to find the           *
 *                        target goal. If true, saves it's direction and returns true, otherwise    *
 *                        it rotates by a constant and returns false.                               *
 * *************************************************************************************************/
/*
bool Forward::findGoal() {
    
    if (!m_bFoundGoal) {
        
        //Change and try to find the goal
        changeView(WidthTypeWide, QualityTypeLow);
        
        const SeeState *cSeeState = getLastSeeState();
        
        ObservableType eGoalToFind;
        
        //Check which goal is ours
        if (getLastTeamState()->teamSide == TeamSideLeft)
            eGoalToFind = ObservableTypeGoalRight;
        else
            eGoalToFind = ObservableTypeGoalLeft;
        
        for (vector<Observable*>::const_iterator iter = cSeeState->getObservables().begin() ;
             iter != cSeeState->getObservables().end() ;
             iter++) {
            
            //Find the correct goal
            if ((*iter)->type == eGoalToFind) {
                
                //Found the goal
                m_bFoundGoal = true;
                m_dGoalDirection = (*iter)->direction;
                return true;
                
            }
            
        }
        
        
        turn(ROTATION_SEARCH_SPEED);
        return false;
    }
    
    return true;
    
        
    
}

*/

void Forward::actTeamState(const TeamState& cTeamState) {
    
    //Decide which Behavior to perform based on the PlayMode
    switch (cTeamState.playMode) {
        case PlayModePlayOn:
            getBrain().setBehavior("Attack");
            break;
            
        case PlayModeBeforeKickOff:
            
            getBrain().setBehavior("Attack");
            break;
            
        default:
            break;
            
    }
    
}


//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: Forward Constructor                                                           *
 * The Input: const Connection object (pointer), const char (pointer), const Vector (reference) *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the base class, and the member variables to default value.*
 * *********************************************************************************************/

Forward::Forward(const Connection* cConnection, const char* chTeamName) :
Player(cConnection, chTeamName) {
    
    //Create all behaviors and add them to the brain
    BehaviorTree *cTree = new BehaviorTree(*this, getBrain(), "Attack");
    
    SequenceNode *cs = new SequenceNode();
    cs->addChild(new SetTargetToNode(new BehaviorTarget(ObservableTypeBall, "lala")));
    cs->addChild(new SearchNode());
    cTree->setRoot(cs);
    
    getBrain().addBehavior(*cTree);
        
}

/**********************************************************************************************
 * function name: Forward Destructor                                                          *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Nothing.                                                            *
 * *******************************************************************************************/

Forward::~Forward() {
    
}
