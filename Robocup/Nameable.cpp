/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include "Nameable.h"

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: Nameable Constructor                                                          *
 * The Input: const string object (reference)                                                   *
 * The output: none                                                                             *
 * The Function Opertion: Sets the member variable that holds the name string with the input    *
 *                        string- it copies the contents from the input string to the member.   *
 * *********************************************************************************************/

Nameable::Nameable(const std::string& strName) {
    
    //Copy the name
    m_strName = strName;
    
}

/**********************************************************************************************
 * function name: changeName                                                                  *
 * The Input: const string object (reference)                                                 *
 * The output: none                                                                           *
 * The Function Opertion: Sets the member variable that holds the name string with the input  *
 *                        string- it copies the contents from the input string to the member. *
 * *******************************************************************************************/

void Nameable::changeName(const std::string &strName) {
    
    //Copy the name
    m_strName = strName;
    
}

/**********************************************************************************************
 * function name: getName                                                                     *
 * The Input: none                                                                            *
 * The output: const string object (reference)                                                *
 * The Function Opertion: Returns a const reference of the member variable that holds the name*
 * *******************************************************************************************/

const std::string& Nameable::getName() const {
    
    //Return a reference
    return m_strName;
    
}
