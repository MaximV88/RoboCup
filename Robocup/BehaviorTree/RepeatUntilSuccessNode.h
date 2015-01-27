//
//  RepeatUntilSuccessNode.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/27/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Robocup__RepeatUntilSuccessNode__
#define __Robocup__RepeatUntilSuccessNode__

#include "DecoratorNode.h"

namespace behavior {
    
    class RepeatUntilSuccessNode : public DecoratorNode {
        
    public:
        
        RepeatUntilSuccessNode(BehaviorTreeNode* cChild);
        ~RepeatUntilSuccessNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
