/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Robocup__IsTurnedOnTargetNode__
#define __Robocup__IsTurnedOnTargetNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************************************
     * TurnNode Class:        This command will turn the player’s body direction Moment                 *
     *                        degrees relative to the current direction. Updates the Target's           *
     *                        Observable pointer.                                                       *
     ***************************************************************************************************/
    
    class IsTurnedOnTargetNode : public BehaviorTreeNode {
        
    private:
        
        double m_dDegreeThreshold;
        
    public:
        IsTurnedOnTargetNode(double dDegreeThreshold);
        ~IsTurnedOnTargetNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
