/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include "InverterNode.h"

using namespace behavior;

InverterNode::InverterNode(BehaviorTreeNode* cChild) :
DecoratorNode(cChild) {
    
}

InverterNode::~InverterNode() {
    
}

StatusType InverterNode::process() {
    
    BehaviorTreeNode *cChild = &getChild();
    
    //Run the child
    cChild->tick();
    
    //Unless we have a result, return the current state
    switch (cChild->getStatus()) {
        case StatusTypeFailure:
            
            return StatusTypeSuccess;
            break;
            
        case StatusTypeSuccess:
            
            return StatusTypeFailure;
            break;
            
        default:
            
            //Return the status recieved
            return cChild->getStatus();
            break;
    }
    
    
}