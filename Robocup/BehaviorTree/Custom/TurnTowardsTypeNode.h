//
//  TurnTowardsTypeNode.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/19/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Robocup__TurnTowardsTypeNode__
#define __Robocup__TurnTowardsTypeNode__

#include "SequenceNode.h"

namespace behavior {
    
    /************************************************************************************
     * TurnTowardsTypeNode Class: Turns the body towards a Target type. Also, as a      *
     *                            result the Target is populated by the type's          *
     *                            Observable information.                               *
     ***********************************************************************************/
    
    class TurnTowardsTypeNode : public SequenceNode {
        
    public:
        TurnTowardsTypeNode();
        ~TurnTowardsTypeNode();
        
        
    };
    
}

#endif 
