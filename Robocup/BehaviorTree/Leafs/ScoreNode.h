//
//  ScoreNode.h
//  Ex3
//
//  Created by Maxim Vainshtein on 1/10/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Ex3__ScoreNode__
#define __Ex3__ScoreNode__

#include <stdio.h>
#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************************************
     * ScoreNode Class: Request the server to send score information.                                   *
     ***************************************************************************************************/
    
    class ScoreNode : public BehaviorTreeNode {
        
        
    public:
        ScoreNode();
        ~ScoreNode();
        
        virtual StatusType process();
        
    };
    
}


#endif
