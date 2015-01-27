//
//  PopFromStackNode.cpp
//  Ex3
//
//  Created by Maxim Vainshtein on 1/14/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "PopFromStackNode.h"

#define DEBUG_ACTION_DESCRIPTION_SUCCESS "Successfuly popped the Stack and set the Target to "
#define DEBUG_ACTION_DESCRIPTION_FAILURE "Could not pop the Stack, clearing the Target."

using namespace behavior;

PopFromStackNode::PopFromStackNode() {
    
}

PopFromStackNode::~PopFromStackNode() {
    
}

StatusType PopFromStackNode::process() {
    
    //Save the reference of the stack to a local variable
    std::stack<BehaviorTarget*>& cStack = getContext().getStack();
    
    //No target to aquire - clear the target in this case
    if (cStack.empty()) {

        //Print the action's description
        DebugLogVerbose(DEBUG_ACTION_DESCRIPTION_FAILURE);
        
        getContext().setCurrentTarget(NULL);
        
        //An error has been encountered
        return StatusTypeFailure;
        
    }
    else {
        
        //Take an object from the stack and make it the target
        BehaviorTarget *cTarget = cStack.top();
        
        //Pop the object from the stack
        cStack.pop();
        
        //Print the action's description
        DebugLogVerbose(DEBUG_ACTION_DESCRIPTION_SUCCESS  << *cTarget);
        
        //Make it the context's target
        getContext().setCurrentTarget(cTarget);
        
        //All was OK
        return StatusTypeSuccess;
        
    }
    
}
