//
//  IsCloseToTargetNode.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/19/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Robocup__IsCloseToTargetNode__
#define __Robocup__IsCloseToTargetNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************************************
     * TurnNode Class:        This command will turn the player’s body direction Moment                 *
     *                        degrees relative to the current direction. Updates the Target's           *
     *                        Observable pointer.                                                       *
     ***************************************************************************************************/
    
    class IsCloseToTargetNode : public BehaviorTreeNode {
        
    private:
        
        double m_dDistanceThreshold;
        
    public:
        IsCloseToTargetNode(double dDistanceThreshold);
        ~IsCloseToTargetNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
