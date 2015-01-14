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

void RepeatUntilFailNode::setRepeats(unsigned int uiRepeats) {
    
    //Set the internal counter
    m_uiRepeats = uiRepeats;
    
}

unsigned int RepeatUntilFailNode::getRepeats() const {
    
    //Return a copy of the current repeat
    return m_uiRepeats;
    
}

void RepeatUntilFailNode::initialize() {
    
    //Initialize the counter to 0
    m_uiCounter = 0;
    
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
        
        //Otherwise increment the count - if it's at the limit, return success
        ++m_uiCounter;
        
        if (m_uiRepeats == m_uiCounter)
            return StatusTypeSuccess;
        
        //Reset the child for another repeating
        cChild->reset();
        
    }
    
    //Something went wrong
    return StatusTypeInvalid;
    
}