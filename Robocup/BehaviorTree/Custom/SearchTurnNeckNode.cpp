//
//  SearchHeadTurnNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/14/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "SearchTurnNeckNode.h"
#include "IsTargetVisibleNode.h"
#include "TurnNeckNode.h"
#include "InverterNode.h"
#include "BehaviorContext.h"
#include "PushTargetToStackNode.h"
#include "SetTargetToNode.h"
#include "EndActNode.h"
#include "PopFromStackNode.h"
#include "Player.h"

using namespace behavior;

SearchTurnNeckNode::SearchTurnNeckNode() {
    
    
    /************************************************
     * Check if visibile on center, otherwise turn  *
     * to right, check again, and if not turn left. *
     ***********************************************/
    
    SequenceNode *cCheckingSequence = new SequenceNode();
    
    /*
     * If not visible, we need to continue the sequence,
     * thus we will use an Inverter.
     */
    
    addVisibilityCheck(cCheckingSequence);
    
    /*
     * If not found, the sequence continues and we need to turn the neck.
     * Save the target into the stack and set rotation value as target.
     * Afterwards, update and check again
     */
    
    double dRotation = getContext().getPlayer().getLastServerState()->maxNeckAngle;
    
    turnNeck(cCheckingSequence, dRotation);
    
    /*
     * At this section, we would have already turned the neck
     * to the maximum angle. We need to check again if the 
     * target is visible using an inverter just like before.
     */

    addVisibilityCheck(cCheckingSequence);

    
    
    
}

SearchTurnNeckNode::~SearchTurnNeckNode() {
    
}

void SearchTurnNeckNode::addVisibilityCheck(SequenceNode* cSequence) {

    //Inverts the result of the visibility check so that sequences can be continued
    InverterNode *cInvert = new InverterNode(new IsTargetVisibleNode());
    cSequence->addChild(cInvert);
    
}

void SearchTurnNeckNode::turnNeck(SequenceNode* cSequence, double dDirection) {
    
    
    //Push the current target to the stack
    cSequence->addChild(new PushTargetToStackNode());
    
    //Set the value for neck rotation as target
    cSequence->addChild(new SetTargetToNode(new BehaviorTarget(dDirection)));
    
    //Perform the rotation and update variables with EndAct
    cSequence->addChild(new TurnNeckNode());
    
    //Pop the original target back
    cSequence->addChild(new PopFromStackNode());
    
    //Update
    cSequence->addChild(new EndActNode());
    
}