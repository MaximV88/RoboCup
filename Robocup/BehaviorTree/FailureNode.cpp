//
//  FailureNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/16/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "FailureNode.h"

using namespace behavior;

FailureNode::FailureNode(BehaviorTreeNode* cChild) :
DecoratorNode(cChild) {
    
}

FailureNode::~FailureNode() {
    
}

StatusType FailureNode::process() {
    
    BehaviorTreeNode *cChild = &getChild();
    
    //Run the child
    cChild->tick();
    
    //Unless we have a result, return the current state
    switch (cChild->getStatus()) {

        case StatusTypeSuccess:
            
            return StatusTypeFailure;
            break;
            
        default:
            
            //Return the status recieved
            return cChild->getStatus();
            break;
    }
    
    
}