/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include "SetTargetToTwiceMaximumHeadAngleNode.h"
#include "Player.h"

#define NODE_NAME "SetTargetToTwiceMaximumHeadAngleNode"

#define DEBUG_ACTION_DESCRIPTION_SUCCESS_1 "Successfuly set rotation for Neck to center at "
#define DEBUG_ACTION_DESCRIPTION_SUCCESS_2 " degrees."

using namespace behavior;

SetTargetToTwiceMaximumHeadAngleNode::SetTargetToTwiceMaximumHeadAngleNode() {
    
}

SetTargetToTwiceMaximumHeadAngleNode::~SetTargetToTwiceMaximumHeadAngleNode() {
    
}

StatusType SetTargetToTwiceMaximumHeadAngleNode::process() {
    
    ServerState *cServerState = getContext().getPlayer().getLastServerState();
    
    //Check if valid for calculation
    if (cServerState == NULL)
        return StatusTypeFailure;
    
    
    double dMaxMomentAngle = cServerState->maxNeckAngle * 2;
    
    //Limit
    if (dMaxMomentAngle > cServerState->maxMoment)
        dMaxMomentAngle = cServerState->maxMoment;
    
    //Set the rotation as the target
    getContext().setCurrentTarget(new BehaviorTarget(dMaxMomentAngle, NODE_NAME));
    
    //Print the action's description
    DebugLogVerbose(DEBUG_ACTION_DESCRIPTION_SUCCESS_1 << dMaxMomentAngle <<
                    DEBUG_ACTION_DESCRIPTION_SUCCESS_2);
    
    //Delete after usage
    delete cServerState;
    
    //All is OK
    return StatusTypeSuccess;
    
}
