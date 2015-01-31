/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Robocup__RepeatUntilSuccessNode__
#define __Robocup__RepeatUntilSuccessNode__

#include "DecoratorNode.h"

namespace behavior {
    
    class RepeatUntilSuccessNode : public DecoratorNode {
        
    public:
        
        RepeatUntilSuccessNode(BehaviorTreeNode* cChild);
        ~RepeatUntilSuccessNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
