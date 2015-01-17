//
//  BehaviorTreeNode.h
//  Ex3
//
//  Created by Maxim Vainshtein on 1/9/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Ex3__BehaviorTreeNode__
#define __Ex3__BehaviorTreeNode__

#include <stdio.h>
#include <stack>
#include "BehaviorContext.h"

#define DEBUG_PRINT_ACTION 1

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