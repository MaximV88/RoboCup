//
//  CatchBallNode.cpp
//  Ex3
//
//  Created by Maxim Vainshtein on 1/10/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>
#include "CatchBallNode.h"
#include "Brain.h"

#define CATCHBALL_NODE_COMMAND "catch"
#define CATCHBALL_NODE_TARGET_ERROR "CatchBallNode Error: No Target given"
#define CATCHBALL_NODE_VALUE_ERROR "CatchBallNode Error: No double value given in the "

#define DEBUG_ACTION_DESCRIPTION "Catching the Ball."

using namespace behavior;

CatchBallNode::CatchBallNode() {
    
}

CatchBallNode::~CatchBallNode() {
    
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

StatusType CatchBallNode::process() {
    
    //Add the required input from the target
    BehaviorTarget *cTarget = getContext().getCurrentTarget();
    
    //If no target is present, return failed
    if (cTarget == NULL) {

        //Print error and return
        DebugLogError(CATCHBALL_NODE_TARGET_ERROR);
        return StatusTypeFailure;
        
    }
    
    //Check if our target has an origin to move to
    const double *dValue = cTarget->getDoubleValue();
    const Observable *cObservable = cTarget->getObservable();

    //If no coordinate is given, return failed
    if (dValue == NULL && cObservable == NULL) {
        
        //Print error and return
        DebugLogError(CATCHBALL_NODE_VALUE_ERROR << *cTarget);
        return StatusTypeFailure;
        
    }
    
    //Override the direction if present
    if (cObservable != NULL)
        dValue = &cObservable->direction;
    
    //Print the action's description
    DebugLogVerbose(DEBUG_ACTION_DESCRIPTION);
    
    //Construct the instruction and send it to the brain
    Instruction *cInstruction = new Instruction();
    
    //Add the required input
    cInstruction->addCommand(CATCHBALL_NODE_COMMAND);
    cInstruction->addCommand(convertToString(*dValue));
    
    //Send the instruction to the brain
    perform(*cInstruction);
    
    return StatusTypeSuccess;
    
}
