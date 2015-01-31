/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Robocup__IsCloseToTargetNode__
#define __Robocup__IsCloseToTargetNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************************************
     * TurnNode Class:        This command will turn the player’s body direction Moment                 *
     *                        degrees relative to the current direction. Updates the Target's           *
     *                        Observable pointer.                                                       *
     ***************************************************************************************************/
    
    class IsCloseToTargetNode : public BehaviorTreeNode {
        
    private:
        
        double m_dDistanceThreshold;
        
    public:
        IsCloseToTargetNode(double dDistanceThreshold);
        ~IsCloseToTargetNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
