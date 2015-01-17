/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Implementation of PlayerState Class    *
 ***********************************************************/

#include "PlayerState.h"
#include <stdlib.h>
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

void PlayerState::assignValues(const std::vector<std::string>& vcSentences) {
    
    for (vector<string>::const_iterator iter = vcSentences.begin() ; iter != vcSentences.end() ; iter++) {
        
        //Assign it to a string stream
        stringstream rstream(*iter);
        
        istream_iterator<string> runner(rstream);
        istream_iterator<string> end;
        
        //This holds the main attribute of the sentence, meaning what to do with the information
        string strFirst = *runner;
        
        //Go to the value stored
        ++runner;
        
        switch (parseWord(strFirst)) {
                
                //Each of the following cases just assignes values
            case ParseTypeID:
                
                //The strings converts to type
                ID = atoi((*runner).data());
                break;
                
            case ParseTypePlayerSpeedMax:
                
                playerSpeedMax = atof((*runner).data());
                break;
                
            case ParseTypeStaminaIncMax:
                
                StaminaIncMax = atof((*runner).data());
                break;
 
            case ParseTypePlayerDecay:
                
                playerDecay = atof((*runner).data());
                break;
                
            case ParseTypeInertiaMoment:
                
                inertiaMoment = atof((*runner).data());
                break;
                                
            case ParseTypeDashPowerRate:
                
                dashPowerRate = atof((*runner).data());
                break;
                
            case ParseTypePlayerSize:
                
                playerSize = atof((*runner).data());
                break;
                
            case ParseTypeKickableMargin:
                
                kickableMargin = atof((*runner).data());
                break;

            case ParseTypeKickRand:
                
                kickRand = atof((*runner).data());
                break;

            case ParseTypeExtraStamina:
                
                extraStamina = atof((*runner).data());
                break;
                
            case ParseTypeEffortMax:
                
                effortMax = atof((*runner).data());
                break;
                
            case ParseTypeEffortMin:
                
                effortMin = atof((*runner).data());
                break;

            case ParseTypeKickPowerRate:
                
                kickPowerRate = atof((*runner).data());
                break;
                
            case ParseTypeFoulDetectProbability:
                
                foulDetectProbability = atof((*runner).data());
                break;

            case ParseTypeCatchableAreaLStretch:
                
                catchableAreaLStretch = atof((*runner).data());
                break;

            default:
                break;
        }
        
        
    }
    
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: PlayerState Constructor                                                       *
 * The Input: map<string, ParseType>                                                            *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with input as reference map for types.         *
 * *********************************************************************************************/

PlayerState::PlayerState(const std::map<std::string, ParseType>& cParseMap) :
State(cParseMap, StateTypePlayer) { }

/**********************************************************************************************
 * function name: PlayerState Destructor                                                      *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Destroys the current object.                                        *
 * *******************************************************************************************/

PlayerState::~PlayerState() {
}

