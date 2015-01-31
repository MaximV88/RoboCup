/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Ex3__ScoreNode__
#define __Ex3__ScoreNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************************************
     * ScoreNode Class: Request the server to send score information.                                   *
     ***************************************************************************************************/
    
    class ScoreNode : public BehaviorTreeNode {
        
        
    public:
        ScoreNode();
        ~ScoreNode();
        
        virtual StatusType process();
        
    };
    
}


#endif
