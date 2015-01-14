//
//  InverterNode.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/14/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Robocup__InverterNode__
#define __Robocup__InverterNode__

#include "DecoratorNode.h"

namespace behavior {
    
    class InverterNode : public DecoratorNode {
        
        
    public:
        InverterNode(BehaviorTreeNode* cChild);
        ~InverterNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
