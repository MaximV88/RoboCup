//
//  TurnNeckNegativeNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/15/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "TurnNeckNegativeNode.h"
#include "PushTargetToStackNode.h"
#include "SetTargetToNegativeNeckTurnAngleNode.h"
#include "TurnNeckNode.h"
#include "SenseBodyNode.h"
#include "PopFromStackNode.h"
#include "EndActNode.h"

using namespace behavior;

TurnNeckNegativeNode::TurnNeckNegativeNode() {
    
    //Push the current target to the stack
    addChild(new PushTargetToStackNode());
    
    //Set the value for neck rotation as target
    addChild(new SetTargetToNegativeNeckTurnAngleNode());
    
    //Perform the rotation
    addChild(new TurnNeckNode());
    
    //Ask to update the body state
    addChild(new SenseBodyNode());
    
    //Pop the original target back
    addChild(new PopFromStackNode());
    
    //Update variables and body state
    addChild(new EndActNode());
    
}

TurnNeckNegativeNode::~TurnNeckNegativeNode() {
    
}
