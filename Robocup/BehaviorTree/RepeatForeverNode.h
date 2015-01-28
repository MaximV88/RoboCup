//
//  RepeatForeverNode.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/28/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Robocup__RepeatForeverNode__
#define __Robocup__RepeatForeverNode__

#include "DecoratorNode.h"

namespace behavior {
    
    class RepeatForeverNode : public DecoratorNode {
        
    public:
        
        RepeatForeverNode(BehaviorTreeNode* cChild);
        ~RepeatForeverNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
