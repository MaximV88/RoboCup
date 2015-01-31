/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Robocup__DashTowardsBallNode__
#define __Robocup__DashTowardsBallNode__

#include "SequenceNode.h"

namespace behavior {
    
    /************************************************************************************
     * TurnTowardsTypeNode Class: Turns the body towards a Target type. Also, as a      *
     *                            result the Target is populated by the type's          *
     *                            Observable information.                               *
     ***********************************************************************************/
    
    class DashTowardsTargetNode : public SequenceNode {
        
    public:
        DashTowardsTargetNode(int iDistance);
        ~DashTowardsTargetNode();
        
        
    };
    
}

#endif
