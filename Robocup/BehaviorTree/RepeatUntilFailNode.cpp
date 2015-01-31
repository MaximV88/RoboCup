/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

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