/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of BehaviorException Class *
 ***********************************************************/

#ifndef __Ex3__BehaviorException__
#define __Ex3__BehaviorException__

#include <stdio.h>
#include <stdexcept>

class BehaviorException : public std::runtime_error {

public:
    BehaviorException(const std::string& strError);
    
};

#endif
