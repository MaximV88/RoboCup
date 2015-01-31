/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include "TurnNeckNegativeNode.h"
#include "PushTargetToStackNode.h"
#include "SetTargetToNegativeNeckTurnAngleNode.h"
#include "TurnNeckNode.h"
#include "PopFromStackNode.h"
#include "EndActNode.h"
#include "SuccessNode.h"
#include "WaitBodyStateUpdateNode.h"
#include "WaitSeeStateUpdateNode.h"

using namespace behavior;

TurnNeckNegativeNode::TurnNeckNegativeNode() {
    
    //Push the current target to the stack - dont care if there is a target
    addChild(new SuccessNode(new PushTargetToStackNode()));
    
    //Set the value for neck rotation as target
    addChild(new SetTargetToNegativeNeckTurnAngleNode());
    
    //Perform the rotation
    addChild(new TurnNeckNode());
    
    //Pop the original target back - dont care if there isnt a target
    addChild(new SuccessNode(new PopFromStackNode()));
        
    //Wait until there is a body update
    addChild(new WaitSeeStateUpdateNode());
    
    //Update variables and body state
    addChild(new EndActNode());
    
}

TurnNeckNegativeNode::~TurnNeckNegativeNode() {
    
}
