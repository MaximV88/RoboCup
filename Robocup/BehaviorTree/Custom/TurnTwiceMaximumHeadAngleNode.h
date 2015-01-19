//
//  TurnTwiceMaximumHeadAngleNode.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/19/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

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
