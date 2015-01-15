//
//  TurnNeckNegativeNode.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/15/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

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
