//
//  DecoratorNode.cpp
//  Ex3
//
//  Created by Maxim Vainshtein on 1/10/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

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
