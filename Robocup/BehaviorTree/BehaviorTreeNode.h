/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of BehaviorTreeNode Class  *
 ***********************************************************/

#ifndef __Ex3__BehaviorTreeNode__
#define __Ex3__BehaviorTreeNode__

#include <stdio.h>
#include <stack>
#include "BehaviorContext.h"

#define DEBUG_VERBOSE 0
#define DEBUG_ERROR 0
#define DebugLogVerbose(Input) if (DEBUG_VERBOSE) std::cout << Input << std::endl;
#define DebugLogError(Input) if (DEBUG_ERROR) std::cerr << Input << std::endl;

namespace behavior {
    
    typedef enum {
        
        StatusTypeInvalid,
        StatusTypeAborted,
        StatusTypeSuccess,
        StatusTypeFailure,
        StatusTypeRunning
        
    } StatusType;
    
    class BehaviorTarget;
    class BehaviorTree;
    
    class BehaviorTreeNode {
        
    private:
        
        StatusType m_eStatus;
        
        BehaviorContext* m_cContext;
        
        virtual StatusType process() = 0;
        
        virtual void initialize();
        
        virtual void terminate(StatusType eStatus);
        
    protected:
        
        double convertToDirection(const Coordinate& cOrigin, const Coordinate& cDestination) const;
        
        void perform(const Instruction& cInstruction);
        
    public:
        
        BehaviorTreeNode();
        
        BehaviorContext& getContext();
        
        virtual ~BehaviorTreeNode();
        
        StatusType tick();
        
        void reset();
        
        void abort();
        
        bool isTerminated() const;
        
        bool isRunning() const;
        
        StatusType getStatus() const;
        
        virtual void setContext(BehaviorContext& cContext);

    };
    
}

#endif