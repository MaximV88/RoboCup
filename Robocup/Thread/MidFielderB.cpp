//
//  MidFielderB.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/29/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "MidFielderB.h"
#include "Behavior.h"

using namespace behavior;

void MidFielderB::actPlayMode(PlayMode ePlayMode) {
    
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

MidFielderB::MidFielderB(const Connection* cConnection, const char* chTeamName) :
Player(cConnection, chTeamName, false) {
    
    
    //      ---     MOVE TO POSITION      ---     //
    
    BehaviorTree *cMove = new BehaviorTree(*this, getBrain(), "MoveToPosition");
    
    SequenceNode *cMoveStart = new SequenceNode();
    cMoveStart->addChild(new SetTargetToNode(new BehaviorTarget(Coordinate(-20, -15), "MidFielder")));
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
    cGoStart->addChild(new IsCloseToTargetNode(40));
    cGoStart->addChild(new DashTowardsTargetUntilDistanceNode(40));
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

MidFielderB::~MidFielderB() {
    
}
