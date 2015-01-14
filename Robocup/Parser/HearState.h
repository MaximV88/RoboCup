/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Declaration of HearState Class         *
 ***********************************************************/

#ifndef __Ex3__HearState__
#define __Ex3__HearState__

#include <stdio.h>
#include "State.h"

/*******************************************************************************
 * HearState Class: Represents the Hearing input recieved from the server,     *
 *                 the (hear ...) command.                                     *
 ******************************************************************************/

class HearState : public State {
    
private:
    
    //  ---                         PRIVATE FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: assignValues                                                                  *
     * The Input: vector<string> (reference)                                                        *
     * The output: none                                                                             *
     * The Function Opertion: assigns the values related to the input in the vector argument        *
     *                        to the state's member variable.                                       *
     * *********************************************************************************************/
    
    virtual void assignValues(const std::vector<std::string>& vcSentences);
    
public:
    
    //  ---                         PUBLIC VARIABLES                       ---   //

    int time;
    
    //TODO: change to enum
    std::string sender;
    std::string message;
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: HearState Constructor                                                         *
     * The Input: map<string, ParseType>                                                            *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input as reference map for types.         *
     * *********************************************************************************************/
    
    HearState(const std::map<std::string, parse::ParseType>& cParseMap);
    
    /**********************************************************************************************
     * function name: HearState Destructor                                                        *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~HearState();
    
};

#endif 
