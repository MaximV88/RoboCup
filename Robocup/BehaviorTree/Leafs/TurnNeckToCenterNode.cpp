/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include <string>
#include <iostream>
#include <sstream>
#include "TurnNeckToCenterNode.h"
#include "Player.h"

#define TURN_NECK_TO_CENTER_NODE_COMMAND "turn_neck"

#define DEBUG_ACTION_DESCRIPTION "Centering the Neck."

using namespace behavior;

TurnNeckToCenterNode::TurnNeckToCenterNode() {
    
}

TurnNeckToCenterNode::~TurnNeckToCenterNode() {
    
}


/****************************************************************************************************
 * function name: convertToString                                                                   *
 * The Input: T type (template)                                                                     *
 * The output: string                                                                               *
 * The Function Opertion: Returns the string version of the input type.                             *
 * *************************************************************************************************/

template <typename T>
inline std::string convertToString(T tType) {
    
    std::ostringstream oss;
    
    oss << tType;
    
    // Return the resulting string
    return oss.str();
    
}

StatusType TurnNeckToCenterNode::process() {
    
    //Check if valid for calculation
    BodyState *cState = getContext().getPlayer().getLastBodyState();
    
    if (cState == NULL)
        return StatusTypeFailure;
    
    //Get the value needed to turn to center
    double dRotation = cState->headAngle;
    
    //Print the action's description
    DebugLogVerbose(DEBUG_ACTION_DESCRIPTION);
    
    //No need to rotate
    if (dRotation == 0) {
        
        //Delete after usage
        delete cState;
        
        return StatusTypeSuccess;
        
    }
    
    //Construct the instruction and send it to the brain
    Instruction *cInstruction = new Instruction();
    
    //Add the required input
    cInstruction->addCommand(TURN_NECK_TO_CENTER_NODE_COMMAND);
    cInstruction->addCommand(convertToString(-dRotation));
    
    //Can be attached to other instructions (not unique per cycle)
    cInstruction->setAttachable(true);
    
    //Send the instruction to the brain
    perform(*cInstruction);
    
    //Delete after usage
    delete cState;
    
    return StatusTypeSuccess;
    
}
