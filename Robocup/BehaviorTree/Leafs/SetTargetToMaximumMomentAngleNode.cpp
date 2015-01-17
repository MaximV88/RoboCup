//
//  SetTargetToMaximumMomentAngleNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/16/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "SetTargetToMaximumMomentAngleNode.h"
#include "Player.h"

#define NODE_NAME "SetTargetToMaximumMomentAngle"

#define DEBUG_ACTION_DESCRIPTION_SUCCESS_1 "Successfuly set rotation for Neck to center at "
#define DEBUG_ACTION_DESCRIPTION_SUCCESS_2 " degrees."

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
    getContext().setCurrentTarget(new BehaviorTarget(dMaxMomentAngle, NODE_NAME));
    
#if DEBUG_PRINT_ACTION
    
    //Print the action's description
    std::cout << DEBUG_ACTION_DESCRIPTION_SUCCESS_1 << dMaxMomentAngle <<
    DEBUG_ACTION_DESCRIPTION_SUCCESS_2 << std::endl;
    
#endif
    
    //All is OK
    return StatusTypeSuccess;
    
}
