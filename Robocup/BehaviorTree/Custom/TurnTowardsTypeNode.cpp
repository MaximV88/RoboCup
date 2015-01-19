//
//  TurnTowardsTypeNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/19/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "TurnTowardsTypeNode.h"
#include "SearchNode.h"
#include "SetTargetToNode.h"
#include "TurnNeckToCenterNode.h"
#include "TurnNode.h"
#include "WaitBodyStateUpdateNode.h"
#include "EndActNode.h"
#include "PushTargetToStackNode.h"
#include "PopFromStackNode.h"
#include "ChangeViewNode.h"

#define NODE_NAME "TurnTowardsTypeNode"

using namespace behavior;

TurnTowardsTypeNode::TurnTowardsTypeNode() {
    
    //Search for the current Target
    addChild(new SearchNode());
    
    //Turn the body to the target
    addChild(new TurnNode());
        
    //Rotate neck to center
    addChild(new TurnNeckToCenterNode());
    
    addChild(new PushTargetToStackNode());
    
    addChild(new SetTargetToNode(new BehaviorTarget(WidthTypeNarrow, QualityTypeHigh, NODE_NAME)));
    
    addChild(new ChangeViewNode());
    
    addChild(new PopFromStackNode());
    
    //Wait until there is a body update
    addChild(new WaitBodyStateUpdateNode());
    
    //Update variables and body state
    addChild(new EndActNode());
    
}

TurnTowardsTypeNode::~TurnTowardsTypeNode() {
    
}
