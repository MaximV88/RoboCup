//
//  SearchNode.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/14/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Robocup__SearchNode__
#define __Robocup__SearchNode__

#include "InverterNode.h"

namespace behavior {
    
    /****************************************************************************************
     * SearchNode Class: Recieves an input target (an ObservableType), and searches for     *
     *                   it. When found, it will populate the context's stack with it's     *
     *                   coordinate, direction from player, and direction vector.           *
     ***************************************************************************************/
    
    class SearchNode : public InverterNode {
                
    public:
        SearchNode();
        ~SearchNode();
        
        
    };
    
}

#endif
