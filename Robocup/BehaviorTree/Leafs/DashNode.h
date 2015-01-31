/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Ex3__DashNode__
#define __Ex3__DashNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************************************
     * DashNode Class:        This command accelerates the player in the direction of its body          *
     *                        (not direction of the current speed). The Power is between minpower       *
     *                        and maxpower.                                                             *
     ***************************************************************************************************/

    class DashNode : public BehaviorTreeNode {
        
    public:
        DashNode();
        ~DashNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
