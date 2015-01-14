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

#define BRAIN_UNKNOWN_BEHAVIOR_NAME_ERROR "Brain Error: Behavior change to unknown name requested."
#define BRAIN_NO_SELECTED_BEHAVIOR_ERROR "Brain Error: No behavior has been selected."
#define BRAIN_INVALID_SHUTTING_DOWN "Invalid setup. Shutting Down."
#define BRAIN_TOO_MANY_UNIQUE_INSTRUCTIONS_ERROR "Brain Error: Too many unique instructions per message."
#define BRAIN_UNIQUE_INSTRUCTION_PER_MESSAGE 1

Brain::Brain(ThreadQueue<std::string*>& qInstructionQueue) :
m_qInstructionQueue(qInstructionQueue), m_cConditionVariable(m_cMutualExclusion) {
 
    m_bIsStarted = false;
    
}

Brain::~Brain() {
    
}

void Brain::addBehavior(std::string strName, behavior::BehaviorTree &cBehaviorTree) {
    
    //Map the Tree pointer to the name
    m_mcBehaviors[strName] = &cBehaviorTree;
    
}

void Brain::setBehavior(std::string strName) {
    
    //Check if the requested behavior was added
    if (m_mcBehaviors.find(strName)->second == NULL) {
        
        std::cerr << BRAIN_UNKNOWN_BEHAVIOR_NAME_ERROR << std::endl;
        return;
        
    }
    
    //Set the acting behavior
    m_cBehavior = m_mcBehaviors.find(strName)->second;
    
    //Start the brain if not started yet
    if (!m_bIsStarted) {
        
        m_bIsStarted = true;
        
        //Start playing
        start();
        
    }
    
}

void Brain::execute() {
    
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

void Brain::startAct() {
    
    //Remove any waiting thread in this object
    m_cConditionVariable.broadcast();
    
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
