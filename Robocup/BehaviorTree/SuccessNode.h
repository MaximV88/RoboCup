/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Robocup__SuccessNode__
#define __Robocup__SuccessNode__

#include "DecoratorNode.h"

namespace behavior {
    
    class SuccessNode : public DecoratorNode {
        
        
    public:
        SuccessNode(BehaviorTreeNode* cChild);
        ~SuccessNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
