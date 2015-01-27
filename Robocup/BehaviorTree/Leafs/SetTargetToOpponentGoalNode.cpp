//
//  SetTargetToOpponentGoalNode.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/27/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

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