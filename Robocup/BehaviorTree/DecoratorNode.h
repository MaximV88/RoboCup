/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Ex3__DecoratorNode__
#define __Ex3__DecoratorNode__

#include <stdio.h>
#include "BehaviorTreeNode.h"

namespace behavior {
    
    class DecoratorNode : public BehaviorTreeNode {
        
    private:
        
        BehaviorTreeNode * const m_cChild;
        
     //   void terminate(StatusType eStatus);
        
    protected:
        
        BehaviorTreeNode& getChild();
        
    public:
        
        DecoratorNode(BehaviorTreeNode* cChild);
        
        virtual ~DecoratorNode();
        
        void setContext(BehaviorContext& cContext);

    };
    
}

#endif
