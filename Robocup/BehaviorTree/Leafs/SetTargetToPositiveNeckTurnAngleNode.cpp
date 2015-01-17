//
//  SetPositiveNeckTurnAngleNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/15/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "SetTargetToPositiveNeckTurnAngleNode.h"
#include "Player.h"

#define VIEW_FACTOR_NARROW 0.5
#define VIEW_FACTOR_NORMAL 1
#define VIEW_FACTOR_WIDE 2

#define NODE_NAME "SetTargetToPositiveNeckTurnAngle"

#define DEBUG_ACTION_DESCRIPTION_SUCCESS_1 "Successfuly set positive rotation for Neck at "
#define DEBUG_ACTION_DESCRIPTION_SUCCESS_2 " degrees."
#define DEBUG_ACTION_DESCRIPTION_FAILURE "Could not set positive rotation for Neck any further."

using namespace behavior;

SetTargetToPositiveNeckTurnAngleNode::SetTargetToPositiveNeckTurnAngleNode() {
    
}

SetTargetToPositiveNeckTurnAngleNode::~SetTargetToPositiveNeckTurnAngleNode() {
    
}

StatusType SetTargetToPositiveNeckTurnAngleNode::process() {
    
    BodyState *cBodyState = getContext().getPlayer().getLastBodyState();
    
    //Check if valid for calculation
    if (cBodyState == NULL)
        return StatusTypeFailure;
    
    ServerState *cServerState = getContext().getPlayer().getLastServerState();
    
    //Check if valid for calculation
    if (cServerState == NULL) {
        
        //Delete after usage
        delete cBodyState;
        
        return StatusTypeFailure;
        
    }
    
    
    //Set the target to the required pointer
    WidthType eWidthType = cBodyState->viewModeWidth;
    double dVisibleAngle = cServerState->visibleAngle;

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
    
    double dMaxAngle = cServerState->maxNeckAngle;
    
    //Check versus the current neck angle
    double dCurrentAngle = cBodyState->headAngle;
    
    //Fail if the current angle is already at max
    if (dCurrentAngle == dMaxAngle) {
    
#if DEBUG_PRINT_ACTION
        
        //Print the action's description
        std::cout << DEBUG_ACTION_DESCRIPTION_FAILURE << std::endl;
        
#endif
        
        //Delete after usage
        delete cBodyState;
        delete cServerState;
        
        return StatusTypeFailure;
    
    }
    
    //Limit it by the minimum allowed angle
    if (dRotation > dMaxAngle)
        dRotation = dMaxAngle;
    
    //Set the rotation as the target
    getContext().setCurrentTarget(new BehaviorTarget(dRotation, NODE_NAME));

#if DEBUG_PRINT_ACTION
    
    //Print the action's description
    std::cout << DEBUG_ACTION_DESCRIPTION_SUCCESS_1 << dRotation <<
    DEBUG_ACTION_DESCRIPTION_SUCCESS_2 << std::endl;
    
#endif
    
    //Delete after usage
    delete cBodyState;
    delete cServerState;
    
    //All is OK
    return StatusTypeSuccess;
    
}
