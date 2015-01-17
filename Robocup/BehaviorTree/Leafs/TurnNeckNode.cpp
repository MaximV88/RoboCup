//
//  TurnNeckNode.cpp
//  Ex3
//
//  Created by Maxim Vainshtein on 1/10/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

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
        
        std::cerr << TURNNECK_NODE_TARGET_ERROR << std::endl;
        return StatusTypeFailure;
        
    }
    
    //Check if our target has an origin to move to
    const double *dValue = cTarget->getDoubleValue();
    
    //If no coordinate is given, return failed
    if (dValue == NULL) {
        
        std::cerr << TURNNECK_NODE_VALUE_ERROR << *cTarget << std::endl;
        return StatusTypeFailure;
        
    }
    
#if DEBUG_PRINT_ACTION
    
    //Print the action's description
    std::cout << DEBUG_ACTION_DESCRIPTION << std::endl;
    
#endif
    
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
