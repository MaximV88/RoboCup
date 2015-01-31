/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Robocup__SetTargetToNegativeNeckTurnAngleNode__
#define __Robocup__SetTargetToNegativeNeckTurnAngleNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************
     * SetTargetToNegativeNeckTurnAngleNode Class:                              *
     *                                                                          *
     *      Sets the target to an appropriate rotation angle based on the view  *
     *      and server settings. Returns success if possible to change angle,   *
     *      false otherwise.                                                    *
     ***************************************************************************/
    
    class SetTargetToNegativeNeckTurnAngleNode : public BehaviorTreeNode {
        
    public:
        SetTargetToNegativeNeckTurnAngleNode();
        ~SetTargetToNegativeNeckTurnAngleNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
