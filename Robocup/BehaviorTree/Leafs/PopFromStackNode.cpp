//
//  PopFromStackNode.cpp
//  Ex3
//
//  Created by Maxim Vainshtein on 1/14/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "PopFromStackNode.h"

using namespace behavior;

PopFromStackNode::PopFromStackNode() {
    
}

PopFromStackNode::~PopFromStackNode() {
    
}

StatusType PopFromStackNode::process() {
    
    //Save the reference of the stack to a local variable
    std::stack<BehaviorTarget*>& cStack = getContext().getStack();
    
    //No target to aquire
    if (cStack.empty())
        return StatusTypeFailure;
    
    //Take an object from the stack and make it the target
    BehaviorTarget *cTarget = cStack.top();
    
    //Pop the object from the stack
    cStack.pop();
    
    //Make it the context's target
    getContext().setCurrentTarget(cTarget);
    
    //All was OK
    return StatusTypeSuccess;
    
}
