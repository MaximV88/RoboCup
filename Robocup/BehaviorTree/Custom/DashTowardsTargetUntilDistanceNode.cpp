//
//  DashTowardsTargetUntilDistanceNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/28/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "DashTowardsTargetUntilDistanceNode.h"
#include "TurnTowardsTypeNode.h"
#include "PushTargetToStackNode.h"
#include "PopFromStackNode.h"
#include "SetTargetToNode.h"
#include "RepeatUntilSuccessNode.h"
#include "RepeatUntilFailNode.h"
#include "DashNode.h"
#include "EndActNode.h"
#include "SuccessNode.h"
#include "FailureNode.h"
#include "IsCloseToTargetNode.h"
#include "IsTargetVisibleNode.h"
#include "SuccessNode.h"
#include "InverterNode.h"
#include "WaitSeeStateUpdateNode.h"

#define NODE_NAME "DashTowardsTargetNode"

using namespace behavior;

DashTowardsTargetUntilDistanceNode::DashTowardsTargetUntilDistanceNode(double dDistanceThreshold) {
    
    //Turn the body towards the ball
    addChild(new TurnTowardsTypeNode());
    
    //Dash towards the target
    SequenceNode *cSequence = new SequenceNode();
    cSequence->addChild(new IsTargetVisibleNode());
    cSequence->addChild(new IsCloseToTargetNode(dDistanceThreshold));
    cSequence->addChild(new DashNode());
    cSequence->addChild(new WaitSeeStateUpdateNode());
    cSequence->addChild(new EndActNode());
    cSequence->addChild(new IsTargetVisibleNode());
    cSequence->addChild(new InverterNode(new IsCloseToTargetNode(1)));
    
    addChild(new InverterNode(new RepeatUntilFailNode(cSequence)));
    
}

DashTowardsTargetUntilDistanceNode::~DashTowardsTargetUntilDistanceNode() {
    
}
