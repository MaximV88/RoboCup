/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Robocup__TurnNeckNegativeNode__
#define __Robocup__TurnNeckNegativeNode__

#include "SequenceNode.h"

namespace behavior {
    
    /************************************************************************************
     * TurnNeckNegativeNode Class: Perform a neck turn to a negative direction. Returns *
     *                             false if cant do that, True otherwise.               *
     ***********************************************************************************/
    
    class TurnNeckNegativeNode : public SequenceNode {
        
    public:
        TurnNeckNegativeNode();
        ~TurnNeckNegativeNode();
        
        
    };
    
}

#endif
