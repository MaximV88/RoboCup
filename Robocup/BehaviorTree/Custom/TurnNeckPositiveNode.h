//
//  TurnNeckPositiveNode.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/15/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

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
