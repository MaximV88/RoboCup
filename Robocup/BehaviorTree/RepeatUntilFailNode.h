/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Ex3__RepeatUntilFailNode__
#define __Ex3__RepeatUntilFailNode__

#include "DecoratorNode.h"

namespace behavior {
    
    class RepeatUntilFailNode : public DecoratorNode {
        
    public:
        
        RepeatUntilFailNode(BehaviorTreeNode* cChild);
        ~RepeatUntilFailNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
