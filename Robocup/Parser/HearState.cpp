/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Implementation of HearState Class      *
 ***********************************************************/

#include "HearState.h"
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <iterator>

using namespace std;
using namespace parse;

//  ---                         PRIVATE FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: assignValues                                                                  *
 * The Input: vector<string> (reference)                                                        *
 * The output: none                                                                             *
 * The Function Opertion: Iterates over the input segmented strings and assignes each type      *
 *                        accordingly. The process if specified in the remarks.                 *
 * *********************************************************************************************/

void HearState::assignValues(const vector<string>& vcSentences) {
    
    for (vector<string>::const_iterator iter = vcSentences.begin() ; iter != vcSentences.end() ;) {
        
        //Assign it to a string stream
        stringstream rstream(*iter);
        
        istream_iterator<string> runner(rstream);
        
        //This holds the main attribute of the sentence, meaning what to do with the information
        string strFirst = *runner;
        
        //Go to the value stored
        ++runner;
        
        switch (parseWord(strFirst)) {
                
            case ParseTypeHear:
                
                //This command is complicated and contains several inputs
                time = atoi((*runner).data());

                //Get to the sender
                ++runner;
                
                sender = *runner;
                
                //Get to the message
                ++runner;
                
                message = *runner;
                
                break;
                
            default:
                break;
                
        }
        
        //Increment the count
        ++iter;
        
    }
    
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: HearState Constructor                                                         *
 * The Input: map<string, ParseType>                                                            *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with input as reference map for types.         *
 * *********************************************************************************************/

HearState::HearState(const std::map<std::string, ParseType>& cParseMap) :
State(cParseMap, StateTypeHear) { }

/**********************************************************************************************
 * function name: HearState Destructor                                                        *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Destroys the current object.                                        *
 * *******************************************************************************************/

HearState::~HearState() { }

