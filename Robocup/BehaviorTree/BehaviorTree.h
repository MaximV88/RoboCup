/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of BehaviorTree Class      *
 ***********************************************************/

#ifndef __Ex3__BehaviorTree__
#define __Ex3__BehaviorTree__

#include <stdio.h>
#include "BehaviorTreeNode.h"
#include "BehaviorContext.h"
#include "Nameable.h"


namespace behavior {

    class BehaviorTree : public Nameable {
            
        //Root of the tree
        BehaviorTreeNode *m_cRoot;
        
        //Context of the tree
        BehaviorContext m_cContext;
                
    public:
        
        BehaviorTree(Player& cPlayer, Brain& cBrain, const std::string& strName);
        ~BehaviorTree();
        
        void setRoot(BehaviorTreeNode *cRoot);
        
        BehaviorContext& getContext();
                
        void tick();
        
    //    void abort();
        
    //    void reset();
        
    };
    
}

#endif
