/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include "SelectorNode.h"

using namespace behavior;

SelectorNode::SelectorNode() {
    
}

SelectorNode::~SelectorNode() {
    
    
}

void SelectorNode::initialize() {
    
    //The iterator starts on the first member of the vector
    m_cIterator = getChildren().begin();
    
}

StatusType SelectorNode::process() {
    
    while (true) {
        
        //Get the status of the current child
        StatusType eStatus = (*m_cIterator)->tick();
        
        //If the child is not successfull, return the status
        if (eStatus != StatusTypeFailure)
            return eStatus;
        
        
        //Otherwise check if reached end of vector
        ++m_cIterator;
        
        //If at the end, we are not successfull - not even one node was successfull
        if (m_cIterator == getChildren().end())
            return StatusTypeFailure;
        
    }
    
}