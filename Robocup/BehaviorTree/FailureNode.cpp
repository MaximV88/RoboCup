/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

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