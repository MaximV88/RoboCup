//
//  SetPositiveNeckTurnAngleNode.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/15/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

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
