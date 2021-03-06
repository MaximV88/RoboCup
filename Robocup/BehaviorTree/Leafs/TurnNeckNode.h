/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Ex3__TurnNeckNode__
#define __Ex3__TurnNeckNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************************************
     * TurnNeckNode Class: This command can be sent (and will be executed) each cycle independently,    *
     *                        along with other action commands. The neck will rotate with the given     *
     *                      Angle relative to previous Angle. Note that the resulting neck angle will be*
     *                       between minneckang and maxneckang relative to the player’s body direction. *
     ***************************************************************************************************/
    
    
    class TurnNeckNode : public BehaviorTreeNode {
        
        
    public:
        TurnNeckNode();
        ~TurnNeckNode();
        
        virtual StatusType process();
        
    };
    
}


#endif
