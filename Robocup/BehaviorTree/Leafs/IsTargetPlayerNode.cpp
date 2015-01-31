/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include "IsTargetPlayerNode.h"

#define IS_TARGET_PLAYER_NODE_TARGET_ERROR "IsTargetPlayerNode Error: No Target given"
#define IS_TARGET_PLAYER_NODE_VALUE_ERROR "IsTargetPlayerNode Error: No Observable value given in the "

#define DEBUG_ACTION_DESCRIPTION "Checking if the Target is a Player."

using namespace behavior;

IsTargetPlayerNode::IsTargetPlayerNode() {
    
}

IsTargetPlayerNode::~IsTargetPlayerNode() {
    
}

StatusType IsTargetPlayerNode::process() {
    
    //Get the current target
    BehaviorTarget* cTarget = getContext().getCurrentTarget();
    
    if (cTarget == NULL) {

        //Print error and return
        DebugLogError(IS_TARGET_PLAYER_NODE_TARGET_ERROR);
        return StatusTypeFailure;
        
    }
    
    const Observable* cObservable = cTarget->getObservable();

    //Check if we have something to check
    if (cObservable == NULL) {
        
        //Print error and return
        DebugLogError(IS_TARGET_PLAYER_NODE_VALUE_ERROR << *cTarget);
        return StatusTypeFailure;
        
    }
    
    //Print the action's description
    DebugLogVerbose(DEBUG_ACTION_DESCRIPTION);
    
    //If the observable is not a player, then it is not an enemy (TODO: CHECK FOR GOALS?)
    if (cObservable->type != ObservableTypePlayer)
        return StatusTypeFailure;
        
    //All was OK
    return StatusTypeSuccess;
    
}