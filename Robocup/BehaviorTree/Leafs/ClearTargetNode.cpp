/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include "ClearTargetNode.h"

#define DEBUG_ACTION_DESCRIPTION "Clearing the Target."

using namespace behavior;

ClearTargetNode::ClearTargetNode() {
    
}

ClearTargetNode::~ClearTargetNode() {
    
}

StatusType ClearTargetNode::process() {

    //Print the action's description
    DebugLogVerbose(DEBUG_ACTION_DESCRIPTION);
    
    //Erase the context's target
    getContext().setCurrentTarget(NULL);
    
    //All was OK
    return StatusTypeSuccess;
    
}
