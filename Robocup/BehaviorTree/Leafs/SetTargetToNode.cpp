//
//  SetTargetToNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/14/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "SetTargetToNode.h"

#define DEBUG_ACTION_DESCRIPTION_SUCCESS "Successfuly set the "
#define DEBUG_ACTION_DESCRIPTION_FAILURE "Could not set the Target, does not exist."

using namespace behavior;

SetTargetToNode::SetTargetToNode(BehaviorTarget* cTarget) :
m_cTarget(cTarget) {
    
}

SetTargetToNode::~SetTargetToNode() {
    
}

StatusType SetTargetToNode::process() {
    
    
    //Set the target to the required pointer only if exists
    if (m_cTarget != NULL)
        getContext().setCurrentTarget(new BehaviorTarget(*m_cTarget));
    else {
        
#if DEBUG_PRINT_ACTION
        
        //Print the action's description
        std::cout << DEBUG_ACTION_DESCRIPTION_FAILURE << std::endl;

#endif

        return StatusTypeFailure;

    }
    
#if DEBUG_PRINT_ACTION
    
    //Print the action's description
    std::cout << DEBUG_ACTION_DESCRIPTION_SUCCESS << *m_cTarget << std::endl;
    
#endif
    
    return StatusTypeSuccess;
    
}
