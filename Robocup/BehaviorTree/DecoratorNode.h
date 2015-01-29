//
//  DecoratorNode.h
//  Ex3
//
//  Created by Maxim Vainshtein on 1/10/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Ex3__DecoratorNode__
#define __Ex3__DecoratorNode__

#include <stdio.h>
#include "BehaviorTreeNode.h"

namespace behavior {
    
    class DecoratorNode : public BehaviorTreeNode {
        
    private:
        
        BehaviorTreeNode * const m_cChild;
        
     //   void terminate(StatusType eStatus);
        
    protected:
        
        BehaviorTreeNode& getChild();
        
    public:
        
        DecoratorNode(BehaviorTreeNode* cChild);
        
        virtual ~DecoratorNode();
        
        void setContext(BehaviorContext& cContext);

    };
    
}

#endif
