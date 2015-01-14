//
//  EndActNode.cpp
//  Ex3
//
//  Created by Maxim Vainshtein on 1/11/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "EndActNode.h"
#include "Brain.h"

using namespace behavior;

EndActNode::EndActNode() {
    
}

EndActNode::~EndActNode() {
    
}

StatusType EndActNode::process() {
    
    //Make the brain send the instructions gathered
    getContext().getBrain().endAct();
    
    return StatusTypeSuccess;
    
}
