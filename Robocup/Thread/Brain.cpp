//
//  Brain.cpp
//  Ex3
//
//  Created by Maxim Vainshtein on 1/9/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "Brain.h"
#include "Player.h"
#include "BehaviorTree.h"

#define DEBUG_PRINT_EXECUTION_INDEX_MESSAGE "Debug: At execution index "

#define BRAIN_UNKNOWN_BEHAVIOR_NAME_ERROR "Brain Error: Behavior change to unknown name requested."
#define BRAIN_NO_SELECTED_BEHAVIOR_ERROR "Brain Error: No behavior has been selected."
#define BRAIN_INVALID_SHUTTING_DOWN "Invalid setup. Shutting Down."
#define BRAIN_TOO_MANY_UNIQUE_INSTRUCTIONS_ERROR "Brain Error: Too many unique instructions per message."
#define BRAIN_UNIQUE_INSTRUCTION_PER_MESSAGE 1

#define EXECUTE_ACTION_DESCRIPTION "Brain: Execution will end the Act."

Brain::Brain(ThreadQueue<std::string*>& qInstructionQueue) :
m_qInstructionQueue(qInstructionQueue), m_cConditionVariable(m_cMutualExclusion) {
 
    m_bIsBodyStateUpdate = false;
    m_bIsSeeStateUpdate = false;
    
    m_cBehavior = NULL;
    
    //Start playing
    start();
    
}

Brain::~Brain() {
    
}

void Brain::addBehavior(behavior::BehaviorTree &cBehaviorTree) {
    
    //Map the Tree pointer to the name
    m_mcBehaviors[cBehaviorTree.getName()] = &cBehaviorTree;
    
}

void Brain::setBehavior(std::string strName) {
    
    //Check if the requested behavior was added
    if (m_mcBehaviors.find(strName)->second == NULL) {
        
        std::cerr << BRAIN_UNKNOWN_BEHAVIOR_NAME_ERROR << std::endl;
        return;
        
    }
    
    //Set the acting behavior
    m_cBehavior = m_mcBehaviors.find(strName)->second;
    
}

void Brain::execute() {
    
    //Dont start doing anything until startAct has been called
    m_cMutualExclusion.lock();
    
    //Dont start doing anything until startAct has been called
    m_cConditionVariable.wait();
    
    //Unlock since we need it elsewhere
    m_cMutualExclusion.unlock();

    
    //Always check before run that the selected tree is valid
    if (m_cBehavior == NULL) {
        
        std::cerr << BRAIN_NO_SELECTED_BEHAVIOR_ERROR << std::endl;
        std::cerr << BRAIN_INVALID_SHUTTING_DOWN << std::endl;
        return;
        
    }
    
    
    while (true) {
        
        //Always tick the behavior tree
        m_cBehavior->tick();
        
    }
    
}

void Brain::perform(const Instruction &cInstruction) {
    
    //Add it to the queue
    m_qInstructionWaitingQueue.push(&cInstruction);
    
}

void Brain::waitBodyStateUpdate() {
    
    m_bIsBodyStateUpdate = true;
    
}

void Brain::waitSeeStateUpdate() {
    
    m_bIsSeeStateUpdate = true;
    
}

void Brain::waitTeamStateUpdate() {
    
    m_bIsTeamStateUpdate = true;
    
}

void Brain::updateState(const State &cState) {
    
    switch (cState.eType) {
        case StateTypeBody:
            m_bIsBodyStateUpdate = false;
            break;
            
        case StateTypeSee:
            m_bIsSeeStateUpdate = false;
            break;
            
        case StateTypeTeam:
            m_bIsTeamStateUpdate = false;
            break;
            
        default:
            break;
    }
    
}

void Brain::startAct() {
    
    /*
     * Dont broadcast if any of the flags 
     * still on (tree building should take that in mind)
     */
    
    if (m_bIsBodyStateUpdate ||
        m_bIsSeeStateUpdate ||
        m_bIsTeamStateUpdate) {
     
        return;
    
    }
    
    //Continue as normal (per every update)
    
#if DEBUG_PRINT_EXECUTION_INDEX
    
    static int iExcIndex = 0;
    
    //Mainly used to compare updates vs server cycles
    std::cout << DEBUG_PRINT_EXECUTION_INDEX_MESSAGE << ++iExcIndex << std::endl;
    
#endif
    
    //Remove any waiting thread in this object
    m_cConditionVariable.broadcast();
    
}

void Brain::executeAct() {
    
    //Check if there is something to execute
    if (!m_qInstructionWaitingQueue.empty()) {
        
#ifdef DEBUG_PRINT_ACTION
      
        std::cout << EXECUTE_ACTION_DESCRIPTION << std::endl;
        
#endif
        
        //Prevent duplicate code
        endAct();
        
    }
    
}

/****************************************************************************************************
 * function name: endAct                                                                            *
 * The Input: none                                                                                  *
 * The output: double                                                                               *
 * The Function Opertion: Checks if instructions are available from the player. If so, takes        *
 *                        it and adds it to the sent string, and appends any other instruction.     *
 *                        if more than one unique (a special insturction that can be called only    *
 *                        once per cycle) is present, make an error and fail to send (this needs    *
 *                        to handled manually in the player inhereted function implementation).     *
 * *************************************************************************************************/

void Brain::endAct() {
    
    //Put a lock on the thread
    m_cMutualExclusion.lock();
    
    //Put all of the waiting instructions to the threaded queue (will start process elsewhere)
    if (!m_qInstructionWaitingQueue.empty()) {
        
        //Avoid multiple copies
        std::string *strToTransmit = new std::string;
        unsigned int uiValidCounter = 0;
        
        //Append all instructions and send them
        while (!m_qInstructionWaitingQueue.empty()) {
            
            const Instruction* cInsToTransmit = m_qInstructionWaitingQueue.front();
            m_qInstructionWaitingQueue.pop();
            
            //If there is a single cycle instruction, add it to the counter
            if (!cInsToTransmit->isAttachable())
                ++uiValidCounter;
            
            //Append the strings
            strToTransmit->append(cInsToTransmit->getInstruction());
            
            delete cInsToTransmit;
            
        }
        
        //Check if the (parsed) instructions are valid
        if (uiValidCounter > BRAIN_UNIQUE_INSTRUCTION_PER_MESSAGE)
            std::cerr << BRAIN_TOO_MANY_UNIQUE_INSTRUCTIONS_ERROR << std::endl;
        else {
            
            //Get the resulting string to the server
            m_qInstructionQueue.push(strToTransmit);
            
        }
        
    }
    
    //Wait after sending the instructions
    m_cConditionVariable.wait();
    
    //Unlock after wait has been released
    m_cMutualExclusion.unlock();
    
}
