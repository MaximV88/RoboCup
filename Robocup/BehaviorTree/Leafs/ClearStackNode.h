/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Robocup__ClearStackNode__
#define __Robocup__ClearStackNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /**********************************************
     * ClearStackNode Class: Clears the stack.    *
     *********************************************/
    
    class ClearStackNode : public BehaviorTreeNode {
        
        
    public:
        ClearStackNode();
        ~ClearStackNode();
        
        virtual StatusType process();
        
    };
    
}

#endif 
