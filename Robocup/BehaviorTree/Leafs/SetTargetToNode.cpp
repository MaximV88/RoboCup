/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include "SetTargetToNode.h"

#define DEBUG_ACTION_DESCRIPTION_SUCCESS "Successfuly set as Target the "
#define DEBUG_ACTION_DESCRIPTION_FAILURE "Could not set the Target, does not exist."

using namespace behavior;

SetTargetToNode::SetTargetToNode(BehaviorTarget* cTarget) :
m_cTarget(cTarget) {
    
}

SetTargetToNode::~SetTargetToNode() {
    
}

StatusType SetTargetToNode::process() {
    
    
    //Set the target to the required pointer only if exists
    if (m_cTarget != NULL) {
        
        getContext().setCurrentTarget(new BehaviorTarget(*m_cTarget));
        
        
        //Print the action's description
        DebugLogVerbose(DEBUG_ACTION_DESCRIPTION_SUCCESS << *m_cTarget);

        return StatusTypeSuccess;
        
    }
    else {
        
        //Print the action's description
        DebugLogVerbose(DEBUG_ACTION_DESCRIPTION_FAILURE);
        
        return StatusTypeFailure;
        
    }
    
}
