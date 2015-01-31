/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

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