/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Robocup__WaitTeamStateUpdateNode__
#define __Robocup__WaitTeamStateUpdateNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************************************
     * TurnNode Class:        This command will turn the player’s body direction Moment                 *
     *                        degrees relative to the current direction.                                *
     ***************************************************************************************************/
    
    class WaitTeamStateUpdateNode : public BehaviorTreeNode {
        
    public:
        WaitTeamStateUpdateNode();
        ~WaitTeamStateUpdateNode();
        
        virtual StatusType process();
        
    };
    
}

#endif