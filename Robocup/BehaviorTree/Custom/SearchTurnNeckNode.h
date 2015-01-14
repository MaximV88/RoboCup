//
//  SearchHeadTurnNode.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/14/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Robocup__SearchHeadTurnNode__
#define __Robocup__SearchHeadTurnNode__

#include "SequenceNode.h"

namespace behavior {
    
    /****************************************************************************************
     * SearchHeadTurnNode Class: Recieves an input target (an ObservableType),              *
     *                   and turns the head to center,left and right and checks visibility. *
     *                   If found, returns success. Otherwise returns false.                *
     ***************************************************************************************/
    
    class SearchTurnNeckNode : public SequenceNode {
        
    private:
        
        void addVisibilityCheck(SequenceNode* cSequence);
        void turnNeck(SequenceNode* cSequence, double dDirection);
        
    public:
        SearchTurnNeckNode();
        ~SearchTurnNeckNode();
        
        
    };
    
}

#endif
