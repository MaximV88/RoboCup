//
//  RepeatUntilSuccessNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/27/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "RepeatUntilSuccessNode.h"

using namespace behavior;

RepeatUntilSuccessNode::RepeatUntilSuccessNode(BehaviorTreeNode* cChild) :
DecoratorNode(cChild) {
    
}

RepeatUntilSuccessNode::~RepeatUntilSuccessNode() {
    
}

StatusType RepeatUntilSuccessNode::process() {
    
    //Always repeat until child node has finished
    while (true) {
        
        BehaviorTreeNode *cChild = &getChild();
        
        //Run the child
        cChild->tick();
        
        //Check if it's still running - if so dont disturbe
        if (cChild->isRunning())
            break;
        
        //Check if the child has failed - if so return failure
        if (cChild->getStatus() == StatusTypeSuccess)
            return StatusTypeSuccess;
        
        //Reset the child for another repeating
        cChild->reset();
        
    }
    
    //Something went wrong
    return StatusTypeInvalid;
    
}