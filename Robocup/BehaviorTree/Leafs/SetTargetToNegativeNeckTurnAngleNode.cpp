/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include "SetTargetToNegativeNeckTurnAngleNode.h"
#include "Player.h"

#define VIEW_FACTOR_NARROW 0.5
#define VIEW_FACTOR_NORMAL 1
#define VIEW_FACTOR_WIDE 2

#define NODE_NAME "SetTargetToNegativeNeckTurnAngle"

#define DEBUG_ACTION_DESCRIPTION_SUCCESS_1 "Successfuly set negative rotation for Neck at "
#define DEBUG_ACTION_DESCRIPTION_SUCCESS_2 " degrees."
#define DEBUG_ACTION_DESCRIPTION_FAILURE "Could not set negative rotation for Neck any further."

using namespace behavior;

SetTargetToNegativeNeckTurnAngleNode::SetTargetToNegativeNeckTurnAngleNode() {
    
}

SetTargetToNegativeNeckTurnAngleNode::~SetTargetToNegativeNeckTurnAngleNode() {
    
}

StatusType SetTargetToNegativeNeckTurnAngleNode::process() {

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
    
    double dMinAngle = cServerState->minNeckAngle;

    //Check versus the current neck angle
    double dCurrentAngle = cBodyState->headAngle;
    
    //Fail if the current angle is already at max
    if (dCurrentAngle == dMinAngle) {
     
        //Print the action's description
        DebugLogVerbose(DEBUG_ACTION_DESCRIPTION_FAILURE);
        
        //Delete after usage
        delete cBodyState;
        delete cServerState;
        
        return StatusTypeFailure;
    }
    
    //Limit it by the maximum allowed angle
    if (dRotation < dMinAngle)
        dRotation = dMinAngle;
    
    //Set the rotation as the target
    getContext().setCurrentTarget(new BehaviorTarget(dRotation, NODE_NAME));
    
    //Print the action's description
    DebugLogVerbose(DEBUG_ACTION_DESCRIPTION_SUCCESS_1 << dRotation <<
                    DEBUG_ACTION_DESCRIPTION_SUCCESS_2);
    
    //Delete after usage
    delete cBodyState;
    delete cServerState;
    
    //All is OK
    return StatusTypeSuccess;
    
}