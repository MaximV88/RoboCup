//
//  SuccessNode.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/16/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Robocup__SuccessNode__
#define __Robocup__SuccessNode__

#include "DecoratorNode.h"

namespace behavior {
    
    class SuccessNode : public DecoratorNode {
        
        
    public:
        SuccessNode(BehaviorTreeNode* cChild);
        ~SuccessNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
