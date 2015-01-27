//
//  ClearStackNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/16/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "ClearStackNode.h"

#define DEBUG_ACTION_DESCRIPTION_1 "Clearing the Stack. Currently contains "
#define DEBUG_ACTION_DESCRIPTION_2 " members"

using namespace behavior;

ClearStackNode::ClearStackNode() {
    
}

ClearStackNode::~ClearStackNode() {
    
}

StatusType ClearStackNode::process() {
    
    std::stack<BehaviorTarget*>& cStack = getContext().getStack();

    //Print the action's description
    DebugLogVerbose(DEBUG_ACTION_DESCRIPTION_1 << cStack.size() <<
                    DEBUG_ACTION_DESCRIPTION_2);
    
    //Erase the object held in the stack
    while (!cStack.empty()) {
        
        //Delete the object
        delete cStack.top();
        
        //Pop the stack
        cStack.pop();
        
    }
    
    //All was OK
    return StatusTypeSuccess;
    
}
