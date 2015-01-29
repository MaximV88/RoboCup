//
//  CompositionNode.h
//  Ex3
//
//  Created by Maxim Vainshtein on 1/10/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Ex3__CompositionNode__
#define __Ex3__CompositionNode__

#include <stdio.h>
#include <vector>
#include "BehaviorTreeNode.h"

namespace behavior {
    
    class CompositionNode : public BehaviorTreeNode {
        
    private:
        
        std::vector<BehaviorTreeNode*> m_vcChildren;
        
     //   void terminate(StatusType eStatus);
        
    protected:
        
        std::vector<BehaviorTreeNode*>& getChildren();
        
    public:
        
        CompositionNode();
        virtual ~CompositionNode();
        
        void addChild(BehaviorTreeNode* cChild);
        
        void removeChild(BehaviorTreeNode* cChild);
        
        void clearChildren();
        
        void setContext(BehaviorContext& cContext);
        
    };
    
}

#endif
