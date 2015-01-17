//
//  ExecuteActNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/15/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "ExecuteActNode.h"
#include "Brain.h"

#define DEBUG_ACTION_DESCRIPTION "Executing the current Act."

using namespace behavior;

ExecuteActNode::ExecuteActNode() {
    
}

ExecuteActNode::~ExecuteActNode() {
    
}

StatusType ExecuteActNode::process() {
    
    /*
     * Make the brain send the instructions gathered, 
     * but dont wait if there are none.
     */
    
#if DEBUG_PRINT_ACTION
    
    //Print the action's description
    std::cout << DEBUG_ACTION_DESCRIPTION << std::endl;
    
#endif
    
    getContext().getBrain().executeAct();
    
    return StatusTypeSuccess;
    
}
