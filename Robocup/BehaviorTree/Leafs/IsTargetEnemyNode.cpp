//
//  IsTargetEnemyNode.cpp
//  Ex3
//
//  Created by Maxim Vainshtein on 1/14/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "IsTargetEnemyNode.h"

#define IS_TARGET_ENEMY_NODE_TARGET_ERROR "IsTargetEnemyNode Error: No Target given"
#define IS_TARGET_ENEMY_NODE_VALUE_ERROR "IsTargetEnemyNode Error: No Observable value given in the "

#define DEBUG_ACTION_DESCRIPTION "Checking if the Target is an Enemy."

using namespace behavior;

IsTargetEnemyNode::IsTargetEnemyNode() {
    
}

IsTargetEnemyNode::~IsTargetEnemyNode() {
    
}

StatusType IsTargetEnemyNode::process() {
    
    //Get the current target
    BehaviorTarget* cTarget = getContext().getCurrentTarget();
    
    if (cTarget == NULL) {
        
        //Print error and return
        DebugLogError(IS_TARGET_ENEMY_NODE_TARGET_ERROR);
        return StatusTypeFailure;
        
    }
    
    //Check if its a player
    const Observable* cObservable = cTarget->getObservable();
    
    //If its not observable, then it is surely not an enemy
    if (cObservable == NULL) {
        
        //Print error and return
        DebugLogError(IS_TARGET_ENEMY_NODE_VALUE_ERROR << *cTarget);
        return StatusTypeFailure;
        
    }
    

    //Print the action's description
    DebugLogVerbose(DEBUG_ACTION_DESCRIPTION);
    
    //If the observable is not a player, then it is not an enemy (TODO: CHECK FOR GOALS?)
    if (cObservable->type != ObservableTypePlayer)
        return StatusTypeFailure;
    
    //COMPLETE PROCEDURE
    
    //All was OK
    return StatusTypeSuccess;
    
}