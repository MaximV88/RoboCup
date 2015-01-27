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
    
    //Print the action's description
    DebugLogVerbose(DEBUG_ACTION_DESCRIPTION);
    
    getContext().getBrain().executeAct();
    
    return StatusTypeSuccess;
    
}
