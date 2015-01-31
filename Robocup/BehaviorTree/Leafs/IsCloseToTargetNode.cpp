/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include "IsCloseToTargetNode.h"
#include "Player.h"
#define IS_CLOSE_TO_TARGET_NODE_TARGET_ERROR "IsCloseToTargetNode Error: No Target given"
#define IS_CLOSE_TO_TARGET_NODE_VALUE_ERROR "IsCloseToTargetNode Error: No Observable value given in the "
#define IS_CLOSE_TO_TARGET_NODE_INT_ERROR "IsCloseToTargetNode Error: No int value given in the "

using namespace behavior;

IsCloseToTargetNode::IsCloseToTargetNode(double dDistanceThreshold) {
    
    //Set the internal member's value to be used later on
    m_dDistanceThreshold = dDistanceThreshold;

}

IsCloseToTargetNode::~IsCloseToTargetNode() {
    
}

StatusType IsCloseToTargetNode::process() {
    
    //Add the required input from the target
    BehaviorTarget *cTarget = getContext().getCurrentTarget();
    
    //If no target is present, return failed
    if (cTarget == NULL) {
        
        //Print error and return
        DebugLogError(IS_CLOSE_TO_TARGET_NODE_TARGET_ERROR);
        return StatusTypeFailure;
        
    }

    //Check if our target has an origin to move to
    const Observable *cObservable = cTarget->getObservable();
    
    //If no coordinate is given, return failed
    if (cObservable == NULL) {
        
        //Print the action's description
        DebugLogError(IS_CLOSE_TO_TARGET_NODE_VALUE_ERROR << *cTarget);
        return StatusTypeFailure;
        
    }

    if (cObservable->distance < m_dDistanceThreshold)
        return StatusTypeSuccess;

    //Havnt found it
    return StatusTypeFailure;
    
}
