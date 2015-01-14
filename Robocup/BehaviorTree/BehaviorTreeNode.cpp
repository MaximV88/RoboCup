//
//  BehaviorTreeNode.cpp
//  Ex3
//
//  Created by Maxim Vainshtein on 1/9/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include <math.h>
#include "BehaviorTreeNode.h"
#include "BehaviorTree.h"
#include "BehaviorContext.h"
#include "Brain.h"
#include "BehaviorException.h"

#define ERROR_NO_CONTEXT_FOUND "BehaviorTreeNode Error: No context found."

using namespace behavior;

BehaviorTreeNode::BehaviorTreeNode() :
m_eStatus(StatusTypeInvalid) {
    
}

BehaviorTreeNode::~BehaviorTreeNode() {
    
}

/****************************************************************************************************
 * function name: convertDirection                                                                  *
 * The Input: const Coordinate object (reference), const Coordinate object (reference)              *
 * The output: double                                                                               *
 * The Function Opertion: Returns the result of making a atan2f action of the input vector.         *
 * *************************************************************************************************/

double BehaviorTreeNode::convertToDirection(const Coordinate& cOrigin, const Coordinate& cDestination) const {
    
    //Direction = arctan(RelativePositionY/RelativePositionX)
    
    Vector cDirection(cDestination.getX() - cOrigin.getX(),
                      cDestination.getY() - cOrigin.getY());
    
    return atan2f(cDirection.getY(), cDirection.getX());
    
}

void BehaviorTreeNode::setContext(BehaviorContext& cContext) {
    
    //Set the current context
    m_cContext = &cContext;
    
}

BehaviorContext& BehaviorTreeNode::getContext() {
    
    //Return the stored context
    if (m_cContext != NULL)
       return *m_cContext;
    else {
        
        //Print an error, a mistake was made
        std::cerr << ERROR_NO_CONTEXT_FOUND << std::endl;

        //Cant continue due to error in code - throw to present it - shouldnt catch it
        throw BehaviorException(ERROR_NO_CONTEXT_FOUND);
        
    }
    
}

void BehaviorTreeNode::perform(const Instruction &cInstruction) {
    
    if (m_cContext != NULL)
        m_cContext->getBrain().perform(cInstruction);
    
}

StatusType BehaviorTreeNode::tick() {
    
    //If the node encountered isnt running yet
    if (m_eStatus != StatusTypeRunning)
    {
        //Initialize the node
        initialize();
    }
    
    //Now the node is surely initialized, and capable of running
    m_eStatus = process();
    
    //If the node has finished running - for whatever reason
    if (m_eStatus != StatusTypeRunning)
    {
        //Terminate it with it's current status (Aborted/Failed)
        terminate(m_eStatus);
    }
    
    //Return the status we ended with
    return m_eStatus;
    
}

void BehaviorTreeNode::initialize() {
    
    //Default node does nothing
    
}

void BehaviorTreeNode::terminate(StatusType eStatus) {
    
    //Default node does nothing
    
}

void BehaviorTreeNode::reset() {
    
    //Reset the status
    m_eStatus = StatusTypeInvalid;
}

void BehaviorTreeNode::abort() {
    
    //Make the node perform aborting procedure
    terminate(StatusTypeAborted);
    
    //And mark as aborted
    m_eStatus = StatusTypeAborted;
    
}

bool BehaviorTreeNode::isTerminated() const {
    
    //If the node has finished with a Success or a Failure (not aborted)
    return (m_eStatus == StatusTypeSuccess  ||  m_eStatus == StatusTypeFailure);
    
}

bool BehaviorTreeNode::isRunning() const {
    
    //If the node is running
    return m_eStatus == StatusTypeRunning;

}

StatusType BehaviorTreeNode::getStatus() const {
    
    //Return the status of the node
    return m_eStatus;

}