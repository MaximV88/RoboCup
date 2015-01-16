//
//  TurnMaximumMomentNode.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/16/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Robocup__TurnMaximumMomentNode__
#define __Robocup__TurnMaximumMomentNode__

#include "SequenceNode.h"

namespace behavior {
    
    /************************************************************************************
     * TurnNeckNegativeNode Class: Perform a neck turn to a negative direction. Returns *
     *                             false if cant do that, True otherwise.               *
     ***********************************************************************************/
    
    class TurnMaximumMomentNode : public SequenceNode {
        
    public:
        TurnMaximumMomentNode();
        ~TurnMaximumMomentNode();
        
        
    };
    
}

#endif
