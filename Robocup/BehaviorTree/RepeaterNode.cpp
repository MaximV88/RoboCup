/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include "RepeaterNode.h"

using namespace behavior;

RepeaterNode::RepeaterNode(BehaviorTreeNode* cChild) :
DecoratorNode(cChild) {
    
}

RepeaterNode::~RepeaterNode() {
    
}

void RepeaterNode::setRepeats(unsigned int uiRepeats) {
    
    //Set the internal counter
    m_uiRepeats = uiRepeats;
    
}

unsigned int RepeaterNode::getRepeats() const {
    
    //Return a copy of the current repeat
    return m_uiRepeats;
    
}

void RepeaterNode::initialize() {
    
    //Initialize the counter to 0
    m_uiCounter = 0;
    
}

StatusType RepeaterNode::process() {
    
    //Always repeat until child node has finished
    while (true) {
        
        BehaviorTreeNode *cChild = &getChild();
        
        //Run the child
        cChild->tick();
        
        //Check if it's still running - if so dont disturbe
        if (cChild->isRunning())
            break;
        
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
