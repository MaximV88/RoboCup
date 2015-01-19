//
//  IsCloseToTargetNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/19/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "IsCloseToTargetNode.h"
#include "Player.h"
#define IS_CLOSE_TO_TARGET_NODE_TARGET_ERROR "IsCloseToTargetNode Error: No Target given"
#define IS_CLOSE_TO_TARGET_NODE_VALUE_ERROR "IsCloseToTargetNode Error: No Observable value given in the "

#define CLOSE_VALUE 1

using namespace behavior;

IsCloseToTargetNode::IsCloseToTargetNode() {
    
}

IsCloseToTargetNode::~IsCloseToTargetNode() {
    
}

StatusType IsCloseToTargetNode::process() {
    
    //Add the required input from the target
    BehaviorTarget *cTarget = getContext().getCurrentTarget();
    
    //If no target is present, return failed
    if (cTarget == NULL) {
        
#if DEBUG_PRINT_ERRORS
        
        std::cerr << IS_CLOSE_TO_TARGET_NODE_TARGET_ERROR << std::endl;
        
#endif
        
        return StatusTypeFailure;
        
    }
    
    //Check if our target has an origin to move to
    const Observable *cObservable = cTarget->getObservable();
    
    //If no coordinate is given, return failed
    if (cObservable == NULL) {
        
#if DEBUG_PRINT_ERRORS
        
        std::cerr << IS_CLOSE_TO_TARGET_NODE_VALUE_ERROR << *cTarget << std::endl;
        
#endif

        return StatusTypeFailure;
        
    }

    if (cObservable->distance < CLOSE_VALUE)
        return StatusTypeSuccess;

    //Havnt found it
    return StatusTypeFailure;
    
}
