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
    
    SeeState *cCState = getContext().getPlayer().getLastSeeState();
    BodyState *cBState = getContext().getPlayer().getLastBodyState();
    
    for (std::vector<Observable*>::const_iterator iter = cCState->getObservables().begin();
         iter != cCState->getObservables().end();
         iter++) {
        
        //Need to adjust it to players
        if ((*iter)->type == cObservable->type) {
            
            Observable* cAdjusted = *iter;
            
            cAdjusted->direction += cBState->headAngle;
        
            //Update the held target
            cTarget->setObservable(*cAdjusted);
        
            //Check too see that the angle is less than limit
            if (abs((*iter)->direction) <= CLOSE_VALUE) {
                
                //Remove the copy
                delete cCState;
                delete cBState;
                
                return StatusTypeSuccess;
                
            }
            else {
                
                //Remove the copy
                delete cCState;
                delete cBState;

                return StatusTypeFailure;
                
            }
            
        }
        
        
    }
    
    //Remove the copy
    delete cCState;
    delete cBState;

    //Havnt found it
    return StatusTypeFailure;
    
}
