//
//  SequenceNode.h
//  Ex3
//
//  Created by Maxim Vainshtein on 1/10/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Ex3__SequenceNode__
#define __Ex3__SequenceNode__

#include <stdio.h>
#include "CompositionNode.h"

namespace behavior {
    
    class SequenceNode :  public CompositionNode {
        
    private:
        
        std::vector<BehaviorTreeNode*>::iterator m_cIterator;
        
    public:
        
        SequenceNode();
        virtual ~SequenceNode();
        
        
        virtual void initialize();
        
        virtual StatusType process();
        
        
    };
    
}

#endif
