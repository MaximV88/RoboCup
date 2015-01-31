/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include "SequenceNode.h"

using namespace behavior;

SequenceNode::SequenceNode() {
    
}

SequenceNode::~SequenceNode() {
    
    
}

void SequenceNode::initialize() {
    
    //The iterator starts on the first member of the vector
    m_cIterator = getChildren().begin();
    
}

StatusType SequenceNode::process() {
    
    while (true) {
        
        //Get the status of the current child
        StatusType eStatus = (*m_cIterator)->tick();
        
        //If the child is not successfull, return the status
        if (eStatus != StatusTypeSuccess)
            return eStatus;
            

        //Otherwise check if reached end of vector
        ++m_cIterator;
        
        //If at the end, we are successfull
        if (m_cIterator == getChildren().end())
            return StatusTypeSuccess;
        
    }
    
}