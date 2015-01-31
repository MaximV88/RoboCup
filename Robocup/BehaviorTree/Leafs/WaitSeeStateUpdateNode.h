/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Robocup__WaitSeeStateUpdateNode__
#define __Robocup__WaitSeeStateUpdateNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************************************
     * TurnNode Class:        This command will turn the player’s body direction Moment                 *
     *                        degrees relative to the current direction.                                *
     ***************************************************************************************************/
    
    class WaitSeeStateUpdateNode : public BehaviorTreeNode {
        
    public:
        WaitSeeStateUpdateNode();
        ~WaitSeeStateUpdateNode();
        
        virtual StatusType process();
        
    };
    
}

#endif