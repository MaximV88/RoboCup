//
//  ClearTargetNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/16/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "ClearTargetNode.h"

using namespace behavior;

ClearTargetNode::ClearTargetNode() {
    
}

ClearTargetNode::~ClearTargetNode() {
    
}

StatusType ClearTargetNode::process() {
    
    //Erase the context's target
    getContext().setCurrentTarget(NULL);
    
    //All was OK
    return StatusTypeSuccess;
    
}
