/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Implementation of Forward Class        *
 ***********************************************************/

#include <iostream>
#include "Striker.h"
#include "Behavior.h"


#define ROTATION_SEARCH_SPEED 20
#define LOCK_WIDTH 1
#define KICK_DISTANCE 1

using namespace std;
using namespace behavior;

void Striker::actPlayMode(PlayMode ePlayMode) {
        
    //Decide which Behavior to perform based on the PlayMode
    switch (ePlayMode) {
        case PlayModePlayOn:
            getBrain().setBehavior("Attack");
            break;
            
        default:
            getBrain().setBehavior("MoveToPosition");
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

Striker::Striker(const Connection* cConnection, const char* chTeamName) :
Player(cConnection, chTeamName, false) {
    
    //      ---     ATTACK      ---     //
    
    BehaviorTree *cAttack = new BehaviorTree(*this, getBrain(), "Attack");
    
    SequenceNode *cAttackStart = new SequenceNode();
    cAttackStart->addChild(new SetTargetToNode(new BehaviorTarget(ObservableTypeBall, "Striker")));
    cAttackStart->addChild(new RepeatUntilSuccessNode(new DashTowardsTargetNode(1)));
    cAttackStart->addChild(new SetTargetToOpponentGoalNode());
    cAttackStart->addChild(new SearchNode());
    cAttackStart->addChild(new KickBallNode());
    cAttackStart->addChild(new EndActNode());
    
    cAttack->setRoot(cAttackStart);
    
    
    //      ---     MOVE TO POSITION      ---     //
    
    BehaviorTree *cMove = new BehaviorTree(*this, getBrain(), "MoveToPosition");

    SequenceNode *cMoveStart = new SequenceNode();
    cMoveStart->addChild(new SetTargetToNode(new BehaviorTarget(Coordinate(-5, 5), "Striker")));
    cMoveStart->addChild(new MoveNode());
    cMoveStart->addChild(new SetTargetToNode(new BehaviorTarget(ObservableTypeBall, "Striker")));
    cMoveStart->addChild(new TurnTowardsTypeNode());
    
    cMove->setRoot(cMoveStart);
    
    
    getBrain().addBehavior(*cAttack);
    getBrain().addBehavior(*cMove);

}

/**********************************************************************************************
 * function name: Forward Destructor                                                          *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Nothing.                                                            *
 * *******************************************************************************************/

Striker::~Striker() {
    
}
