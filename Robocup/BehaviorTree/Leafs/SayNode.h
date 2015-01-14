//
//  SayNode.h
//  Ex3
//
//  Created by Maxim Vainshtein on 1/10/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Ex3__SayNode__
#define __Ex3__SayNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************************************
     * SayNode Class: This command broadcasts the Message through the field, and any player near        *
     *                enough (specified with audio cut dist, default: 50.0 meters), with enough         *
     *                hearing capacity will hear the Message. The message is a string of valid          *
     *                characters.                                                                       *
     ***************************************************************************************************/
    
    class SayNode : public BehaviorTreeNode {
        
        
    public:
        SayNode();
        ~SayNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
