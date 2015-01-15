//
//  ExecuteActNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/15/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "ExecuteActNode.h"
#include "Brain.h"

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
    
    getContext().getBrain().executeAct();
    
    return StatusTypeSuccess;
    
}
