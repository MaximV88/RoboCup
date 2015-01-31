/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include "TurnTwiceMaximumHeadAngleNode.h"
#include "SetTargetToTwiceMaximumHeadAngleNode.h"
#include "PushTargetToStackNode.h"
#include "PopFromStackNode.h"
#include "TurnNode.h"
#include "EndActNode.h"
#include "SuccessNode.h"
#include "WaitBodyStateUpdateNode.h"

using namespace behavior;

TurnTwiceMaximumHeadAngleNode::TurnTwiceMaximumHeadAngleNode() {
    
    //Push the current target to the stack - dont care if there is a target
    addChild(new SuccessNode(new PushTargetToStackNode()));
    
    //Set the value for neck rotation as target
    addChild(new SetTargetToTwiceMaximumHeadAngleNode());
    
    //Perform the rotation
    addChild(new TurnNode());
    
    //Pop the original target back - dont care if there isnt a target
    addChild(new SuccessNode(new PopFromStackNode()));
    
    //Wait until there is a body update
    addChild(new WaitBodyStateUpdateNode());
    
    //Update variables and body state
    addChild(new EndActNode());
    
}

TurnTwiceMaximumHeadAngleNode::~TurnTwiceMaximumHeadAngleNode() {
    
}
