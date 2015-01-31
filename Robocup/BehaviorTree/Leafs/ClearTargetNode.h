/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Robocup__ClearTargetNode__
#define __Robocup__ClearTargetNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /********************************************************
     * ClearTargetNode Class: Clears the current target.    *
     *******************************************************/
    
    class ClearTargetNode : public BehaviorTreeNode {
        
        
    public:
        ClearTargetNode();
        ~ClearTargetNode();
        
        virtual StatusType process();
        
    };
    
}

#endif 
