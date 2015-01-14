//
//  SelectorNode.h
//  Ex3
//
//  Created by Maxim Vainshtein on 1/10/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Ex3__SelectorNode__
#define __Ex3__SelectorNode__

#include <stdio.h>
#include "CompositionNode.h"

namespace behavior {
    
    class SelectorNode : public CompositionNode {
        
    private:
        
        std::vector<BehaviorTreeNode*>::iterator m_cIterator;
        
    public:
        
        SelectorNode();
        virtual ~SelectorNode();
        
        virtual void initialize();
        
        virtual StatusType process();
        
    };
    
}

#endif
