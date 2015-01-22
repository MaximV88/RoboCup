//
//  IsTurnedOnTargetNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/21/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "IsTurnedOnTargetNode.h"
#include "Player.h"

#define IS_TURNED_ON_TARGET_NODE_TARGET_ERROR "IsTurnedOnTargetNode Error: No Target given"
#define IS_TURNED_ON_TARGET_NODE_VALUE_ERROR "IsTurnedOnTargetNode Error: No Observable value given in the "

#define CLOSE_VALUE 5

using namespace behavior;

IsTurnedOnTargetNode::IsTurnedOnTargetNode() {
    
}

IsTurnedOnTargetNode::~IsTurnedOnTargetNode() {
    
}

StatusType IsTurnedOnTargetNode::process() {
    
    //Add the required input from the target
    BehaviorTarget *cTarget = getContext().getCurrentTarget();
    
    //If no target is present, return failed
    if (cTarget == NULL) {
        
#if DEBUG_PRINT_ERRORS
        
        std::cerr << IS_TURNED_ON_TARGET_NODE_TARGET_ERROR << std::endl;
        
#endif
        
        return StatusTypeFailure;
        
    }
    
    //Check if our target has an origin to move to
    const Observable *cObservable = cTarget->getObservable();
    
    //If no coordinate is given, return failed
    if (cObservable == NULL) {
        
#if DEBUG_PRINT_ERRORS
        
        std::cerr << IS_TURNED_ON_TARGET_NODE_VALUE_ERROR << *cTarget << std::endl;
        
#endif
        
        return StatusTypeFailure;
        
    }
    
    SeeState *cState = getContext().getPlayer().getLastSeeState();
    
    for (std::vector<Observable*>::const_iterator iter = cState->getObservables().begin();
         iter != cState->getObservables().end();
         iter++) {
        
        //Need to adjust it to players
        if ((*iter)->type == cObservable->type) {
            
            //Update the held target
            cTarget->setObservable(**iter);
        
            //Check too see that the angle is less than limit
            if (abs((*iter)->direction) < CLOSE_VALUE) {
                
                //Remove the copy
                delete cState;
                
                return StatusTypeSuccess;
                
            }
            else {
                
                //Remove the copy
                delete cState;
                
                return StatusTypeFailure;
                
            }
            
        }
        
        
    }
    
    //Havnt found it
    return StatusTypeFailure;
    
}
