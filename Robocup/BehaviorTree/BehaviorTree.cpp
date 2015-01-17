//
//  BehaviorTree.cpp
//  Ex3
//
//  Created by Maxim Vainshtein on 1/9/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "BehaviorTree.h"

#define ERROR_NO_ROOT "BehaviorTree Error: No root found."
#define ERROR_NO_ROOT_SET "BehaviorTree Error: No root was set."

using namespace behavior;

BehaviorTree::BehaviorTree(Player& cPlayer, Brain& cBrain, const std::string& strName) :
Nameable(strName), m_cContext(cPlayer, cBrain), m_cRoot(NULL) {
    
}

BehaviorTree::~BehaviorTree() {
    
    //Remove the root at deletion
    if (m_cRoot != NULL)
        delete m_cRoot;
    
}

void BehaviorTree::setRoot(BehaviorTreeNode *cRoot) {
    
    //Replace the root
    m_cRoot = cRoot;
    
    //Set the root's context
    if (m_cRoot != NULL) {
        
        //Set the root to conform to our context
        m_cRoot->setContext(m_cContext);
        
    }
    else {
        
        //This is an error
        std::cerr << ERROR_NO_ROOT_SET << std::endl;

    }
    
}

BehaviorContext& BehaviorTree::getContext() {
    
    //Return the stored context
    return m_cContext;
    
}

void BehaviorTree::tick() {
 
    //Tick the root if exists
    if (m_cRoot != NULL)
        m_cRoot->tick();
    else {
     
        //Present error message
        std::cerr << ERROR_NO_ROOT << std::endl;
    
    }
    
}