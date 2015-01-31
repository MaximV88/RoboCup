/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Ex3__CatchBallNode__
#define __Ex3__CatchBallNode__

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
