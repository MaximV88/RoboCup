/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include "EndActNode.h"
#include "Brain.h"

#define DEBUG_ACTION_DESCRIPTION "Ending the current Act."

using namespace behavior;

EndActNode::EndActNode() {
    
}

EndActNode::~EndActNode() {
    
}

StatusType EndActNode::process() {
    
    //Print the action's description
    DebugLogVerbose(DEBUG_ACTION_DESCRIPTION);
    
    //Make the brain send the instructions gathered
    getContext().getBrain().endAct();
    
    return StatusTypeSuccess;
    
}
