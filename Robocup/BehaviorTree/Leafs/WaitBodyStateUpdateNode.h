/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Robocup__WaitBodyStateUpdateNode__
#define __Robocup__WaitBodyStateUpdateNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************************************
     * TurnNode Class:        This command will turn the player’s body direction Moment                 *
     *                        degrees relative to the current direction.                                *
     ***************************************************************************************************/
    
    class WaitBodyStateUpdateNode : public BehaviorTreeNode {
        
    public:
        WaitBodyStateUpdateNode();
        ~WaitBodyStateUpdateNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
