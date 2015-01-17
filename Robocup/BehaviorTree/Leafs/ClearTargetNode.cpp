//
//  ClearTargetNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/16/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "ClearTargetNode.h"

#define DEBUG_ACTION_DESCRIPTION "Clearing the Target."

using namespace behavior;

ClearTargetNode::ClearTargetNode() {
    
}

ClearTargetNode::~ClearTargetNode() {
    
}

StatusType ClearTargetNode::process() {
    
#if DEBUG_PRINT_ACTION
    
    //Print the action's description
    std::cout << DEBUG_ACTION_DESCRIPTION << std::endl;
    
#endif
    
    //Erase the context's target
    getContext().setCurrentTarget(NULL);
    
    //All was OK
    return StatusTypeSuccess;
    
}
