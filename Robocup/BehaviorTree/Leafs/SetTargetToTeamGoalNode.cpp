//
//  SetTargetToTeamGoalNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/27/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "SetTargetToTeamGoalNode.h"
#include "Player.h"

#define NODE_NAME "SetTargetToOpponentGoalNode"

#define DEBUG_ACTION_DESCRIPTION_SUCCESS "Successfuly set opponent side as Target type"

using namespace behavior;

SetTargetToTeamGoalNode::SetTargetToTeamGoalNode() {
    
}

SetTargetToTeamGoalNode::~SetTargetToTeamGoalNode() {
    
}

StatusType SetTargetToTeamGoalNode::process() {
    
    TeamState *cTeamState = getContext().getPlayer().getLastTeamState();
    
    //Check if valid for calculation
    if (cTeamState == NULL)
        return StatusTypeFailure;
    
    //Check if opponent goal visible
    ObservableType eGoal;
    
    switch (cTeamState->teamSide) {
        case TeamSideLeft:
            eGoal = ObservableTypeGoalLeft;
            break;
            
        case TeamSideRight:
            eGoal = ObservableTypeGoalRight;
            break;
            
        default:
            break;
    }
    
    //Set the rotation as the target
    getContext().setCurrentTarget(new BehaviorTarget(eGoal, NODE_NAME));
    
    //Print the action's description
    DebugLogVerbose(DEBUG_ACTION_DESCRIPTION_SUCCESS);
    
    //Delete after usage
    delete cTeamState;
    
    //All is OK
    return StatusTypeSuccess;
    
}