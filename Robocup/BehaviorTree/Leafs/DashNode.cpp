//
//  DashNode.cpp
//  Ex3
//
//  Created by Maxim Vainshtein on 1/10/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>
#include "DashNode.h"
#include "Brain.h"

#define DASH_NODE_COMMAND "dash"
#define DASH_NODE_TARGET_ERROR "DashNode Error: No Target given"
#define DASH_NODE_VALUE_ERROR "DashNode Error: No int value given in the "

#define DEBUG_ACTION_DESCRIPTION "Dashing the Player."

using namespace behavior;

DashNode::DashNode() {
    
    
}

DashNode::~DashNode() {
    
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

StatusType DashNode::process() {

    //Add the required input from the target
    BehaviorTarget *cTarget = getContext().getCurrentTarget();
    
    //If no target is present, return failed
    if (cTarget == NULL) {
        
        std::cerr << DASH_NODE_TARGET_ERROR << std::endl;
        return StatusTypeFailure;
        
    }
    
    //Check if our target has an origin to move to
    const int *iValue = cTarget->getIntValue();
    
    //If no coordinate is given, return failed
    if (iValue == NULL) {
        
        std::cerr << DASH_NODE_VALUE_ERROR << *cTarget << std::endl;
        return StatusTypeFailure;
        
    }
    
#if DEBUG_PRINT_ACTION
    
    //Print the action's description
    std::cout << DEBUG_ACTION_DESCRIPTION << std::endl;
    
#endif
    
    //Construct the instruction and send it to the brain
    Instruction *cInstruction = new Instruction();
    
    //Add the required input
    cInstruction->addCommand(DASH_NODE_COMMAND);
    cInstruction->addCommand(convertToString(*iValue));
    
    //Send the instruction to the brain
    perform(*cInstruction);
    
    return StatusTypeSuccess;
    
}
