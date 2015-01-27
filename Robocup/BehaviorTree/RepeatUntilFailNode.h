//
//  RepeatUntilFailNode.h
//  Ex3
//
//  Created by Maxim Vainshtein on 1/10/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Ex3__RepeatUntilFailNode__
#define __Ex3__RepeatUntilFailNode__

#include "DecoratorNode.h"

namespace behavior {
    
    class RepeatUntilFailNode : public DecoratorNode {
        
    public:
        
        RepeatUntilFailNode(BehaviorTreeNode* cChild);
        ~RepeatUntilFailNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
