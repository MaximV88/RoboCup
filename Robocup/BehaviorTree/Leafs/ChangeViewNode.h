/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Ex3__ChangeViewNode__
#define __Ex3__ChangeViewNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************************************
     * ChangeViewNode Class:  Changes the view parameters of the player. Width is one of narrow, normal *
     *                        or wide and Quality is one of high or low. The amount and detail of the   *
     *                        informationreturned by the visual sensor depends on the width of the view *
     *                        and the quality. But note that the frequency of sending information also  *
     *                        depends on these parameters (e.g. if you change the quality from high to  *
     *                        low, the frequency doubles, and the time between two see sensors will     *
     *                        be cut to half).                                                          *
     ***************************************************************************************************/
    
    class ChangeViewNode : public BehaviorTreeNode {
        
        
    public:
        ChangeViewNode();
        ~ChangeViewNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
