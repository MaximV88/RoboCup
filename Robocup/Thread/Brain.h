//
//  Brain.h
//  Ex3
//
//  Created by Maxim Vainshtein on 1/9/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Ex3__Brain__
#define __Ex3__Brain__

#include <stdio.h>
#include <queue>
#include <map>
#include "Threadable.h"
#include "Instruction.h"
#include "ThreadQueue.h"
#include "BehaviorTree.h"
#include "Mutex.h"
#include "ConditionVariable.h"

class Brain : Threadable {
    
private:
    
    //This holds the Behaviors trees
    std::map<std::string, behavior::BehaviorTree*> m_mcBehaviors;
    
    //The queue is shared by all the players, thus can have several threads accessing it at once so it needs to be safe
    ThreadQueue<std::string*>& m_qInstructionQueue;
    
    //Holds the instructions created by the Player
    std::queue<const Instruction*> m_qInstructionWaitingQueue;
    
    //Holds the current acting behavior
    behavior::BehaviorTree* m_cBehavior;
    
    //Responsible for holding the thread until an update has been recieved
    Mutex m_cMutualExclusionPrimary;

    //Responsible for holding the tree pointer while performing ticks
    Mutex m_cMutualExclusionSecondary;
    
    //Pauses and resumes the thread
    ConditionVariable m_cConditionVariable;
    
    //Checks if should wait until a body state update
    double m_dIsBodyStateUpdate;
    
    //Checks if should wait until a sight state update
    double m_dIsSeeStateUpdate;

    //Checks if should wait until a sight state update
    double m_dIsTeamStateUpdate;
    
    /****************************************************************************************************
     * function name: execute                                                                           *
     * The Input: none                                                                                  *
     * The output: none                                                                                 *
     * The Function Opertion: Executes the operations required from this class (it's the 'main' thread  *
     *                        of this object), in a loop.                                               *
     * *************************************************************************************************/
    
    virtual void execute();
        
public:
    
    Brain(ThreadQueue<std::string*>& qInstructionQueue);
    
    ~Brain();
    
    void addBehavior(behavior::BehaviorTree& cBehaviorTree);
    
    void setBehavior(std::string strName);
    
    void perform(const Instruction& cInstruction);
    
    void waitBodyStateUpdate();
    
    void waitSeeStateUpdate();
    
    void waitTeamStateUpdate();
    
    void updateState(const State& cState);
    
    void executeAct();
    
    void startAct();

    /****************************************************************************************************
     * function name: endAct                                                                            *
     * The Input: none                                                                                  *
     * The output: double                                                                               *
     * The Function Opertion: After an execution cycle has been performed this takes all of the         *
     *                        decisions made by the behavior and sends them to the server.              *
     * *************************************************************************************************/
    
    void endAct();
    
};


#endif
