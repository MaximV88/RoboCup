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
    
#if DEBUG_PRINT_ACTION
    
    //Print the action's description
    std::cout << DEBUG_ACTION_DESCRIPTION << std::endl;
    
#endif
    
    //Make the brain send the instructions gathered
    getContext().getBrain().waitBodyStateUpdate();
    
    return StatusTypeSuccess;
    
}
