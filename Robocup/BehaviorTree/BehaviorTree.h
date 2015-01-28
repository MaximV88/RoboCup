//
//  BehaviorTree.h
//  Ex3
//
//  Created by Maxim Vainshtein on 1/9/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Ex3__BehaviorTree__
#define __Ex3__BehaviorTree__

#include <stdio.h>
#include "BehaviorTreeNode.h"
#include "BehaviorContext.h"
#include "Nameable.h"


namespace behavior {

    class BehaviorTree : public Nameable {
            
        //Root of the tree
        BehaviorTreeNode *m_cRoot;
        
        //Context of the tree
        BehaviorContext m_cContext;
                
    public:
        
        BehaviorTree(Player& cPlayer, Brain& cBrain, const std::string& strName);
        ~BehaviorTree();
        
        void setRoot(BehaviorTreeNode *cRoot);
        
        BehaviorContext& getContext();
                
        void tick();
        
        void abort();
        
        void reset();
        
    };
    
}

#endif
