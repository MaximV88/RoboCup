/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Robocup__TurnNeckToCenterNode__
#define __Robocup__TurnNeckToCenterNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************
     * TurnNode Class: This command will turn the player’s neck to  *
     *                 the center.                                  *
     ***************************************************************/
    
    class TurnNeckToCenterNode : public BehaviorTreeNode {
        
        
    public:
        TurnNeckToCenterNode();
        ~TurnNeckToCenterNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
