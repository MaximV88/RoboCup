//
//  SenseBodyNode.cpp
//  Ex3
//
//  Created by Maxim Vainshtein on 1/10/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "SenseBodyNode.h"
#include "BehaviorContext.h"
#include "Brain.h"

#define SENSE_BODY_NODE_COMMAND "sense_body"

using namespace behavior;

SenseBodyNode::SenseBodyNode() {
    
}

SenseBodyNode::~SenseBodyNode() {
    
}

StatusType SenseBodyNode::process() {

    //Construct the instruction and send it to the brain
    Instruction *cInstruction = new Instruction();
    
    //Add the required input
    cInstruction->addCommand(SENSE_BODY_NODE_COMMAND);
    
    //Can be attached to other instructions (not unique per cycle)
    cInstruction->setAttachable(true);
    
    //Send the instruction to the brain
    perform(*cInstruction);
    
    return StatusTypeSuccess;
    
}
