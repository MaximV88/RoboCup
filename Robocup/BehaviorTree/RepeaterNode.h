/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Ex3__RepeaterNode__
#define __Ex3__RepeaterNode__

#include <stdio.h>
#include "DecoratorNode.h"

namespace behavior {
    
    class RepeaterNode : public DecoratorNode {
        
    private:
        
        unsigned int m_uiCounter;
        unsigned int m_uiRepeats;
        
    public:
        
        RepeaterNode(BehaviorTreeNode* cChild);
        ~RepeaterNode();
        
        void setRepeats(unsigned int uiRepeats);
        
        unsigned int getRepeats() const;
        
        virtual void initialize();
        
        virtual StatusType process();
        
        
    };
    
}

#endif
