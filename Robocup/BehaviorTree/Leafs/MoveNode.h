//
//  MoveNode.h
//  Ex3
//
//  Created by Maxim Vainshtein on 1/10/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Ex3__MoveNode__
#define __Ex3__MoveNode__

#include <stdio.h>
#include "BehaviorTreeNode.h"
#include "Coordinate.h"

namespace behavior {
    
    /****************************************************************************************************
     * MoveNode Class: This node can be executed only before kick off and after a goal. It              *
     *                        moves the player to the exact position of X (between −54 and 54) and Y    *
     *                      (between −32 and 32) in one simulation cycle. This is useful for before kick*
     *                       off arrangements.                                                          *
     ***************************************************************************************************/
    
    class MoveNode : public BehaviorTreeNode {
        
    public:
        
        MoveNode();
        ~MoveNode();
                
        virtual StatusType process();

    };
    
}

#endif
