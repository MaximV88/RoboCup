/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Declaration of State Class             *
 ***********************************************************/

#ifndef __Ex3__State__
#define __Ex3__State__

#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include "ParserTypeDefinitions.h"

typedef enum {
    
    StateTypeTeam,
    StateTypePlayer,
    StateTypeServer,
    StateTypeBody,
    StateTypeSee,
    StateTypeHear
    
}StateType;

/*******************************************************************************
 * State Class: Represents the input recieved from the robocup server,         *
 *              Parses the information recieved and assigns it to variables.   *
 ******************************************************************************/

class State {
    
private:
    
    //  ---                         PRIVATE VARIABLES                       ---   //

    //Stored the hash table that connects string values to ParseType
    const std::map<std::string, parse::ParseType>& m_cParseMap;
    
    
    //  ---                         PRIVATE FUNCTIONS                       ---   //

    
    /************************************************************************************************
     * function name: parseHelper                                                                   *
     * The Input: vector<string> (reference), string (reference)                                    *
     * The output: none                                                                             *
     * The Function Opertion: Parses the input string to the values contained inside the "(....)"   *
     * *********************************************************************************************/
    
    void parseHelper(std::vector<std::string>& vcSentences, const std::string& strInput);
    
protected:
    
    //  ---                         PROTECTED FUNCTIONS                       ---   //

    
    /************************************************************************************************
     * function name: parseWord                                                                     *
     * The Input: string (reference)                                                                *
     * The output: ParseType                                                                        *
     * The Function Opertion: Returns the type that is related to the input string.                 *
     * *********************************************************************************************/
    
    parse::ParseType parseWord(const std::string& strInput) const;
    
    /************************************************************************************************
     * function name: assignValues                                                                  *
     * The Input: vector<string> (reference)                                                        *
     * The output: none                                                                             *
     * The Function Opertion: assigns the values related to the input in the vector argument        *
     *                        to the state's member variable.                                       *
     * *********************************************************************************************/
    
    virtual void assignValues(const std::vector<std::string>& vcSentences) = 0;
    
public:
    
    //  ---                         PUBLIC VARIABLES                       ---   //

    //The type of the current object.
    const StateType eType;
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //

    
    /************************************************************************************************
     * function name: State Constructor                                                             *
     * The Input: map<string, ParseType>                                                            *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input as reference map for types.         *
     * *********************************************************************************************/
    
    State(const std::map<std::string, parse::ParseType>& cParseMap, StateType eType);
    
    /**********************************************************************************************
     * function name: State Destructor                                                            *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    virtual ~State();
    
    /************************************************************************************************
     * function name: parseUpdatedInput                                                             *
     * The Input: map<string, ParseType>                                                            *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input as reference map for types.         *
     * *********************************************************************************************/
    
    void parseUpdatedInput(const std::string& strInput);
    
};

#endif 
