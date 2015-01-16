//
//  TurnNeckToCenterNode.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/16/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Robocup__TurnNeckToCenterNode__
#define __Robocup__TurnNeckToCenterNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************
     * TurnNode Class: This command will turn the player’s neck to  *
     *                 the center.                                  *
     ***************************************************************/
    
    class TurnNeckToCenterNode : public BehaviorTreeNode {
        
        
    public:
        TurnNeckToCenterNode();
        ~TurnNeckToCenterNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
