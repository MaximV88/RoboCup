//
//  SearchNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/14/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "SearchNode.h"
#include "ChangeViewNode.h"
#include "PushTargetToStackNode.h"
#include "PopFromStackNode.h"
#include "SetTargetToNode.h"
#include "IsTargetVisibleNode.h"
#include "InverterNode.h"
#include "EndActNode.h"
#include "ExecuteActNode.h"
#include "Player.h"
#include "SearchTurnNeckNode.h"
#include "RepeatUntilFailNode.h"
#include "TurnMaximumMomentNode.h"
#include "SuccessNode.h"
#include "Player.h"

#define NODE_NAME "SearchNode"

using namespace behavior;

SearchNode::SearchNode() : InverterNode(new SequenceNode()) {
    
    //Take the existing child into a pointer
    SequenceNode *cCheckingSequence = static_cast<SequenceNode*>(&getChild());
    
    /********************************************
     * Checks if the target is visible, if not  *
     * changes the view settings for search.    *
     *******************************************/
    
    /*
     * First check if the object is already visible.
     * if not continue the sequence, otherwise
     * stop the sequence once found. For the sequence to
     * continue, a successful answer must be received from
     * not seeing the target. We will use an Inverter.
     */
        
    InverterNode *cInvert = new InverterNode(new IsTargetVisibleNode());
    cCheckingSequence->addChild(cInvert);
    
    /*
     * When searching, first we need to change the view quality to low,
     * and the width angle to wide. Because we are searching
     * for a specific target in context, we save it onto
     * the stack, load our target, pop the stack and continue.
     */
    
    //Push the current target to the stack - dont care if there isnt a target
    cCheckingSequence->addChild(new SuccessNode(new PushTargetToStackNode()));
    
    //Create our required target for view changing
    cCheckingSequence->addChild(new SetTargetToNode(new BehaviorTarget(WidthTypeNarrow, QualityTypeHigh, NODE_NAME)));
    
    //Change the view
    cCheckingSequence->addChild(new ChangeViewNode());
    
    //Pop the previous target back to the context - dont care if there isnt a target
    cCheckingSequence->addChild(new SuccessNode(new PopFromStackNode()));
    
    //Call the EndAct node to update the view settings
    cCheckingSequence->addChild(new ExecuteActNode());
    
    
    /*
     * This next section will be repeated 
     * until the target is found.
     */
    
    SequenceNode *cSequence = new SequenceNode();
    
    /********************************************
     *  Rotate the head - check center,         *
     *  left and right.                         *
     *******************************************/
    
    cSequence->addChild(new InverterNode(new SearchTurnNeckNode()));
    
    /********************************************
     *  Turn the body, and check again. The     *
     *  turning of the body is decided by       *
     *  the maximum angle.                      *
     *******************************************/
    
    cSequence->addChild(new TurnMaximumMomentNode());
    
    //Implement the repeater
    cCheckingSequence->addChild(new RepeatUntilFailNode(cSequence));
        
}

SearchNode::~SearchNode() {
    
}
