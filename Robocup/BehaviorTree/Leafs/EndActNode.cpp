//
//  EndActNode.cpp
//  Ex3
//
//  Created by Maxim Vainshtein on 1/11/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

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
