/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include <iostream>
#include <sstream>
#include <string>
#include <iostream>
#include "MoveNode.h"
#include "Brain.h"
#include "Player.h"

#define MOVE_NODE_COMMAND "move"
#define MOVE_NODE_PLAYMODE_ERROR "MoveNode Error: No compatible PlayMode for moving"
#define MOVE_NODE_TARGET_ERROR "MoveNode Error: No Target given"
#define MOVE_NODE_COORDINATE_ERROR "MoveNode Error: No Coordinate given in the "

#define DEBUG_ACTION_DESCRIPTION "Moving the Player."

using namespace behavior;

MoveNode::MoveNode() {
    
}

MoveNode::~MoveNode() {
    
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

StatusType MoveNode::process() {
    
    //Get the TeamState and check if it allows for Move commands
    const TeamState* cState = getContext().getPlayer().getLastTeamState();
    
    //Fail silently
    if (cState == NULL)
        return StatusTypeFailure;
    
    //Cannot move when in PlayOn mode
    if (cState->playMode == PlayModePlayOn) {
        
        //Print error and return
        DebugLogError(MOVE_NODE_PLAYMODE_ERROR);
        
        //Delete after usage
        delete cState;
        
        return StatusTypeFailure;
        
    }

    //Add the required input from the target
    BehaviorTarget *cTarget = getContext().getCurrentTarget();
    
    //If no target is present, return failed
    if (cTarget == NULL) {

        //Print error and return
        DebugLogError(MOVE_NODE_TARGET_ERROR);
        
        //Delete after usage
        delete cState;
        
        return StatusTypeFailure;
    
    }
    
    //Check if our target has an origin to move to
    const Coordinate *cCoordinate = cTarget->getOrigin();
    
    //If no coordinate is given, return failed
    if (cCoordinate == NULL) {
     

        //Print error and return
        DebugLogError(MOVE_NODE_COORDINATE_ERROR << *cTarget);
        
        //Delete after usage
        delete cState;
        
        return StatusTypeFailure;
        
    }
    
    DebugLogVerbose(DEBUG_ACTION_DESCRIPTION);
    
    //Construct the instruction and send it to the brain
    Instruction *cInstruction = new Instruction();
    
    cInstruction->addCommand(MOVE_NODE_COMMAND);
    cInstruction->addCommand(convertToString(cCoordinate->getX()));
    cInstruction->addCommand(convertToString(cCoordinate->getY()));
    
    //Send the instruction to the brain
    perform(*cInstruction);
    
    //Delete after usage
    delete cState;
    
    return StatusTypeSuccess;
    
}
