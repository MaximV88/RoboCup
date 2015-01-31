/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

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
    
    //Print the action's description
    DebugLogVerbose(DEBUG_ACTION_DESCRIPTION);
    
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
