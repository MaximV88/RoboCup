//
//  SetTargetToNode.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/14/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Robocup__SetTargetToNode__
#define __Robocup__SetTargetToNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************************************
     * TurnNode Class:        This command will turn the player’s body direction Moment                 *
     *                        degrees relative to the current direction.                                *
     ***************************************************************************************************/
    
    class SetTargetToNode : public BehaviorTreeNode {
        
    private:
        
        BehaviorTarget* m_cTarget;
        
    public:
        SetTargetToNode(BehaviorTarget* cTarget);
        ~SetTargetToNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
