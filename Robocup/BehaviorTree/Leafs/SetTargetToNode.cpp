//
//  SetTargetToNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/14/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "SetTargetToNode.h"

using namespace behavior;

SetTargetToNode::SetTargetToNode(BehaviorTarget* cTarget) :
m_cTarget(cTarget) {
    
}

SetTargetToNode::~SetTargetToNode() {
    
}

StatusType SetTargetToNode::process() {
    
    //Set the target to the required pointer only if exists
    if (m_cTarget != NULL)
        getContext().setCurrentTarget(new BehaviorTarget(*m_cTarget));
    
    return StatusTypeSuccess;
    
}
