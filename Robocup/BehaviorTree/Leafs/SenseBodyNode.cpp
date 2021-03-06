/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include "SenseBodyNode.h"
#include "BehaviorContext.h"
#include "Brain.h"
#include "Player.h"

#define SENSE_BODY_NODE_COMMAND "sense_body"

#define DEBUG_ACTION_DESCRIPTION "Sensing the Body."

using namespace behavior;

SenseBodyNode::SenseBodyNode() {
    
}

SenseBodyNode::~SenseBodyNode() {
    
}

StatusType SenseBodyNode::process() {
    
    //Print the action's description
    DebugLogVerbose(DEBUG_ACTION_DESCRIPTION);
    
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
