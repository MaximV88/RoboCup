//
//  TurnNode.h
//  Ex3
//
//  Created by Maxim Vainshtein on 1/10/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Ex3__TurnNode__
#define __Ex3__TurnNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************************************
     * TurnNode Class:        This command will turn the player’s body direction Moment                 *
     *                        degrees relative to the current direction. Turns towards the Observable   *
     *                        set in the Target. Otherwise if not present, turns toward the Double value*
     ***************************************************************************************************/

    class TurnNode : public BehaviorTreeNode {
        
        
    public:
        TurnNode();
        ~TurnNode();
    
        virtual StatusType process();

    };
    
}

#endif
