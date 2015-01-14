//
//  IsTargetPlayerNode.h
//  Ex3
//
//  Created by Maxim Vainshtein on 1/14/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Ex3__IsTargetPlayerNode__
#define __Ex3__IsTargetPlayerNode__

#include <stdio.h>
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
