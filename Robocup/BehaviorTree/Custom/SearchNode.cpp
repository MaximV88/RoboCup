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
#include "Player.h"

using namespace behavior;

SearchNode::SearchNode() {
    
    //  -----   FIRST SEQUENCE ----- //
    
    
    /********************************************
     * Checks if the target is visible, if not  *
     * changes the view settings for search.    *
     *******************************************/

    SequenceNode *cFirstSequence = new SequenceNode();
    
    /*
     * First check if the object is already visible.
     * if not continue the sequence, otherwise
     * stop the sequence once found. For the sequence to
     * continue, a successful answer must be received from
     * not seeing the target. We will use an Inverter.
     */
    
    InverterNode *cInvert = new InverterNode(new IsTargetVisibleNode());
    cFirstSequence->addChild(cInvert);
    
    /*
     * When searching, first we need to change the view quality to low,
     * and the width angle to wide. Because we are searching
     * for a specific target in context, we save it onto
     * the stack, load our target, pop the stack and continue.
     */
    
    //Push the current target to the stack
    cFirstSequence->addChild(new PushTargetToStackNode());
    
    //Create our required target for view changing
    cFirstSequence->addChild(new SetTargetToNode(new BehaviorTarget(WidthTypeWide, QualityTypeLow)));
    
    //Change the view
    cFirstSequence->addChild(new ChangeViewNode());
    
    //Pop the previous target back to the context
    cFirstSequence->addChild(new PopFromStackNode());
    
    //Call the EndAct node to update the view settings
    cFirstSequence->addChild(new EndActNode());
    
    
    //  -----   SECOND SEQUENCE ----- //

    
    /********************************************
     *  Rotate the head - check center,         *
     *  left and right.                         *
     *******************************************/
    
    
}

SearchNode::~SearchNode() {
    
}