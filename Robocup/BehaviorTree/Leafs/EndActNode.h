//
//  EndActNode.h
//  Ex3
//
//  Created by Maxim Vainshtein on 1/11/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Ex3__EndActNode__
#define __Ex3__EndActNode__

#include <stdio.h>
#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************************************
     * EndActNode Class: Request the Brain to send gathered instructions.                               *
     ***************************************************************************************************/
    
    class EndActNode : public BehaviorTreeNode {
        
        
    public:
        EndActNode();
        ~EndActNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
