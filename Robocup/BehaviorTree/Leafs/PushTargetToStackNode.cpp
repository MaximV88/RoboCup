//
//  PushTargetToStackNode.cpp
//  Ex3
//
//  Created by Maxim Vainshtein on 1/14/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "PushTargetToStackNode.h"

#define DEBUG_ACTION_DESCRIPTION_SUCCESS_1 "Successfuly pushed to Stack the "
#define DEBUG_ACTION_DESCRIPTION_SUCCESS_2 " clearing the Target."
#define DEBUG_ACTION_DESCRIPTION_FAILURE "Could not push Target to Stack, no Target found"

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
        
#if DEBUG_PRINT_ACTION
        
        //Print the action's description
        std::cout << DEBUG_ACTION_DESCRIPTION_SUCCESS_1 << *cTarget <<
        DEBUG_ACTION_DESCRIPTION_SUCCESS_2 << std::endl;
        
#endif
        
        //Clear the current target once pointer is saved
        getContext().setCurrentTarget(NULL);
        
        //All was OK
        return StatusTypeSuccess;
    }
    else {
        
#if DEBUG_PRINT_ACTION
        
        //Print the action's description
        std::cout << DEBUG_ACTION_DESCRIPTION_FAILURE << std::endl;
        
#endif
        
        //Operation was not successful
        return StatusTypeFailure;
        
    }
    
}