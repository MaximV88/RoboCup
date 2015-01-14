/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Implementation of State Class          *
 ***********************************************************/


#include "State.h"
#include <iostream>
#include <sstream>
#include <iterator>

#define START_DELIMITER '('
#define END_DELIMITER ')'
#define WHITE_SPACE ' '

using namespace std;
using namespace parse;

//  ---                         PRIVATE FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: parseHelper                                                                   *
 * The Input: vector<string> (reference), string (reference)                                    *
 * The output: none                                                                             *
 * The Function Opertion: Checks if there is a "(....)" expression, if not it pushes the        *
 *                        given input to the Sentences vector. Otherwise it continues to        *
 *                        go over the input and send to parsing a value that is inside          *
 *                        the "(....)" expression using recursion.                              *
 * *********************************************************************************************/

void State::parseHelper(vector<string>& vcSentences, const string& strInput) {

    //When not detecting any parenthesis, its a 'pure' sentence
    string::size_type iDelimStart = strInput.find_first_of(START_DELIMITER);
    string::size_type iDelimEnd = strInput.find_last_of(END_DELIMITER);
    
    if (iDelimEnd == string::npos && iDelimStart == string::npos) {
        
        //Its a valid sentence
        vcSentences.push_back(strInput);
        return;
        
    }
    
    unsigned int uiCounter = 0;
    string::size_type uiPosStart = 0;

    
    //First get a possible input
    string strFirst = strInput.substr(0, iDelimStart-1);
    if (strFirst.length() != 0)
        vcSentences.push_back(strFirst);
    
    //Otherwise, there is still a sentence- scan using a counter (instead of stack)
    for (string::const_iterator iter = strInput.begin() ; iter != strInput.end() ; iter++) {
        
        //When finding a parenthesis, increment the counter
        if (*iter == START_DELIMITER) {
         
            //The starting position of substring is from the first deliminator
            if (uiCounter == 0)
                uiPosStart = iter - strInput.begin();
                
            ++uiCounter;
            
        }
        else if (*iter == END_DELIMITER) {
            
            --uiCounter;
         
            //If its the ending of a valid sentence, the counter should be 0
            if (uiCounter == 0) {
                
                //Add the current given input as a sentence - remove the whitespace
                parseHelper(vcSentences, strInput.substr(uiPosStart+1,  iter-strInput.begin()-uiPosStart-1));
                
            }
            
            
        }
        
    }
    
}

//  ---                         PROTECTED FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: parseWord                                                                     *
 * The Input: string (reference)                                                                *
 * The output: ParseType                                                                        *
 * The Function Opertion: Finds the requested type in the reference map, and returns it.        *
 * *********************************************************************************************/

ParseType State::parseWord(const string& strInput) const {
    
    //Get the type from the map, if exists.
    return (m_cParseMap.find(strInput))->second;
    
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: State Constructor                                                             *
 * The Input: map<string, ParseType>                                                            *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the member variable.                                      *
 * *********************************************************************************************/

State::State(const map<string, ParseType>& cParseMap, StateType eType) : m_cParseMap(cParseMap), eType(eType) { }

/**********************************************************************************************
 * function name: State Destructor                                                            *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Nothing.                                                            *
 * *******************************************************************************************/

State::~State() { }

/************************************************************************************************
 * function name: parseUpdatedInput                                                             *
 * The Input: map<string, ParseType>                                                            *
 * The output: none                                                                             *
 * The Function Opertion: Cuts off the first '(' and the last ')', sends the resulting string   *
 *                        into parsing that it will return segmented in a vector, and passes    *
 *                        on the segments to assigned values.                                   *
 * *********************************************************************************************/

void State::parseUpdatedInput(const string &strInput) {
   
    vector<string> vcSentences;
    
    //First prepare the scope
    string::size_type iDelimStart = strInput.find_first_of(START_DELIMITER);
    string::size_type iDelimEnd = strInput.find_last_of(END_DELIMITER);

    parseHelper(vcSentences, strInput.substr(iDelimStart+1, iDelimEnd-1));
    
    //Return the created vector
    assignValues(vcSentences);
    
}
