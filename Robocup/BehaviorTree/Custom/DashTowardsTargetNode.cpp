/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include "DashTowardsTargetNode.h"
#include "TurnTowardsTypeNode.h"
#include "PushTargetToStackNode.h"
#include "PopFromStackNode.h"
#include "SetTargetToNode.h"
#include "RepeatUntilSuccessNode.h"
#include "RepeatUntilFailNode.h"
#include "DashNode.h"
#include "EndActNode.h"
#include "SuccessNode.h"
#include "FailureNode.h"
#include "IsCloseToTargetNode.h"
#include "IsTargetVisibleNode.h"
#include "SuccessNode.h"
#include "InverterNode.h"
#include "WaitSeeStateUpdateNode.h"

#define NODE_NAME "DashTowardsTargetNode"

using namespace behavior;

DashTowardsTargetNode::DashTowardsTargetNode(int iDistance) {

    //Turn the body towards the ball
    addChild(new TurnTowardsTypeNode());
    
    //Dash towards the target
    SequenceNode *cSequence = new SequenceNode();
    cSequence->addChild(new IsTargetVisibleNode());
    cSequence->addChild(new DashNode());
    cSequence->addChild(new WaitSeeStateUpdateNode());
    cSequence->addChild(new EndActNode());
    cSequence->addChild(new IsTargetVisibleNode());
    cSequence->addChild(new InverterNode(new IsCloseToTargetNode(iDistance)));
    
    addChild(new InverterNode(new RepeatUntilFailNode(cSequence)));
    
}

DashTowardsTargetNode::~DashTowardsTargetNode() {
    
}
