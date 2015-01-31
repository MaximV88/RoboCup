/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include "WaitTeamStateUpdateNode.h"
#include "Brain.h"

#define DEBUG_ACTION_DESCRIPTION "Waiting until next TeamState update."

using namespace behavior;

WaitTeamStateUpdateNode::WaitTeamStateUpdateNode() {
    
}

WaitTeamStateUpdateNode::~WaitTeamStateUpdateNode() {
    
}

StatusType WaitTeamStateUpdateNode::process() {
    
    //Print the action's description
    DebugLogVerbose(DEBUG_ACTION_DESCRIPTION);
    
    //Make the brain send the instructions gathered
    getContext().getBrain().waitTeamStateUpdate();
    
    return StatusTypeSuccess;
    
}
