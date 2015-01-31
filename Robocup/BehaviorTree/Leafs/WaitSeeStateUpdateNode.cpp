/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include "WaitSeeStateUpdateNode.h"
#include "Brain.h"

#define DEBUG_ACTION_DESCRIPTION "Waiting until next SeeState update."

using namespace behavior;

WaitSeeStateUpdateNode::WaitSeeStateUpdateNode() {
    
}

WaitSeeStateUpdateNode::~WaitSeeStateUpdateNode() {
    
}

StatusType WaitSeeStateUpdateNode::process() {
    
    //Print the action's description
    DebugLogVerbose(DEBUG_ACTION_DESCRIPTION);
    
    //Make the brain send the instructions gathered
    getContext().getBrain().waitSeeStateUpdate();
    
    return StatusTypeSuccess;
    
}
