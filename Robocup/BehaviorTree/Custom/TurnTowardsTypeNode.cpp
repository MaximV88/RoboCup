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
#include "TurnNeckNode.h"
#include "IsTurnedOnTargetNode.h"
#include "RepeatUntilFailNode.h"

#define NODE_NAME "TurnTowardsTypeNode"

using namespace behavior;

TurnTowardsTypeNode::TurnTowardsTypeNode() {
    
    //Search for the current Target
    addChild(new SearchNode());
    
    //Rotate neck to center
    addChild(new TurnNeckToCenterNode());
    
    SequenceNode *cSequence = new SequenceNode();
    cSequence->addChild(new InverterNode(new IsTurnedOnTargetNode()));
    cSequence->addChild(new TurnNode());
    addChild(new RepeatUntilFailNode(cSequence));
    
    //Turn the body to the target
    addChild(new TurnNode());
    
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
