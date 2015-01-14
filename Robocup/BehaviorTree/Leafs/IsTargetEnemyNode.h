//
//  IsTargetEnemyNode.h
//  Ex3
//
//  Created by Maxim Vainshtein on 1/14/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Ex3__IsTargetEnemyNode__
#define __Ex3__IsTargetEnemyNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************************************
     * PushToStackNode Class: Request the Brain to send gathered instructions.                          *
     ***************************************************************************************************/
    
    class IsTargetEnemyNode : public BehaviorTreeNode {
        
        
    public:
        IsTargetEnemyNode();
        ~IsTargetEnemyNode();
        
        virtual StatusType process();
        
    };
    
}

#endif