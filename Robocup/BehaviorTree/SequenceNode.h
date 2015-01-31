/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Ex3__SequenceNode__
#define __Ex3__SequenceNode__

#include <stdio.h>
#include "CompositionNode.h"

namespace behavior {
    
    class SequenceNode :  public CompositionNode {
        
    private:
        
        std::vector<BehaviorTreeNode*>::iterator m_cIterator;
        
    public:
        
        SequenceNode();
        virtual ~SequenceNode();
        
        
        virtual void initialize();
        
        virtual StatusType process();
        
        
    };
    
}

#endif
