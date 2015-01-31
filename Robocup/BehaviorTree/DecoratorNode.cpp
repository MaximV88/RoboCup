/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include "DecoratorNode.h"

using namespace behavior;

DecoratorNode::DecoratorNode(BehaviorTreeNode* cChild) : m_cChild(cChild) {
    
}

DecoratorNode::~DecoratorNode() {
    
    //Remove the child
    delete m_cChild;
    
}

void DecoratorNode::setContext(BehaviorContext& cContext) {

    //Call the parent function
    BehaviorTreeNode::setContext(cContext);
    
    //Set the child (thats why we overloaded)
    m_cChild->setContext(cContext);
    
}

BehaviorTreeNode& DecoratorNode::getChild() {
    
    //Return the child
    return *m_cChild;
    
}
/*
void DecoratorNode::terminate(StatusType eStatus) {
    
    switch (eStatus) {
            
        //Send Abort message downwards
        case StatusTypeAborted:
            
            if (m_cChild != NULL && m_cChild->isRunning())
                m_cChild->abort();
            
            break;
            
        default:
            break;
    }
    

    
}
*/