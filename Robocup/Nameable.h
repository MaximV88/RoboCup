//
//  Nameable.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/17/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Robocup__Nameable__
#define __Robocup__Nameable__

#include <stdio.h>
#include <string>

/***********************************************************************************
 * Nameable Class: The class has a name, that can be changed. it is usefull        *
 *                 when inherited from to prevent duplicate code for a basic trait.*
 **********************************************************************************/

class Nameable {
    
    //  ---                         PRIVATE VARIABLES                       ---   //
    
    
    std::string m_strName;
    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: Nameable Constructor                                                          *
     * The Input: const string object (reference)                                                   *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with the input as name                         *
     * *********************************************************************************************/
    
    Nameable(const std::string& strName);
    
    /**********************************************************************************************
     * function name: changeName                                                                  *
     * The Input: const string object (reference)                                                 *
     * The output: none                                                                           *
     * The Function Opertion: Changes the name                                                    *
     * *******************************************************************************************/
    
    void changeName(const std::string& strName);
    
    /**********************************************************************************************
     * function name: getName                                                                     *
     * The Input: none                                                                            *
     * The output: const string object (reference)                                                *
     * The Function Opertion: Returns the name                                                    *
     * *******************************************************************************************/
    
    const std::string& getName() const;
    
};

#endif
