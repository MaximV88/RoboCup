//
//  WaitBodyStateUpdateNode.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/17/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Robocup__WaitBodyStateUpdateNode__
#define __Robocup__WaitBodyStateUpdateNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************************************
     * TurnNode Class:        This command will turn the player’s body direction Moment                 *
     *                        degrees relative to the current direction.                                *
     ***************************************************************************************************/
    
    class WaitBodyStateUpdateNode : public BehaviorTreeNode {
        
    public:
        WaitBodyStateUpdateNode();
        ~WaitBodyStateUpdateNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
