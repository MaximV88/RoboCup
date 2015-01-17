//
//  ScoreNode.cpp
//  Ex3
//
//  Created by Maxim Vainshtein on 1/10/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "ScoreNode.h"
#include "Brain.h"

#define SCORE_NODE_COMMAND "score"

#define DEBUG_ACTION_DESCRIPTION "Finding out the Score."

using namespace behavior;

ScoreNode::ScoreNode() {
    
}

ScoreNode::~ScoreNode() {
    
}

StatusType ScoreNode::process() {
    
#if DEBUG_PRINT_ACTION
    
    //Print the action's description
    std::cout << DEBUG_ACTION_DESCRIPTION << std::endl;
    
#endif
    
    //Construct the instruction and send it to the brain
    Instruction *cInstruction = new Instruction();
    
    //Add the required input
    cInstruction->addCommand(SCORE_NODE_COMMAND);
    
    //Can be attached to other instructions (not unique per cycle)
    cInstruction->setAttachable(true);
    
    //Send the instruction to the brain
    perform(*cInstruction);
    
    return StatusTypeSuccess;
    
}
