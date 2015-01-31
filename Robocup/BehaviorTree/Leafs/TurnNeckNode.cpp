/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include <iostream>
#include <sstream>
#include <string>
#include "TurnNeckNode.h"
#include "Brain.h"

#define TURNNECK_NODE_COMMAND "turn_neck"
#define TURNNECK_NODE_TARGET_ERROR "TurnNeckNode Error: No Target given"
#define TURNNECK_NODE_VALUE_ERROR "TurnNeckNode Error: No double value given in the "

#define DEBUG_ACTION_DESCRIPTION "Turning the Neck."

using namespace behavior;

TurnNeckNode::TurnNeckNode() {
    
}

TurnNeckNode::~TurnNeckNode() {
    
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

StatusType TurnNeckNode::process() {
    
    //Add the required input from the target
    BehaviorTarget *cTarget = getContext().getCurrentTarget();
    
    //If no target is present, return failed
    if (cTarget == NULL) {
        
        //Print error and return
        DebugLogError(TURNNECK_NODE_TARGET_ERROR);
        return StatusTypeFailure;
        
    }
    
    const Observable *cObservable = cTarget->getObservable();
    
    if (cObservable != NULL) {
        
        //Construct the instruction and send it to the brain
        Instruction *cInstruction = new Instruction();
        
        //Add the required input
        cInstruction->addCommand(TURNNECK_NODE_COMMAND);
        cInstruction->addCommand(convertToString(cObservable->direction));
        
        //Can be attached to other instructions (not unique per cycle)
        cInstruction->setAttachable(true);
        
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
        DebugLogError(TURNNECK_NODE_VALUE_ERROR << *cTarget);
        return StatusTypeFailure;
        
    }
    
    //Print the action's description
    DebugLogVerbose(DEBUG_ACTION_DESCRIPTION);
    
    //Construct the instruction and send it to the brain
    Instruction *cInstruction = new Instruction();
    
    //Add the required input
    cInstruction->addCommand(TURNNECK_NODE_COMMAND);
    cInstruction->addCommand(convertToString(*dValue));
    
    //Can be attached to other instructions (not unique per cycle)
    cInstruction->setAttachable(true);
    
    //Send the instruction to the brain
    perform(*cInstruction);
    
    return StatusTypeSuccess;
    
}
