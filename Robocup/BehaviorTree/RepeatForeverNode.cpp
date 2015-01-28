//
//  RepeatForeverNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/28/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "RepeatForeverNode.h"

using namespace behavior;

RepeatForeverNode::RepeatForeverNode(BehaviorTreeNode* cChild) :
DecoratorNode(cChild) {
    
}

RepeatForeverNode::~RepeatForeverNode() {
    
}

StatusType RepeatForeverNode::process() {
    
    //Always repeat until child node has finished
    while (true) {
        
        BehaviorTreeNode *cChild = &getChild();
        
        //Run the child
        cChild->tick();
        
        //Check if it's still running - if so dont disturbe
        if (cChild->isRunning())
            break;
        
        //Reset the child for another repeating
        cChild->reset();
        
    }
    
    //Something went wrong
    return StatusTypeInvalid;
    
}
