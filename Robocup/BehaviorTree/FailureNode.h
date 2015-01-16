//
//  FailureNode.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/16/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Robocup__FailureNode__
#define __Robocup__FailureNode__

#include "DecoratorNode.h"

namespace behavior {
    
    class FailureNode : public DecoratorNode {
        
        
    public:
        FailureNode(BehaviorTreeNode* cChild);
        ~FailureNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
