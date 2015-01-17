//
//  TurnNode.cpp
//  Ex3
//
//  Created by Maxim Vainshtein on 1/10/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

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
        
#if DEBUG_PRINT_ERRORS

        std::cerr << TURN_NODE_TARGET_ERROR << std::endl;
        
#endif
        
        return StatusTypeFailure;
        
    }
    
    //Check if our target has an origin to move to
    const double *dValue = cTarget->getDoubleValue();
    
    //If no coordinate is given, return failed
    if (dValue == NULL) {
        
#if DEBUG_PRINT_ERRORS

        std::cerr << TURN_NODE_VALUE_ERROR << *cTarget << std::endl;
        
#endif
        
        return StatusTypeFailure;
        
    }
    
#if DEBUG_PRINT_ACTION
    
    //Print the action's description
    std::cout << DEBUG_ACTION_DESCRIPTION << std::endl;
    
#endif
    
    //Construct the instruction and send it to the brain
    Instruction *cInstruction = new Instruction();
    
    //Add the required input
    cInstruction->addCommand(TURN_NODE_COMMAND);
    cInstruction->addCommand(convertToString(*dValue));
    
    //Send the instruction to the brain
    perform(*cInstruction);
    
    return StatusTypeSuccess;
    
}
