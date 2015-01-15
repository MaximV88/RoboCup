//
//  RepeatUntilFailNode.cpp
//  Ex3
//
//  Created by Maxim Vainshtein on 1/10/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "RepeatUntilFailNode.h"

using namespace behavior;

RepeatUntilFailNode::RepeatUntilFailNode(BehaviorTreeNode* cChild) :
DecoratorNode(cChild) {
    
}

RepeatUntilFailNode::~RepeatUntilFailNode() {
    
}

StatusType RepeatUntilFailNode::process() {
    
    //Always repeat until child node has finished
    while (true) {
        
        BehaviorTreeNode *cChild = &getChild();
        
        //Run the child
        cChild->tick();
        
        //Check if it's still running - if so dont disturbe
        if (cChild->isRunning())
            break;
        
        //Check if the child has failed - if so return failure
        if (cChild->getStatus() == StatusTypeFailure)
            return StatusTypeFailure;

        //Reset the child for another repeating
        cChild->reset();
        
    }
    
    //Something went wrong
    return StatusTypeInvalid;
    
}