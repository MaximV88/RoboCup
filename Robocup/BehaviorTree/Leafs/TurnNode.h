/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

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
