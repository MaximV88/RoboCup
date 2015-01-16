//
//  SetPositiveNeckTurnAngleNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/15/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "SetTargetToPositiveNeckTurnAngleNode.h"
#include "Player.h"

#define VIEW_FACTOR_NARROW 2
#define VIEW_FACTOR_NORMAL 1
#define VIEW_FACTOR_WIDE 0.5

using namespace behavior;

SetTargetToPositiveNeckTurnAngleNode::SetTargetToPositiveNeckTurnAngleNode() {
    
}

SetTargetToPositiveNeckTurnAngleNode::~SetTargetToPositiveNeckTurnAngleNode() {
    
}

StatusType SetTargetToPositiveNeckTurnAngleNode::process() {
    
    //Check if valid for calculation
    if (getContext().getPlayer().getLastBodyState() == NULL)
        return StatusTypeFailure;
    
    
    //Set the target to the required pointer
    WidthType eWidthType = getContext().getPlayer().getLastBodyState()->viewModeWidth;
    double dVisibleAngle = getContext().getPlayer().getLastServerState()->visibleAngle;

    //Set the target's rotation value based on the width
    double dRotation = 0;
    
    
    /*
     * Default view width factors:
     * wide     - 0.5
     * normail  - 1
     * narrow   - 2
     *
     * View angle: visible_angle * view_width_factor
     */
    
    switch (eWidthType) {
        case WidthTypeNarrow:
            
            //This will result in 45 degrees
            dRotation = dVisibleAngle * VIEW_FACTOR_NARROW;
            break;
            
        case WidthTypeNormal:
            
            //This will result in 90 degrees
            dRotation = dVisibleAngle * VIEW_FACTOR_NORMAL;
            break;
            
            
        case WidthTypeWide:
            
            //This will result in 180 degrees
            dRotation = dVisibleAngle * VIEW_FACTOR_WIDE;
            break;
            
        //Shouldnt reach here
        default:
            break;
    }
    
    double dMaxAngle = getContext().getPlayer().getLastServerState()->maxNeckAngle;
    
    //Check versus the current neck angle
    double dCurrentAngle = getContext().getPlayer().getLastBodyState()->headAngle;
    
    //Fail if the current angle is already at max
    if (dCurrentAngle == dMaxAngle)
        return StatusTypeFailure;
    
    //Limit it by the minimum allowed angle
    if (dRotation > dMaxAngle)
        dRotation = dMaxAngle;
    
    //Set the rotation as the target
    getContext().setCurrentTarget(new BehaviorTarget(dRotation));

    //All is OK
    return StatusTypeSuccess;
    
}
