/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include "SetTargetToOpponentGoalNode.h"
#include "Player.h"

#define NODE_NAME "SetTargetToOpponentGoalNode"

#define DEBUG_ACTION_DESCRIPTION_SUCCESS "Successfuly set opponent side as Target type"

using namespace behavior;

SetTargetToOpponentGoalNode::SetTargetToOpponentGoalNode() {
    
}

SetTargetToOpponentGoalNode::~SetTargetToOpponentGoalNode() {
    
}

StatusType SetTargetToOpponentGoalNode::process() {
    
    TeamState *cTeamState = getContext().getPlayer().getLastTeamState();
    
    //Check if valid for calculation
    if (cTeamState == NULL)
        return StatusTypeFailure;

    //Check if opponent goal visible
    ObservableType eOpponentGoal;
    
    switch (cTeamState->teamSide) {
        case TeamSideLeft:
            eOpponentGoal = ObservableTypeGoalRight;
            break;
            
        case TeamSideRight:
            eOpponentGoal = ObservableTypeGoalLeft;
            break;
            
        default:
            break;
    }
    
    //Set the rotation as the target
    getContext().setCurrentTarget(new BehaviorTarget(eOpponentGoal, NODE_NAME));
    
    //Print the action's description
    DebugLogVerbose(DEBUG_ACTION_DESCRIPTION_SUCCESS);
    
    //Delete after usage
    delete cTeamState;

    //All is OK
    return StatusTypeSuccess;
    
}