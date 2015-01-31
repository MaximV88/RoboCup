/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include "IsTargetVisibleNode.h"
#include "Player.h"

#define IS_TARGET_VISIBLE_NODE_TARGET_ERROR "IsTargetVisibleNode Error: No Target given"
#define IS_TARGET_VISIBLE_NODE_VALUE_ERROR "IsTargetVisibleNode Error: No ObservableType value given in the "

#define DEBUG_ACTION_DESCRIPTION_SUCCESS "Successfuly seen the "
#define DEBUG_ACTION_DESCRIPTION_FAILURE "Did not see the "

using namespace behavior;

IsTargetVisibleNode::IsTargetVisibleNode() {
    
}

IsTargetVisibleNode::~IsTargetVisibleNode() {
    
}

StatusType IsTargetVisibleNode::process() {
    
    //Set the target to the required pointer
    SeeState* cState = getContext().getPlayer().getLastSeeState();
    BodyState *cBody = getContext().getPlayer().getLastBodyState();
    
    //Check if the player has even seen anything
    if (cState == NULL || cBody == NULL)
        return StatusTypeFailure;
    
    //Add the required input from the target
    BehaviorTarget *cTarget = getContext().getCurrentTarget();
    
    //If no target is present, return failed
    if (cTarget == NULL) {
        
        //Print error and return
        DebugLogError(IS_TARGET_VISIBLE_NODE_TARGET_ERROR);
        
        //Delete after usage
        delete cState;
        delete cBody;
        
        return StatusTypeFailure;
        
    }
    
    //Check if our target has an origin to move to
    const ObservableType *eObservableType = cTarget->getObservableType();
    
    //If no coordinate is given, return failed
    if (eObservableType == NULL) {
   
        //Print error and return
        DebugLogError(IS_TARGET_VISIBLE_NODE_VALUE_ERROR << *cTarget);
        
        //Delete after usage
        delete cState;
        delete cBody;

        return StatusTypeFailure;
        
    }
    
    std::vector<Observable*> vcObservables = cState->getObservables();
    
    //Search in the see states visible observables for our target
    for (std::vector<Observable*>::const_iterator iter = vcObservables.begin() ;
         iter != vcObservables.end() ;
         iter++) {
        
        if ((*iter)->type == *eObservableType) {
            
            //Print the action's description
            DebugLogVerbose(DEBUG_ACTION_DESCRIPTION_SUCCESS << **iter);
            
            (*iter)->direction += cBody->headAngle;
            
            //Add extra data to the target
            cTarget->setObservable(**iter);
            
            //Delete after usage
            delete cState;
            delete cBody;

            //Found it - thus it's visible
            return StatusTypeSuccess;
            
        }
        
    }
    
    //Print the action's description
    DebugLogVerbose(DEBUG_ACTION_DESCRIPTION_FAILURE << *cTarget);
    
    //Delete after usage
    delete cState;
    delete cBody;

    //Havnt found it
    return StatusTypeFailure;
    
}
