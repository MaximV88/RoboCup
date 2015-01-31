/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Ex3__SelectorNode__
#define __Ex3__SelectorNode__

#include <stdio.h>
#include "CompositionNode.h"

namespace behavior {
    
    class SelectorNode : public CompositionNode {
        
    private:
        
        std::vector<BehaviorTreeNode*>::iterator m_cIterator;
        
    public:
        
        SelectorNode();
        virtual ~SelectorNode();
        
        virtual void initialize();
        
        virtual StatusType process();
        
    };
    
}

#endif
