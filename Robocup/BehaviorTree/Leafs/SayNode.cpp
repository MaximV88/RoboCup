//
//  SayNode.cpp
//  Ex3
//
//  Created by Maxim Vainshtein on 1/10/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "SayNode.h"
#include "Brain.h"

#define SAY_NODE_COMMAND "say"
#define SAY_NODE_TARGET_ERROR "SayNode Error: No Target given"
#define SAY_NODE_VALUE_ERROR "SayNode Error: No C string given in the Target"

using namespace behavior;

SayNode::SayNode() {
    
}

SayNode::~SayNode() {
    
}

StatusType SayNode::process() {
    
    //Add the required input from the target
    BehaviorTarget *cTarget = getContext().getCurrentTarget();
    
    //If no target is present, return failed
    if (cTarget == NULL) {
        
        std::cerr << SAY_NODE_TARGET_ERROR << std::endl;
        return StatusTypeFailure;
        
    }
    
    //Check if our target has an origin to move to
    const char *chMessage = cTarget->getCStringValue();
    
    //If no coordinate is given, return failed
    if (chMessage == NULL) {
        
        std::cerr << SAY_NODE_VALUE_ERROR << std::endl;
        return StatusTypeFailure;
        
    }
    
    //Construct the instruction and send it to the brain
    Instruction *cInstruction = new Instruction();
    
    //Add the required input
    cInstruction->addCommand(SAY_NODE_COMMAND);
    cInstruction->addCommand(chMessage);
    
    //Can be attached to other instructions (not unique per cycle)
    cInstruction->setAttachable(true);
    
    //Send the instruction to the brain
    perform(*cInstruction);
    
    return StatusTypeSuccess;
    
}
