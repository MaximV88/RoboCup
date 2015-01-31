/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Ex3__IsTargetEnemyNode__
#define __Ex3__IsTargetEnemyNode__

#include "BehaviorTreeNode.h"
#include "Nameable.h"

namespace behavior {
    
    /****************************************************************************************************
     * PushToStackNode Class: Request the Brain to send gathered instructions.                          *
     ***************************************************************************************************/
    
    class IsTargetEnemyNode : public BehaviorTreeNode {
        
        
    public:
        IsTargetEnemyNode();
        ~IsTargetEnemyNode();
        
        virtual StatusType process();
        
    };
    
}

#endif