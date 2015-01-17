//
//  IsTargetPlayerNode.cpp
//  Ex3
//
//  Created by Maxim Vainshtein on 1/14/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "IsTargetPlayerNode.h"

#define IS_TARGET_PLAYER_NODE_TARGET_ERROR "IsTargetPlayerNode Error: No Target given"
#define IS_TARGET_PLAYER_NODE_VALUE_ERROR "IsTargetPlayerNode Error: No Observable value given in the "

#define DEBUG_ACTION_DESCRIPTION "Checking if the Target is a Player."

using namespace behavior;

IsTargetPlayerNode::IsTargetPlayerNode() {
    
}

IsTargetPlayerNode::~IsTargetPlayerNode() {
    
}

StatusType IsTargetPlayerNode::process() {
    
    //Get the current target
    BehaviorTarget* cTarget = getContext().getCurrentTarget();
    
    if (cTarget == NULL) {
        
#if DEBUG_PRINT_ERRORS

        std::cerr << IS_TARGET_PLAYER_NODE_TARGET_ERROR << std::endl;

#endif
        
        return StatusTypeFailure;
        
    }
    
    const Observable* cObservable = cTarget->getObservable();

    //Check if we have something to check
    if (cObservable == NULL) {
        
#if DEBUG_PRINT_ERRORS

        std::cerr << IS_TARGET_PLAYER_NODE_VALUE_ERROR << *cTarget << std::endl;

#endif
        
        return StatusTypeFailure;
        
    }
    
#if DEBUG_PRINT_ACTION
    
    //Print the action's description
    std::cout << DEBUG_ACTION_DESCRIPTION << std::endl;
    
#endif
    
    //If the observable is not a player, then it is not an enemy (TODO: CHECK FOR GOALS?)
    if (cObservable->type != ObservableTypePlayer)
        return StatusTypeFailure;
        
    //All was OK
    return StatusTypeSuccess;
    
}