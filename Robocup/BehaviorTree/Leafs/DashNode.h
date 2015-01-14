//
//  DashNode.h
//  Ex3
//
//  Created by Maxim Vainshtein on 1/10/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

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
