/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include "ExecuteActNode.h"
#include "Brain.h"

#define DEBUG_ACTION_DESCRIPTION "Executing the current Act."

using namespace behavior;

ExecuteActNode::ExecuteActNode() {
    
}

ExecuteActNode::~ExecuteActNode() {
    
}

StatusType ExecuteActNode::process() {
    
    /*
     * Make the brain send the instructions gathered, 
     * but dont wait if there are none.
     */
    
    //Print the action's description
    DebugLogVerbose(DEBUG_ACTION_DESCRIPTION);
    
    getContext().getBrain().executeAct();
    
    return StatusTypeSuccess;
    
}
