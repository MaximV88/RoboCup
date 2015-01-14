//
//  CompositionNode.cpp
//  Ex3
//
//  Created by Maxim Vainshtein on 1/10/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "CompositionNode.h"

using namespace behavior;

CompositionNode::CompositionNode() {
    
}

CompositionNode::~CompositionNode() {
    
    //Remove all children from memory
    clearChildren();
    
}

std::vector<BehaviorTreeNode*>& CompositionNode::getChildren() {
    
    //Return the vector containing the children
    return m_vcChildren;
    
}

void CompositionNode::addChild(BehaviorTreeNode *cChild) {
    
    //Add a child to the vector
    m_vcChildren.push_back(cChild);
    
}

void CompositionNode::removeChild(BehaviorTreeNode *cChild) {
    
    //Remove the specific child
    for (std::vector<BehaviorTreeNode*>::iterator iter = m_vcChildren.begin() ; iter != m_vcChildren.end() ; iter++) {
        
        //Delete the node and break the loop
        if (*iter == cChild) {
            delete *iter;
            break;
        }
        
    }
    
}

void CompositionNode::clearChildren() {
    
    //Clear all the children (delete them)
    for (std::vector<BehaviorTreeNode*>::iterator iter = m_vcChildren.begin() ; iter != m_vcChildren.end() ; iter++) {
        
        //Delete the node
        delete *iter;
        
    }
    
    //Clear the vector
    m_vcChildren.clear();
    
}

void CompositionNode::setContext(BehaviorContext& cContext) {
    
    //Call the parent function
    BehaviorTreeNode::setContext(cContext);
    
    //Set the children (thats why we overloaded)
    for (std::vector<BehaviorTreeNode*>::iterator iter = m_vcChildren.begin() ; iter != m_vcChildren.end() ; iter++) {
        
        //Set the node
        (*iter)->setContext(cContext);
        
    }
    
}
