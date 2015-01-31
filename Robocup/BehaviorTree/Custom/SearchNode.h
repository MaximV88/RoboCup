/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Robocup__SearchNode__
#define __Robocup__SearchNode__

#include "InverterNode.h"

namespace behavior {
    
    /****************************************************************************************
     * SearchNode Class: Recieves an input target (an ObservableType), and searches for     *
     *                   it. When found, it will populate the context's target with it's    *
     *                   Observable representation.                                         *
     ***************************************************************************************/
    
    class SearchNode : public InverterNode {
                
    public:
        SearchNode();
        ~SearchNode();
        
        
    };
    
}

#endif
