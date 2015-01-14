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

namespace behavior {
    
    class BehaviorTarget {
        
        const Coordinate* m_cOrigin;
        
        const int* m_iValue;
        
        const double* m_dValue;
        
        const char* m_chCString;
        
        const WidthType* m_eWidthTypeValue;
        
        const QualityType* m_eQualityTypeValue;
        
        const Observable* m_cObservable;
        
    public:
        BehaviorTarget(const Observable& cObservable);
        
        BehaviorTarget(const Coordinate& cCoordinate);
        
        BehaviorTarget(WidthType eWidthType, QualityType eQualityType);
        
        ~BehaviorTarget();
        
        void initialize();
        
        const Coordinate* getOrigin() const;
        
        const int* getIntValue() const;
        
        const double* getDoubleValue() const;
        
        const char* getCStringValue() const;
        
        const WidthType* getWidthTypeValue() const;

        const QualityType* getQualityTypeValue() const;
        
        const Observable* getObservable() const;

    };
    
}

#endif
