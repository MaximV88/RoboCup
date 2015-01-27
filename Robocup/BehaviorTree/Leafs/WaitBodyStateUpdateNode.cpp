//
//  WaitBodyStateUpdateNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/17/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "WaitBodyStateUpdateNode.h"
#include "Brain.h"

#define DEBUG_ACTION_DESCRIPTION "Waiting until next BodyState update."

using namespace behavior;

WaitBodyStateUpdateNode::WaitBodyStateUpdateNode() {
    
}

WaitBodyStateUpdateNode::~WaitBodyStateUpdateNode() {
    
}

StatusType WaitBodyStateUpdateNode::process() {
    
    //Print the action's description
    DebugLogVerbose(DEBUG_ACTION_DESCRIPTION);
    
    //Make the brain send the instructions gathered
    getContext().getBrain().waitBodyStateUpdate();
    
    return StatusTypeSuccess;
    
}
