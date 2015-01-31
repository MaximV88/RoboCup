/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Ex3__MoveNode__
#define __Ex3__MoveNode__

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
