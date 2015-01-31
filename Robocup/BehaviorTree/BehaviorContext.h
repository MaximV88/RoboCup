/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of BehaviorContext Class   *
 ***********************************************************/

#ifndef __Ex3__BehaviorContext__
#define __Ex3__BehaviorContext__

#include <stdio.h>
#include <stack>
#include "BehaviorTarget.h"

class Player;
class Brain;

namespace behavior {
    
    class BehaviorContext {
        
    private:
        
        //Holds all the targets in a stack
        std::stack<BehaviorTarget*> m_cStack;
        
        //Holds the current target
        BehaviorTarget* m_cCurrentTarget;

        //Holds the current player
        Player& m_cPlayer;
        
        //Holds the player's brain
        Brain& m_cBrain;

        
    public:
        BehaviorContext(Player& cPlayer, Brain& cBrain);
        ~BehaviorContext();
        
        Player& getPlayer() const;
        
        Brain& getBrain();
        
        std::stack<BehaviorTarget*>& getStack();
        
        BehaviorTarget* getCurrentTarget() const;
        
        void setCurrentTarget(BehaviorTarget* cTarget);
        
    };
    
}

#endif
