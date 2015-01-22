//
//  IsTurnedOnTargetNode.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/21/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Robocup__IsTurnedOnTargetNode__
#define __Robocup__IsTurnedOnTargetNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************************************
     * TurnNode Class:        This command will turn the player’s body direction Moment                 *
     *                        degrees relative to the current direction. Updates the Target's           *
     *                        Observable pointer.                                                       *
     ***************************************************************************************************/
    
    class IsTurnedOnTargetNode : public BehaviorTreeNode {
        
    public:
        IsTurnedOnTargetNode();
        ~IsTurnedOnTargetNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
