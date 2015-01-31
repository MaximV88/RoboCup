/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Robocup__SetPositiveNeckTurnAngleNode__
#define __Robocup__SetPositiveNeckTurnAngleNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************
     * SetTargetToPositiveNeckTurnAngleNode Class:                              *
     *                                                                          *
     *      Sets the target to an appropriate rotation angle based on the view  *
     *      and server settings. Returns success if possible to change angle,   *
     *      false otherwise.                                                    *
     ***************************************************************************/
    
    class SetTargetToPositiveNeckTurnAngleNode : public BehaviorTreeNode {
        
    public:
        SetTargetToPositiveNeckTurnAngleNode();
        ~SetTargetToPositiveNeckTurnAngleNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
