/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include <iostream>
#include <sstream>
#include <string>
#include "TurnNode.h"
#include "Brain.h"

#define TURN_NODE_COMMAND "turn"
#define TURN_NODE_TARGET_ERROR "TurnNode Error: No Target given"
#define TURN_NODE_VALUE_ERROR "TurnNode Error: No double value given in the "

#define DEBUG_ACTION_DESCRIPTION "Turning the Player."

using namespace behavior;

TurnNode::TurnNode() {
    
}

TurnNode::~TurnNode() {
    
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

StatusType TurnNode::process() {
    
    //Add the required input from the target
    BehaviorTarget *cTarget = getContext().getCurrentTarget();
    
    //If no target is present, return failed
    if (cTarget == NULL) {
        
        //Print error and return
        DebugLogError(TURN_NODE_TARGET_ERROR);
        return StatusTypeFailure;
        
    }
    
    const Observable *cObservable = cTarget->getObservable();
    
    if (cObservable != NULL) {
        
        //Construct the instruction and send it to the brain
        Instruction *cInstruction = new Instruction();
        
        //Add the required input
        cInstruction->addCommand(TURN_NODE_COMMAND);
        cInstruction->addCommand(convertToString(cObservable->direction));
        
        //Send the instruction to the brain
        perform(*cInstruction);
        
        //It ends here
        return StatusTypeSuccess;
        
    }
    
    //Check if our target has an origin to move to
    const double *dValue = cTarget->getDoubleValue();
    
    //If no coordinate is given, return failed
    if (dValue == NULL) {
        
        //Print error and return
        DebugLogError(TURN_NODE_VALUE_ERROR << *cTarget);
        return StatusTypeFailure;
        
    }
    
    //Print the action's description
    DebugLogVerbose(DEBUG_ACTION_DESCRIPTION);
    
    //Construct the instruction and send it to the brain
    Instruction *cInstruction = new Instruction();
    
    //Add the required input
    cInstruction->addCommand(TURN_NODE_COMMAND);
    cInstruction->addCommand(convertToString(*dValue));
    
    //Send the instruction to the brain
    perform(*cInstruction);
    
    return StatusTypeSuccess;
    
}
