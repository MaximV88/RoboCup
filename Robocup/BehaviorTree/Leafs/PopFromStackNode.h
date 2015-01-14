//
//  PopFromStackNode.h
//  Ex3
//
//  Created by Maxim Vainshtein on 1/14/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Ex3__PopFromStackNode__
#define __Ex3__PopFromStackNode__

#include <stdio.h>

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