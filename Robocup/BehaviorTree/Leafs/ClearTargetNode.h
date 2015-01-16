//
//  ClearTargetNode.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/16/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

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
