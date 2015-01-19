//
//  BehaviorTarget.h
//  Ex3
//
//  Created by Maxim Vainshtein on 1/9/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Ex3__BehaviorTarget__
#define __Ex3__BehaviorTarget__

#include <stdio.h>
#include "Coordinate.h"
#include "Observable.h"
#include "Instruction.h"
#include "BodyState.h"
#include "Nameable.h"

namespace behavior {
    
    class BehaviorTarget : public Nameable {
        
        const Coordinate* m_cOrigin;
        
        const int* m_iValue;
        
        const double* m_dValue;
        
        const char* m_chCString;
        
        const WidthType* m_eWidthTypeValue;
        
        const QualityType* m_eQualityTypeValue;
        
        const Observable* m_cObservable;
        
        const ObservableType* m_eObservableType;
        
    public:
        
        BehaviorTarget(const BehaviorTarget& cBehaviorTarget);
        
        BehaviorTarget(const Observable& cObservable, const std::string& strName);
        
        BehaviorTarget(const Coordinate& cCoordinate, const std::string& strName);
        
        BehaviorTarget(WidthType eWidthType, QualityType eQualityType, const std::string& strName);
    
        BehaviorTarget(ObservableType eObservableType, const std::string& strName);
        
        BehaviorTarget(double dValue, const std::string& strName);
        
        BehaviorTarget(int iValue, const std::string& strName);

        ~BehaviorTarget();
        
        void initialize();
        
        void setObservable(const Observable& cObservable);
        
        const Coordinate* getOrigin() const;
        
        const int* getIntValue() const;
        
        const double* getDoubleValue() const;
        
        const char* getCStringValue() const;
        
        const WidthType* getWidthTypeValue() const;

        const QualityType* getQualityTypeValue() const;
        
        const Observable* getObservable() const;
        
        const ObservableType* getObservableType() const;
        
        friend std::ostream& operator<<(std::ostream &out, const BehaviorTarget &cBehaviorTarget);

    };
    
}

#endif
