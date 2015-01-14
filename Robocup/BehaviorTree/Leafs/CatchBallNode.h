//
//  CatchBallNode.h
//  Ex3
//
//  Created by Maxim Vainshtein on 1/10/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Ex3__CatchBallNode__
#define __Ex3__CatchBallNode__

#include <stdio.h>
#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************************************
     * CatchBallNode Class:   Goalie special command: Tries to catch the ball in the given Direction    *
     *                        relative to its body direction. If the catch is successful the ball       *
     *                        will be in the goalie’s hand until kicked away.                           *
     ***************************************************************************************************/

    class CatchBallNode : public BehaviorTreeNode {
        
        
    public:
        CatchBallNode();
        ~CatchBallNode();
        
        virtual StatusType process();

    };
    
}

#endif
