/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Robocup__SetTargetToNode__
#define __Robocup__SetTargetToNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************************************
     * TurnNode Class:        This command will turn the player’s body direction Moment                 *
     *                        degrees relative to the current direction.                                *
     ***************************************************************************************************/
    
    class SetTargetToNode : public BehaviorTreeNode {
        
    private:
        
        BehaviorTarget* m_cTarget;
        
    public:
        SetTargetToNode(BehaviorTarget* cTarget);
        ~SetTargetToNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
