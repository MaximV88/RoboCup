/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Robocup__InverterNode__
#define __Robocup__InverterNode__

#include "DecoratorNode.h"

namespace behavior {
    
    class InverterNode : public DecoratorNode {
        
        
    public:
        InverterNode(BehaviorTreeNode* cChild);
        ~InverterNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
