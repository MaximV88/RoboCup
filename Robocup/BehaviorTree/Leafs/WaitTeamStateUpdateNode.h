//
//  WaitTeamStateUpdateNode.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/17/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Robocup__WaitTeamStateUpdateNode__
#define __Robocup__WaitTeamStateUpdateNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************************************
     * TurnNode Class:        This command will turn the player’s body direction Moment                 *
     *                        degrees relative to the current direction.                                *
     ***************************************************************************************************/
    
    class WaitTeamStateUpdateNode : public BehaviorTreeNode {
        
    public:
        WaitTeamStateUpdateNode();
        ~WaitTeamStateUpdateNode();
        
        virtual StatusType process();
        
    };
    
}

#endif