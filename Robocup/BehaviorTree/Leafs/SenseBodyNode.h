//
//  SenseBodyNode.h
//  Ex3
//
//  Created by Maxim Vainshtein on 1/10/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Ex3__SenseBodyNode__
#define __Ex3__SenseBodyNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************************************
     * SenseBodyNode Class: Requests the server to send sense body information. Note the server sends   *
     *                        sense body information every cycle if you connect with version 6.00       *
     *                        or higher.                                                                *
     ***************************************************************************************************/
    
    class SenseBodyNode : public BehaviorTreeNode {
        
        
    public:
        SenseBodyNode();
        ~SenseBodyNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
