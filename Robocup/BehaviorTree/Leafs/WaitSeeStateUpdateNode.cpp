//
//  WaitSeeStateUpdateNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/17/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "WaitSeeStateUpdateNode.h"
#include "Brain.h"

#define DEBUG_ACTION_DESCRIPTION "Waiting until next SeeState update."

using namespace behavior;

WaitSeeStateUpdateNode::WaitSeeStateUpdateNode() {
    
}

WaitSeeStateUpdateNode::~WaitSeeStateUpdateNode() {
    
}

StatusType WaitSeeStateUpdateNode::process() {
    
    //Print the action's description
    DebugLogVerbose(DEBUG_ACTION_DESCRIPTION);
    
    //Make the brain send the instructions gathered
    getContext().getBrain().waitSeeStateUpdate();
    
    return StatusTypeSuccess;
    
}
