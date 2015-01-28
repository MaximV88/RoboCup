//
//  DashTowardsTargetUntilDistanceNode.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/28/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Robocup__DashTowardsTargetUntilDistanceNode__
#define __Robocup__DashTowardsTargetUntilDistanceNode__

#include "SequenceNode.h"

namespace behavior {
    
    /************************************************************************************
     * TurnTowardsTypeNode Class: Turns the body towards a Target type. Also, as a      *
     *                            result the Target is populated by the type's          *
     *                            Observable information.                               *
     ***********************************************************************************/
    
    class DashTowardsTargetUntilDistanceNode : public SequenceNode {
        
    public:
        DashTowardsTargetUntilDistanceNode(double dDistanceThreshold);
        ~DashTowardsTargetUntilDistanceNode();
        
        
    };
    
}

#endif
