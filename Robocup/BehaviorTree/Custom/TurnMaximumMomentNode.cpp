//
//  TurnMaximumMomentNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/16/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "TurnMaximumMomentNode.h"
#include "SetTargetToMaximumMomentAngleNode.h"
#include "PushTargetToStackNode.h"
#include "PopFromStackNode.h"
#include "TurnNode.h"
#include "EndActNode.h"
#include "SuccessNode.h"

using namespace behavior;

TurnMaximumMomentNode::TurnMaximumMomentNode() {
    
    //Push the current target to the stack - dont care if there is a target
    addChild(new SuccessNode(new PushTargetToStackNode()));
    
    //Set the value for neck rotation as target
    addChild(new SetTargetToMaximumMomentAngleNode());
    
    //Perform the rotation
    addChild(new TurnNode());
    
    //Pop the original target back - dont care if there isnt a target
    addChild(new SuccessNode(new PopFromStackNode()));
    
    //Update variables and body state
    addChild(new EndActNode());
    
}

TurnMaximumMomentNode::~TurnMaximumMomentNode() {
    
}
