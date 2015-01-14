//
//  PushTargetToStackNode.cpp
//  Ex3
//
//  Created by Maxim Vainshtein on 1/14/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "PushTargetToStackNode.h"

using namespace behavior;

PushTargetToStackNode::PushTargetToStackNode() {
    
}

PushTargetToStackNode::~PushTargetToStackNode() {
    
}

StatusType PushTargetToStackNode::process() {
    
    //Get the current target
    BehaviorTarget* cTarget = getContext().getCurrentTarget();
    
    //Push it to the stack
    getContext().getStack().push(cTarget);
    
    //All was OK
    return StatusTypeSuccess;
    
}