/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Ex3__SenseBodyNode__
#define __Ex3__SenseBodyNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************************************
     * SenseBodyNode Class: Requests the server to send sense body information. Note the server sends   *
     *                        sense body information every cycle if you connect with version 6.00       *
     *                        or higher.                                                                *
     ***************************************************************************************************/
    
    class SenseBodyNode : public BehaviorTreeNode {
        
        
    public:
        SenseBodyNode();
        ~SenseBodyNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
