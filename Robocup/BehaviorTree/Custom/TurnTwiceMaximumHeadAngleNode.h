/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Robocup__TurnTwiceMaximumHeadAngleNode__
#define __Robocup__TurnTwiceMaximumHeadAngleNode__

#include "SequenceNode.h"

namespace behavior {
    
    /************************************************************************************
     * TurnNeckNegativeNode Class: Perform a neck turn to a negative direction. Returns *
     *                             false if cant do that, True otherwise.               *
     ***********************************************************************************/
    
    class TurnTwiceMaximumHeadAngleNode : public SequenceNode {
        
    public:
        TurnTwiceMaximumHeadAngleNode();
        ~TurnTwiceMaximumHeadAngleNode();
        
        
    };
    
}

#endif 
