//
//  SetTargetToMaximumMomentAngleNode.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/16/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Robocup__SetTargetToMaximumMomentAngleNode__
#define __Robocup__SetTargetToMaximumMomentAngleNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************
     * SetTargetToMaximumMomentAngleNode Class:                                 *
     *                                                                          *
     *      Sets the target to the maximum moment value from                    *
     *      the server settings.                                                *
     ***************************************************************************/
    
    class SetTargetToMaximumMomentAngleNode : public BehaviorTreeNode {
        
    public:
        SetTargetToMaximumMomentAngleNode();
        ~SetTargetToMaximumMomentAngleNode();
        
        virtual StatusType process();
        
    };
    
}

#endif 
