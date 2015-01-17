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
        
#if DEBUG_PRINT_ACTION
        
        //Print the action's description
        std::cout << DEBUG_ACTION_DESCRIPTION_FAILURE << std::endl;
        
#endif
        
        getContext().setCurrentTarget(NULL);
        
        return StatusTypeFailure;
    
    }
    
    //Take an object from the stack and make it the target
    BehaviorTarget *cTarget = cStack.top();
    
    //Pop the object from the stack
    cStack.pop();
    
#if DEBUG_PRINT_ACTION
    
    //Print the action's description
    std::cout << DEBUG_ACTION_DESCRIPTION_SUCCESS  << *cTarget << std::endl;
    
#endif
    
    //Make it the context's target
    getContext().setCurrentTarget(cTarget);
    
    //All was OK
    return StatusTypeSuccess;
    
}
