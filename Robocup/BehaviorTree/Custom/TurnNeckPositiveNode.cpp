//
//  TurnNeckPositiveNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/15/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "TurnNeckPositiveNode.h"
#include "PushTargetToStackNode.h"
#include "SetTargetToPositiveNeckTurnAngleNode.h"
#include "TurnNeckNode.h"
#include "SenseBodyNode.h"
#include "PopFromStackNode.h"
#include "EndActNode.h"

using namespace behavior;

TurnNeckPositiveNode::TurnNeckPositiveNode() {
    
    //Push the current target to the stack
    addChild(new PushTargetToStackNode());
    
    //Set the value for neck rotation as target
    addChild(new SetTargetToPositiveNeckTurnAngleNode());
    
    //Perform the rotation
    addChild(new TurnNeckNode());
    
    //Ask to update the body state
    addChild(new SenseBodyNode());
    
    //Pop the original target back
    addChild(new PopFromStackNode());
    
    //Update variables and body state
    addChild(new EndActNode());
    
}

TurnNeckPositiveNode::~TurnNeckPositiveNode() {
    
}
