//
//  BehaviorTarget.cpp
//  Ex3
//
//  Created by Maxim Vainshtein on 1/9/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "BehaviorTarget.h"

using namespace behavior;

BehaviorTarget::BehaviorTarget(const Observable& cObservable) {
    
    initialize();
    
    //Copy the origin of the Observable
    m_cOrigin = cObservable.origin;
    
}

BehaviorTarget::BehaviorTarget(const Coordinate& cCoordinate) {
    
    initialize();
    
    //Copy the origin of the Observable
    m_cOrigin = &cCoordinate;
    
}

BehaviorTarget::~BehaviorTarget() {
    
}

void BehaviorTarget::initialize() {
    
    m_chCString = NULL;
    m_cOrigin = NULL;
    m_dValue = NULL;
    m_eQualityTypeValue = NULL;
    m_eWidthTypeValue = NULL;
    m_iValue = NULL;
    
    //TODO: convert to memset?
    
}

const Coordinate* BehaviorTarget::getOrigin() const {
    
    //Return the origin pointer
    return m_cOrigin;
    
}

const int* BehaviorTarget::getIntValue() const {
    
    //Return the value pointer
    return m_iValue;
    
}

const double* BehaviorTarget::getDoubleValue() const {
    
    //Return the value pointer
    return m_dValue;
    
}

const char* BehaviorTarget::getCStringValue() const {
    
    //Return the value pointer
    return m_chCString;
    
}

const WidthType* BehaviorTarget::getWidthTypeValue() const {
    
    //Return the value pointer
    return m_eWidthTypeValue;
    
}

const QualityType* BehaviorTarget::getQualityTypeValue() const {
    
    //Return the value pointer
    return m_eQualityTypeValue;
    
}

const Observable* BehaviorTarget::getObservable() const {
    
    //Return value pointer
    return m_cObservable;
    
}