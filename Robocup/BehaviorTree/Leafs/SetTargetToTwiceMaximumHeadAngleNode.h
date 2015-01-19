//
//  SetTargetToTwiceMaximumHeadAngleNode.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/19/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Robocup__SetTargetToTwiceMaximumHeadAngleNode__
#define __Robocup__SetTargetToTwiceMaximumHeadAngleNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************
     * SetTargetToMaximumMomentAngleNode Class:                                 *
     *                                                                          *
     *      Sets the target to the maximum moment value from                    *
     *      the server settings.                                                *
     ***************************************************************************/
    
    class SetTargetToTwiceMaximumHeadAngleNode : public BehaviorTreeNode {
        
    public:
        SetTargetToTwiceMaximumHeadAngleNode();
        ~SetTargetToTwiceMaximumHeadAngleNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
