//
//  SetTargetToNegativeNeckTurnAngleNode.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/15/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

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
