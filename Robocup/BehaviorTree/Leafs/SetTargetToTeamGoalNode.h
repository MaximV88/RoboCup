//
//  SetTargetToTeamGoalNode.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/27/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Robocup__SetTargetToTeamGoalNode__
#define __Robocup__SetTargetToTeamGoalNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************************************
     * TurnNode Class:        This command will turn the player’s body direction Moment                 *
     *                        degrees relative to the current direction. Updates the Target's           *
     *                        Observable pointer.                                                       *
     ***************************************************************************************************/
    
    class SetTargetToTeamGoalNode : public BehaviorTreeNode {
        
    private:
        
        double m_dDegreeThreshold;
        
    public:
        SetTargetToTeamGoalNode();
        ~SetTargetToTeamGoalNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
