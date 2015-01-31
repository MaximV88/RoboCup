/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Robocup__FailureNode__
#define __Robocup__FailureNode__

#include "DecoratorNode.h"

namespace behavior {
    
    class FailureNode : public DecoratorNode {
        
        
    public:
        FailureNode(BehaviorTreeNode* cChild);
        ~FailureNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
