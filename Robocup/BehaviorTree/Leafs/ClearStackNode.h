//
//  ClearStackNode.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/16/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

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
