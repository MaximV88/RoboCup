//
//  KickBallNode.h
//  Ex3
//
//  Created by Maxim Vainshtein on 1/10/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Ex3__KickBallNode__
#define __Ex3__KickBallNode__

#include <stdio.h>
#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************************************
     * KickBallNode Class: Accelerates the ball with the given Power in the given Direction.            *
     *                        The direction is relative to the the Direction of the body of the player  *
     *                        and the power is again between minpower and maxparam.                     *
     ***************************************************************************************************/
    
    class KickBallNode : public BehaviorTreeNode {
        
        
    public:
        KickBallNode();
        ~KickBallNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
