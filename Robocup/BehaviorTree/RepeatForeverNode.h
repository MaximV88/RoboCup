/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Robocup__RepeatForeverNode__
#define __Robocup__RepeatForeverNode__

#include "DecoratorNode.h"

namespace behavior {
    
    class RepeatForeverNode : public DecoratorNode {
        
    public:
        
        RepeatForeverNode(BehaviorTreeNode* cChild);
        ~RepeatForeverNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
