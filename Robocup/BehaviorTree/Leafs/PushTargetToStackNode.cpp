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
    
    //Validate that the current target exists
    if (getContext().getCurrentTarget() != NULL) {
        
        //Get the current target copy
        BehaviorTarget* cTarget = new BehaviorTarget(*getContext().getCurrentTarget());
        
        //Push it to the stack
        getContext().getStack().push(cTarget);
        
        //Clear the current target once pointer is saved
        getContext().setCurrentTarget(NULL);
        
        //All was OK
        return StatusTypeSuccess;
    }
    else {
        
        //Operation was not successful
        return StatusTypeFailure;
        
    }
    
}