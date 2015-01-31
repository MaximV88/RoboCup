/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Robocup__ExecuteActNode__
#define __Robocup__ExecuteActNode__

#include "BehaviorTreeNode.h"
namespace behavior {
    
    /********************************************************************
     * ExecuteActNode Class: Request the Brain to send gathered         *
     *                       instructions if there are any. Otherwise   *
     *                       dont do anything.                          *
     *******************************************************************/
    
    class ExecuteActNode : public BehaviorTreeNode {
        
        
    public:
        ExecuteActNode();
        ~ExecuteActNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
