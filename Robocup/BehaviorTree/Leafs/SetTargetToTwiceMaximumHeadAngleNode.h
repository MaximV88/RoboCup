/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Robocup__SetTargetToTwiceMaximumHeadAngleNode__
#define __Robocup__SetTargetToTwiceMaximumHeadAngleNode__

#include "BehaviorTreeNode.h"

namespace behavior {
    
    /****************************************************************************
     * SetTargetToMaximumMomentAngleNode Class:                                 *
     *                                                                          *
     *      Sets the target to the maximum moment value from                    *
     *      the server settings.                                                *
     ***************************************************************************/
    
    class SetTargetToTwiceMaximumHeadAngleNode : public BehaviorTreeNode {
        
    public:
        SetTargetToTwiceMaximumHeadAngleNode();
        ~SetTargetToTwiceMaximumHeadAngleNode();
        
        virtual StatusType process();
        
    };
    
}

#endif
