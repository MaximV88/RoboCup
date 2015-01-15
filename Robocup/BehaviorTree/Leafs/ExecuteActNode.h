//
//  ExecuteActNode.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/15/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

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
