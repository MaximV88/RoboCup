//
//  DashTowardsBallNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/19/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "DashTowardsBallNode.h"
#include "TurnTowardsTypeNode.h"
#include "PushTargetToStackNode.h"
#include "PopFromStackNode.h"
#include "SetTargetToNode.h"
#include "RepeatUntilFailNode.h"
#include "DashNode.h"
#include "EndActNode.h"
#include "SuccessNode.h"
#include "IsCloseToTargetNode.h"
#include "IsTargetVisibleNode.h"
#include "SuccessNode.h"
#include "InverterNode.h"
#include "WaitSeeStateUpdateNode.h"

#define NODE_NAME "DashTowardsBallNode"

using namespace behavior;

DashTowardsBallNode::DashTowardsBallNode() {
    
    //Push the current target
    addChild(new SuccessNode(new PushTargetToStackNode()));
    
    //Set the target as the Ball
    addChild(new SetTargetToNode(new BehaviorTarget(ObservableTypeBall, NODE_NAME)));
    
    //Turn the body towards the ball
    addChild(new TurnTowardsTypeNode());
    
    
    SequenceNode *cSequence = new SequenceNode();
    
    cSequence->addChild(new SuccessNode(new PushTargetToStackNode()));
    cSequence->addChild(new SetTargetToNode(new BehaviorTarget(int(100), NODE_NAME)));
    cSequence->addChild(new DashNode());
    cSequence->addChild(new SuccessNode(new PopFromStackNode()));
    cSequence->addChild(new WaitSeeStateUpdateNode());
    cSequence->addChild(new EndActNode());
    cSequence->addChild(new IsTargetVisibleNode());
    cSequence->addChild(new InverterNode(new IsCloseToTargetNode(1)));
    
    addChild(new InverterNode(new RepeatUntilFailNode(cSequence)));
    
    addChild(new SuccessNode(new PopFromStackNode()));

    
}

DashTowardsBallNode::~DashTowardsBallNode() {
    
}
