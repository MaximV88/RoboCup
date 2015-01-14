//
//  BehaviorException.h
//  Ex3
//
//  Created by Maxim Vainshtein on 1/14/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Ex3__BehaviorException__
#define __Ex3__BehaviorException__

#include <stdio.h>
#include <stdexcept>

class BehaviorException : public std::runtime_error {

public:
    BehaviorException(const std::string& strError);
    
};

#endif
