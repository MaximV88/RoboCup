//
//  PushTargetToStackNode.h
//  Ex3
//
//  Created by Maxim Vainshtein on 1/14/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Ex3__PushTargetToStackNode__
#define __Ex3__PushTargetToStackNode__

#include <stdio.h>
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