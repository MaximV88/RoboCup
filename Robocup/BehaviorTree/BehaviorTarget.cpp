/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of BehaviorTarget Class *
 ***********************************************************/

#include "BehaviorTarget.h"

#define TARGET_PRINT_FORMAT "BehaviorTarget created by "

using namespace behavior;

BehaviorTarget::BehaviorTarget(const BehaviorTarget& cBehaviorTarget) :
Nameable(cBehaviorTarget) {
    
    initialize();
    
    //Copy each element that exists into the heap
    if (cBehaviorTarget.m_iValue != NULL)
        m_iValue = new int(*cBehaviorTarget.m_iValue);
    
    if (cBehaviorTarget.m_dValue != NULL)
        m_dValue = new double(*cBehaviorTarget.m_dValue);
    
    if (cBehaviorTarget.m_eWidthTypeValue != NULL)
        m_eWidthTypeValue = new WidthType(*cBehaviorTarget.m_eWidthTypeValue);
    
    if (cBehaviorTarget.m_eQualityTypeValue != NULL)
        m_eQualityTypeValue = new QualityType(*cBehaviorTarget.m_eQualityTypeValue);
    
    if (cBehaviorTarget.m_eObservableType != NULL)
        m_eObservableType = new ObservableType(*cBehaviorTarget.m_eObservableType);
    
    //Just copy the pointer for this one (its not our responsibility to delete it)
    if (cBehaviorTarget.m_cObservable != NULL)
        m_cObservable =  new Observable(*cBehaviorTarget.m_cObservable);
    
    if (cBehaviorTarget.m_cOrigin != NULL)
        m_cOrigin =  new Coordinate(*cBehaviorTarget.m_cOrigin);
    
    
}

BehaviorTarget::BehaviorTarget(const Observable& cObservable, const std::string& strName) :
Nameable(strName) {
    
    initialize();
    
    //Copy the input to the target
    m_cObservable = new Observable(cObservable);
    
    //Copy the origin of the Observable
   // m_cOrigin = cObservable.origin;
    
}

BehaviorTarget::BehaviorTarget(const Coordinate& cCoordinate, const std::string& strName) :
Nameable(strName) {
    
    initialize();
    
    //Copy the origin of the Observable
    m_cOrigin = new Coordinate(cCoordinate);
    
}

BehaviorTarget::BehaviorTarget(WidthType eWidthType, QualityType eQualityType, const std::string& strName) :
Nameable(strName) {
    
    initialize();
    
    //Copy both parameters
    m_eQualityTypeValue = new QualityType(eQualityType);
    m_eWidthTypeValue = new WidthType(eWidthType);
    
}

BehaviorTarget::BehaviorTarget(ObservableType eObservableType, const std::string& strName) :
Nameable(strName) {
    
    initialize();

    //Copy the parameter
    m_eObservableType = new ObservableType(eObservableType);
    
}

BehaviorTarget::BehaviorTarget(double dValue, const std::string& strName) :
Nameable(strName) {
    
    initialize();
    
    //Copy the parameter
    m_dValue = new double(dValue);
    
}

BehaviorTarget::BehaviorTarget(int iValue, const std::string& strName) :
Nameable(strName) {
    
    initialize();
    
    //Copy the parameter
    m_iValue = new int(iValue);
    
}

BehaviorTarget::~BehaviorTarget() {
    
    //Remove all non-object member variables
    if (m_eQualityTypeValue != NULL)
        delete m_eQualityTypeValue;
    
    if (m_eWidthTypeValue != NULL)
        delete m_eWidthTypeValue;

    if (m_dValue != NULL)
        delete m_dValue;
    
    if (m_iValue != NULL)
        delete m_iValue;
    
    if (m_eObservableType != NULL)
        delete m_eObservableType;
    
    if (m_cObservable != NULL)
        delete m_cObservable;
    
    if (m_cOrigin != NULL)
        delete m_cOrigin;
    
    //Should delete c string? check for memory leaks
 //   if (m_chCString != NULL)
 //       delete m_chCString;
    
}

void BehaviorTarget::initialize() {
    
    m_chCString = NULL;
    m_cOrigin = NULL;
    m_dValue = NULL;
    m_eQualityTypeValue = NULL;
    m_eWidthTypeValue = NULL;
    m_iValue = NULL;
    m_eObservableType = NULL;
    m_cObservable = NULL;
    
    //TODO: convert to memset?
    
}

void BehaviorTarget::setObservable(const Observable& cObservable) {
    
    //Remove the current Observable object
    if (m_cObservable != NULL)
        delete m_cObservable;
    
    m_cObservable = new Observable(cObservable);
    
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

const ObservableType* BehaviorTarget::getObservableType() const {
    
    //Return value pointer
    return m_eObservableType;
    
}

namespace behavior {
    
    std::ostream& operator<<(std::ostream &out, const BehaviorTarget &cBehaviorTarget) {
        
        out << TARGET_PRINT_FORMAT << "'" << cBehaviorTarget.getName() << "'.";
        
        return out;
        
    }

}
