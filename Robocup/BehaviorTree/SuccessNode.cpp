//
//  SuccessNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/16/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "SuccessNode.h"

using namespace behavior;

SuccessNode::SuccessNode(BehaviorTreeNode* cChild) :
DecoratorNode(cChild) {
    
}

SuccessNode::~SuccessNode() {
    
}

StatusType SuccessNode::process() {
    
    BehaviorTreeNode *cChild = &getChild();
    
    //Run the child
    cChild->tick();
    
    //Unless we have a result, return the current state
    switch (cChild->getStatus()) {
        case StatusTypeFailure:
            
            return StatusTypeSuccess;
            break;

        default:
            
            //Return the status recieved
            return cChild->getStatus();
            break;
    }
    
    
}