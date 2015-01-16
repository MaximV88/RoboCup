//
//  SetTargetToNegativeNeckTurnAngleNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/15/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "SetTargetToNegativeNeckTurnAngleNode.h"
#include "Player.h"

#define VIEW_FACTOR_NARROW 2
#define VIEW_FACTOR_NORMAL 1
#define VIEW_FACTOR_WIDE 0.5

using namespace behavior;

SetTargetToNegativeNeckTurnAngleNode::SetTargetToNegativeNeckTurnAngleNode() {
    
}

SetTargetToNegativeNeckTurnAngleNode::~SetTargetToNegativeNeckTurnAngleNode() {
    
}

StatusType SetTargetToNegativeNeckTurnAngleNode::process() {

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
            dRotation = dVisibleAngle * VIEW_FACTOR_NARROW * -1;
            break;
            
        case WidthTypeNormal:
            
            //This will result in 90 degrees
            dRotation = dVisibleAngle * VIEW_FACTOR_NORMAL * -1;
            break;
            
            
        case WidthTypeWide:
            
            //This will result in 180 degrees
            dRotation = dVisibleAngle * VIEW_FACTOR_WIDE * -1;
            break;
            
            //Shouldnt reach here
        default:
            break;
    }
    
    double dMinAngle = getContext().getPlayer().getLastServerState()->minNeckAngle;

    //Check versus the current neck angle
    double dCurrentAngle = getContext().getPlayer().getLastBodyState()->headAngle;
    
    //Fail if the current angle is already at max
    if (dCurrentAngle == dMinAngle)
        return StatusTypeFailure;
    
    //Limit it by the maximum allowed angle
    if (dRotation < dMinAngle)
        dRotation = dMinAngle;
    
    //Set the rotation as the target
    getContext().setCurrentTarget(new BehaviorTarget(dRotation));

    //All is OK
    return StatusTypeSuccess;
    
}