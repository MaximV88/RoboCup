//
//  BehaviorException.cpp
//  Ex3
//
//  Created by Maxim Vainshtein on 1/14/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "BehaviorException.h"

using namespace std;

BehaviorException::BehaviorException(const std::string& strError) : runtime_error(strError) {
    
}