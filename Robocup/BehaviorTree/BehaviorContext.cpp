//
//  BehaviorContext.cpp
//  Ex3
//
//  Created by Maxim Vainshtein on 1/10/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "BehaviorContext.h"
#include "Player.h"
#include "Brain.h"

using namespace behavior;

BehaviorContext::BehaviorContext(Player& cPlayer, Brain& cBrain) :
m_cPlayer(cPlayer), m_cBrain(cBrain) {
    
    m_cCurrentTarget = NULL;
    
}

BehaviorContext::~BehaviorContext() {
    
}

Player& BehaviorContext::getPlayer() const {
    
    //Return the player
    return m_cPlayer;
    
}

Brain& BehaviorContext::getBrain() {
    
    //Return the player's brain
    return m_cBrain;
    
}

std::stack<BehaviorTarget*>& BehaviorContext::getStack() {
    
    //Return the stored stack
    return m_cStack;
    
}

BehaviorTarget* BehaviorContext::getCurrentTarget() const {
    
    //Return the current target
    return m_cCurrentTarget;
    
}

void BehaviorContext::setCurrentTarget(behavior::BehaviorTarget *cTarget) {
    
    //Always remove the previous target
    if (m_cCurrentTarget != NULL)
        delete m_cCurrentTarget;
    
    //Set the new target
    m_cCurrentTarget = cTarget;
    
}