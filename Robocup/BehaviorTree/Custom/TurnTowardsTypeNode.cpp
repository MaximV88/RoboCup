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
#include "WaitSeeStateUpdateNode.h"
#include "PushTargetToStackNode.h"
#include "PopFromStackNode.h"
#include "ChangeViewNode.h"
#include "TurnNeckNode.h"
#include "IsTurnedOnTargetNode.h"
#include "RepeatUntilFailNode.h"
#include "SuccessNode.h"

#define NODE_NAME "TurnTowardsTypeNode"

using namespace behavior;

TurnTowardsTypeNode::TurnTowardsTypeNode() {
    
    //Search and turn for the current Target    
    SequenceNode *cSequence = new SequenceNode();
    cSequence->addChild(new SearchNode());
    cSequence->addChild(new InverterNode(new IsTurnedOnTargetNode(2)));
    cSequence->addChild(new TurnNode());
    cSequence->addChild(new TurnNeckToCenterNode());
    cSequence->addChild(new WaitSeeStateUpdateNode());
    cSequence->addChild(new WaitBodyStateUpdateNode());
    cSequence->addChild(new EndActNode());
    addChild(new SuccessNode(new RepeatUntilFailNode(cSequence)));

    
    addChild(new SuccessNode(new PushTargetToStackNode()));
    addChild(new SetTargetToNode(new BehaviorTarget(WidthTypeNarrow, QualityTypeHigh, NODE_NAME)));
    addChild(new ChangeViewNode());
    addChild(new SuccessNode(new PopFromStackNode()));
    
    //Update variables and body state
    addChild(new EndActNode());
    
}

TurnTowardsTypeNode::~TurnTowardsTypeNode() {
    
}
