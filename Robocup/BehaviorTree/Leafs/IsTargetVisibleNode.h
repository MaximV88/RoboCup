/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Robocup__IsTargetVisibleNode__
#define __Robocup__IsTargetVisibleNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************************************
     * TurnNode Class:        This command will turn the player’s body direction Moment                 *
     *                        degrees relative to the current direction. Updates the Target's           *
     *                        Observable pointer.                                                       *
     ***************************************************************************************************/
    
    class IsTargetVisibleNode : public BehaviorTreeNode {
        
    public:
        IsTargetVisibleNode();
        ~IsTargetVisibleNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
