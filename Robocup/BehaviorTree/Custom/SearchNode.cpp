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
#include "Player.h"

using namespace behavior;

SearchNode::SearchNode() {
    
    /*
     * When searching, first we need to change the view quality to low,
     * and the width angle to wide. Because we are searching
     * for a specific target in context, we save it onto
     * the stack, load our target, pop the stack and continue.
     */
    
    //First check if the object is already visible
    
    //Push the current target to the stack
    addChild(new PushTargetToStackNode());
    
    //Create our required target for view changing
    addChild(new SetTargetToNode(new BehaviorTarget(WidthTypeWide, QualityTypeLow)));
    
    //Pop the previous target back to the context
    addChild(new PopFromStackNode());
    
    
    
    
}

SearchNode::~SearchNode() {
    
}