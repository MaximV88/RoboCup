/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include <iostream>
#include <sstream>
#include <string>
#include "DashNode.h"
#include "Brain.h"
#include "Player.h"

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
       
        //Print error and return
        DebugLogError(DASH_NODE_TARGET_ERROR);
        return StatusTypeFailure;
        
    }
    
    //Check if our target has an origin to move to
    const int *iValue = cTarget->getIntValue();
    const int *tValue = NULL;
    
    ServerState *cState = getContext().getPlayer().getLastServerState();
    
    //If no coordinate is given, return failed
    if (iValue == NULL) {
        
        tValue = new int(cState->maxPower);
        
        //Aliase...
        iValue = tValue;
        
    }
    
    //Print the action's description
    DebugLogVerbose(DEBUG_ACTION_DESCRIPTION);
    
    //Construct the instruction and send it to the brain
    Instruction *cInstruction = new Instruction();
    
    //Add the required input
    cInstruction->addCommand(DASH_NODE_COMMAND);
    cInstruction->addCommand(convertToString(*iValue));
    
    //Send the instruction to the brain
    perform(*cInstruction);
    
    if (tValue != NULL)
        delete tValue;
    
    delete cState;
    
    return StatusTypeSuccess;
    
}
