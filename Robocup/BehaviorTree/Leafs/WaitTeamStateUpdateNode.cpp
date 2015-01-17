//
//  WaitTeamStateUpdateNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/17/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "WaitTeamStateUpdateNode.h"
#include "Brain.h"

#define DEBUG_ACTION_DESCRIPTION "Waiting until next TeamState update."

using namespace behavior;

WaitTeamStateUpdateNode::WaitTeamStateUpdateNode() {
    
}

WaitTeamStateUpdateNode::~WaitTeamStateUpdateNode() {
    
}

StatusType WaitTeamStateUpdateNode::process() {
    
#if DEBUG_PRINT_ACTION
    
    //Print the action's description
    std::cout << DEBUG_ACTION_DESCRIPTION << std::endl;
    
#endif
    
    //Make the brain send the instructions gathered
    getContext().getBrain().waitTeamStateUpdate();
    
    return StatusTypeSuccess;
    
}
