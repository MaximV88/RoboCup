/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include "MidFielderA.h"
#include "Behavior.h"

using namespace behavior;

void MidFielderA::actPlayMode(PlayMode ePlayMode) {
    
    //Decide which Behavior to perform based on the PlayMode
    switch (ePlayMode) {
        case PlayModePlayOn:
            getBrain().setBehavior("GoToPosition");
            break;
            
        case PlayModeBeforeKickOff:
            getBrain().setBehavior("MoveToPosition");
            break;
            
        default:
            getBrain().setBehavior("GoToPosition");
            break;
            
    }
    
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: MidFielder Constructor                                                        *
 * The Input: const Connection object (pointer), const char (pointer), const Vector (reference) *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the base class.                                           *
 * *********************************************************************************************/

MidFielderA::MidFielderA(const Connection* cConnection, const char* chTeamName) :
Player(cConnection, chTeamName, false) {
    
    
    //      ---     MOVE TO POSITION      ---     //
    
    BehaviorTree *cMove = new BehaviorTree(*this, getBrain(), "MoveToPosition");
    
    SequenceNode *cMoveStart = new SequenceNode();
    cMoveStart->addChild(new SetTargetToNode(new BehaviorTarget(Coordinate(-10, -25), "MidFielder")));
    cMoveStart->addChild(new MoveNode());
    cMoveStart->addChild(new SetTargetToNode(new BehaviorTarget(ObservableTypeBall, "MidFielder")));
    cMoveStart->addChild(new TurnTowardsTypeNode());
    cMoveStart->addChild(new EndActNode());
    
    cMove->setRoot(cMoveStart);
    
    //      ---     GO TO POSITION      ---     //
    
    BehaviorTree *cGo = new BehaviorTree(*this, getBrain(), "GoToPosition");
    
    SequenceNode *cGoStart = new SequenceNode();
    cGoStart->addChild(new SetTargetToNode(new BehaviorTarget(ObservableTypeFlagCenter, "MidFielder")));
    cGoStart->addChild(new DashTowardsTargetNode(20));
    cGoStart->addChild(new SetTargetToNode(new BehaviorTarget(ObservableTypeBall, "MidFielder")));
    cGoStart->addChild(new TurnTowardsTypeNode());
    cGoStart->addChild(new IsCloseToTargetNode(30));
    cGoStart->addChild(new DashTowardsTargetUntilDistanceNode(30));
    cGoStart->addChild(new SetTargetToOpponentGoalNode());
    cGoStart->addChild(new TurnTowardsTypeNode());
    cGoStart->addChild(new KickBallNode());
    cGoStart->addChild(new EndActNode());
    
    cGo->setRoot(cGoStart);
    
    getBrain().addBehavior(*cMove);
    getBrain().addBehavior(*cGo);
    
}

/**********************************************************************************************
 * function name: MidFielder Destructor                                                       *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Nothing.                                                            *
 * *******************************************************************************************/

MidFielderA::~MidFielderA() {
    
}
