/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include "PushTargetToStackNode.h"

#define DEBUG_ACTION_DESCRIPTION_SUCCESS_1 "Successfuly pushed to Stack the "
#define DEBUG_ACTION_DESCRIPTION_SUCCESS_2 " Clearing the Target."
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
        
        //Print the action's description
        DebugLogVerbose(DEBUG_ACTION_DESCRIPTION_SUCCESS_1 << *cTarget <<
                        DEBUG_ACTION_DESCRIPTION_SUCCESS_2);
        
        //Clear the current target once pointer is saved
        getContext().setCurrentTarget(NULL);
        
        //All was OK
        return StatusTypeSuccess;
    }
    else {
        
        //Print the action's description
        DebugLogError(DEBUG_ACTION_DESCRIPTION_FAILURE);
        
        //Operation was not successful
        return StatusTypeFailure;
        
    }
    
}