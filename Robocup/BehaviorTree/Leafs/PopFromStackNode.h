/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Ex3__PopFromStackNode__
#define __Ex3__PopFromStackNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************************************
     * PushToStackNode Class: Request the Brain to send gathered instructions.                          *
     ***************************************************************************************************/
    
    class PopFromStackNode : public BehaviorTreeNode {
        
        
    public:
        PopFromStackNode();
        ~PopFromStackNode();
        
        virtual StatusType process();
        
    };
    
}

#endif