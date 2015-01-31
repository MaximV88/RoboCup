/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include <stdlib.h>
#include "IsTurnedOnTargetNode.h"
#include "Player.h"

#define IS_TURNED_ON_TARGET_NODE_TARGET_ERROR "IsTurnedOnTargetNode Error: No Target given"
#define IS_TURNED_ON_TARGET_NODE_VALUE_ERROR "IsTurnedOnTargetNode Error: No Observable value given in the "

using namespace behavior;

IsTurnedOnTargetNode::IsTurnedOnTargetNode(double dDegreeThreshold) {
    
    //Set the internal member's value to be used later on
    m_dDegreeThreshold = dDegreeThreshold;
    
}

IsTurnedOnTargetNode::~IsTurnedOnTargetNode() {
    
}

StatusType IsTurnedOnTargetNode::process() {
    
    //Add the required input from the target
    BehaviorTarget *cTarget = getContext().getCurrentTarget();
    
    //If no target is present, return failed
    if (cTarget == NULL) {
        
        //Print error and return
        DebugLogError(IS_TURNED_ON_TARGET_NODE_TARGET_ERROR);
        return StatusTypeFailure;
        
    }
    
    //Check if our target has an origin to move to
    const Observable *cObservable = cTarget->getObservable();
    
    //If no coordinate is given, return failed
    if (cObservable == NULL) {
        
        //Print error and return
        DebugLogError(IS_TURNED_ON_TARGET_NODE_VALUE_ERROR << *cTarget)
        return StatusTypeFailure;
        
    }
    
    SeeState *cCState = getContext().getPlayer().getLastSeeState();
    BodyState *cBState = getContext().getPlayer().getLastBodyState();
    
    for (std::vector<Observable*>::const_iterator iter = cCState->getObservables().begin();
         iter != cCState->getObservables().end();
         iter++) {
        
        //Need to adjust it to players
        if ((*iter)->type == cObservable->type) {
            
            Observable* cAdjusted = *iter;
            
            cAdjusted->direction += cBState->headAngle;
        
            //Update the held target
            cTarget->setObservable(*cAdjusted);
        
            //Check too see that the angle is less than limit
            if (abs((*iter)->direction) <= m_dDegreeThreshold) {
                
                //Remove the copy
                delete cCState;
                delete cBState;
                
                return StatusTypeSuccess;
                
            }
            else {
                
                //Remove the copy
                delete cCState;
                delete cBState;

                return StatusTypeFailure;
                
            }
            
        }
        
        
    }
    
    //Remove the copy
    delete cCState;
    delete cBState;

    //Havnt found it
    return StatusTypeFailure;
    
}
