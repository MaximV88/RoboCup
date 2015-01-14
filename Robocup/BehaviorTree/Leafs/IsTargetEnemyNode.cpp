//
//  IsTargetEnemyNode.cpp
//  Ex3
//
//  Created by Maxim Vainshtein on 1/14/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "IsTargetEnemyNode.h"

using namespace behavior;

IsTargetEnemyNode::IsTargetEnemyNode() {
    
}

IsTargetEnemyNode::~IsTargetEnemyNode() {
    
}

StatusType IsTargetEnemyNode::process() {
    
    //Get the current target
    BehaviorTarget* cTarget = getContext().getCurrentTarget();
    
    //Check if its a player
    const Observable* cObservable = cTarget->getObservable();
    
    //If its not observable, then it is surely not an enemy
    if (cObservable == NULL)
        return StatusTypeFailure;
    
    //If the observable is not a player, then it is not an enemy (TODO: CHECK FOR GOALS?)
    if (cObservable->type != ObservableTypePlayer)
        return StatusTypeFailure;
    
    //COMPLETE PROCEDURE
    
    //All was OK
    return StatusTypeSuccess;
    
}