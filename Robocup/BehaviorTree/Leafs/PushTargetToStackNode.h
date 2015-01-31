/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Ex3__PushTargetToStackNode__
#define __Ex3__PushTargetToStackNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************************************
     * PushToStackNode Class: Request the Brain to send gathered instructions.                          *
     ***************************************************************************************************/
    
    class PushTargetToStackNode : public BehaviorTreeNode {
        
        
    public:
        PushTargetToStackNode();
        ~PushTargetToStackNode();
        
        virtual StatusType process();
        
    };
    
}

#endif