/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Robocup__TurnNeckPositiveNode__
#define __Robocup__TurnNeckPositiveNode__

#include "SequenceNode.h"

namespace behavior {
    
    /************************************************************************************
     * TurnNeckPositiveNode Class: Perform a neck turn to a positive direction. Returns *
     *                             false if cant do that, True otherwise.               *
     ***********************************************************************************/
    
    class TurnNeckPositiveNode : public SequenceNode {
        
    public:
        TurnNeckPositiveNode();
        ~TurnNeckPositiveNode();
        
        
    };
    
}

#endif
