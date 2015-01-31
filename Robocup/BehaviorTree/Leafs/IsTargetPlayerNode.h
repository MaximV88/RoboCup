/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Ex3__IsTargetPlayerNode__
#define __Ex3__IsTargetPlayerNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************************************
     * PushToStackNode Class: Request the Brain to send gathered instructions.                          *
     ***************************************************************************************************/
    
    class IsTargetPlayerNode : public BehaviorTreeNode {
        
        
    public:
        IsTargetPlayerNode();
        ~IsTargetPlayerNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
