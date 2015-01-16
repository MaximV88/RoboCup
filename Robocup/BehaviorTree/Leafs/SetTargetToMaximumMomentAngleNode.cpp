//
//  SetTargetToMaximumMomentAngleNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/16/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "SetTargetToMaximumMomentAngleNode.h"
#include "Player.h"

using namespace behavior;

SetTargetToMaximumMomentAngleNode::SetTargetToMaximumMomentAngleNode() {
    
}

SetTargetToMaximumMomentAngleNode::~SetTargetToMaximumMomentAngleNode() {
    
}

StatusType SetTargetToMaximumMomentAngleNode::process() {
    
    //Check if valid for calculation
    if (getContext().getPlayer().getLastServerState() == NULL)
        return StatusTypeFailure;
    
    
    double dMaxMomentAngle = getContext().getPlayer().getLastServerState()->maxMoment;
    
    //Set the rotation as the target
    getContext().setCurrentTarget(new BehaviorTarget(dMaxMomentAngle));
    
    //All is OK
    return StatusTypeSuccess;
    
}
