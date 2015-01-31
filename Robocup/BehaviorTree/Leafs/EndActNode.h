/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Ex3__EndActNode__
#define __Ex3__EndActNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /*******************************************************************************
     * EndActNode Class: Request the Brain to send gathered instructions. Will     *
     *                   always wait until an update has been recieved from server.*
     ******************************************************************************/
    
    class EndActNode : public BehaviorTreeNode {
        
        
    public:
        EndActNode();
        ~EndActNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
