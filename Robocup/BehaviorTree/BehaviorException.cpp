/****************************************************************
 * Student Name:     TreeBots                                   *
 * Exercise Name:    Ex6                                        *
 * File description: Implementation of BehaviorException Class  *
 ***************************************************************/

#include "BehaviorException.h"

using namespace std;

BehaviorException::BehaviorException(const std::string& strError) : runtime_error(strError) {
    
}