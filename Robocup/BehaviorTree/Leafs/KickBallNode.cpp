//
//  KickBallNode.cpp
//  Ex3
//
//  Created by Maxim Vainshtein on 1/10/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>
#include "KickBallNode.h"
#include "Brain.h"

#define KICKBALL_NODE_COMMAND "kick"
#define KICKBALL_NODE_TARGET_ERROR "KickBallNode Error: No Target given"
#define KICKBALL_NODE_INT_VALUE_ERROR "KickBallNode Error: No int value given in the "
#define KICKBALL_NODE_DOUBLE_VALUE_ERROR "KickBallNode Error: No double value given in the "

#define DEBUG_ACTION_DESCRIPTION "Kicking the Ball."

using namespace behavior;

KickBallNode::KickBallNode() {
    
}

KickBallNode::~KickBallNode() {
    
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

StatusType KickBallNode::process() {
    
    //Add the required input from the target
    BehaviorTarget *cTarget = getContext().getCurrentTarget();
    
    //If no target is present, return failed
    if (cTarget == NULL) {
        
        std::cerr << KICKBALL_NODE_TARGET_ERROR << std::endl;
        return StatusTypeFailure;
        
    }
    
    //Check if our target has an origin to move to
    const int *iValue = cTarget->getIntValue();
    
    //If no coordinate is given, return failed
    if (iValue == NULL) {
        
        std::cerr << KICKBALL_NODE_INT_VALUE_ERROR << *cTarget << std::endl;
        return StatusTypeFailure;
        
    }
    
    const double* dValue = cTarget->getDoubleValue();
    
    //If no coordinate is given, return failed
    if (dValue == NULL) {
        
        std::cerr << KICKBALL_NODE_DOUBLE_VALUE_ERROR << *cTarget << std::endl;
        return StatusTypeFailure;
        
    }
    
#if DEBUG_PRINT_ACTION
    
    //Print the action's description
    std::cout << DEBUG_ACTION_DESCRIPTION << std::endl;
    
#endif
    
    //Construct the instruction and send it to the brain
    Instruction *cInstruction = new Instruction();
    
    //Add the required input
    cInstruction->addCommand(KICKBALL_NODE_COMMAND);
    cInstruction->addCommand(convertToString(*iValue));
    cInstruction->addCommand(convertToString(*dValue));
    
    //Send the instruction to the brain
    perform(*cInstruction);
    
    return StatusTypeSuccess;
    
}
