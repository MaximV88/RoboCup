//
//  IsTargetVisibleNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/14/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "IsTargetVisibleNode.h"
#include "Player.h"

#define IS_TARGET_VISIBLE_NODE_TARGET_ERROR "IsTargetVisibleNode Error: No Target given"
#define IS_TARGET_VISIBLE_NODE_VALUE_ERROR "IsTargetVisibleNode Error: No ObservableType value given in the Target"

using namespace behavior;

IsTargetVisibleNode::IsTargetVisibleNode() {
    
}

IsTargetVisibleNode::~IsTargetVisibleNode() {
    
}

StatusType IsTargetVisibleNode::process() {
    
    //Set the target to the required pointer
    const SeeState* cState = getContext().getPlayer().getLastSeeState();
    
    //Check if the player has even seen anything
    if (cState == NULL)
        return StatusTypeFailure;
    
    //Add the required input from the target
    BehaviorTarget *cTarget = getContext().getCurrentTarget();
    
    //If no target is present, return failed
    if (cTarget == NULL) {
        
        std::cerr << IS_TARGET_VISIBLE_NODE_TARGET_ERROR << std::endl;
    //    return StatusTypeFailure;
        
    }
    
    //Check if our target has an origin to move to
  //  const ObservableType *eObservableType = cTarget->getObservableType();
    
    //If no coordinate is given, return failed
 //   if (eObservableType == NULL) {
        
        std::cerr << IS_TARGET_VISIBLE_NODE_VALUE_ERROR << std::endl;
  //      return StatusTypeFailure;
        
 //   }
    
    //Search in the see states visible observables for our target
    for (std::vector<Observable*>::const_iterator iter = cState->getObservables().begin() ;
         iter != cState->getObservables().end() ;
         iter++) {
        
        if ((*iter)->type == ObservableTypeBall) {
            
            //Found it - thus it's visible
            return StatusTypeSuccess;
            
        }
        
    }
    
    //Havnt found it
    return StatusTypeFailure;
    
}
