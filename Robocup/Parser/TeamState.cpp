/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Implementation of TeamState Class      *
 ***********************************************************/

#include "TeamState.h"
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <iterator>
#include "HearState.h"

#define SERVER_STATE_KEYWORD_TEAM_SIDE_RIGHT "r"
#define SERVER_STATE_KEYWORD_TEAM_SIDE_LEFT "l"
#define MISSING_PARSE_MESSAGE "TeamState error: Missing a parse case- "
#define SPECIAL_CASE_INIT "init"


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

void TeamState::assignValues(const std::vector<std::string>& vcSentences) {
    
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
            case ParseTypeInit:
                
            {
                
                //The next property is the TeamSide
                if (*runner == SERVER_STATE_KEYWORD_TEAM_SIDE_LEFT)
                    teamSide = TeamSideLeft;
                else if (*runner == SERVER_STATE_KEYWORD_TEAM_SIDE_RIGHT)
                    teamSide = TeamSideRight;
                
                //The next property is the player number
                ++runner;
                
                unum = atoi((*runner).data());
                
                //The next property is the GameType
                ++runner;
                
                
                //Instead of handling as a unique case for everyone, just compare the ints
                playMode = static_cast<PlayMode>(parseWord(*runner));
                
                break;
                
            }
                
            case ParseTypePlayerParam:
                
                //This is just an empty property
                break;
                
                //Each of the following cases just assignes values
            case ParseTypeAllowMultipleDefaultType:
                
                //The strings converts to type
                allowMultipleDefaultType = atoi((*runner).data());
                break;
                
            case ParseTypeCatchableAreaLStretchMax:
                
                //The strings converts to type
                catchableAreaLStretchMax = atof((*runner).data());
                break;
                
            case ParseTypeCatchableAreaLStretchMin:
                
                //The strings converts to type
                catchableAreaLStretchMin = atof((*runner).data());
                break;
                
            case ParseTypeDashPowerRateDeltaMax:
                
                //The strings converts to type
                dashPowerRateDeltaMax = atof((*runner).data());
                break;
                
            case ParseTypeDashPowerRateDeltaMin:
                
                //The strings converts to type
                dashPowerRateDeltaMin = atof((*runner).data());
                break;

            case ParseTypeEffortMaxDeltaFactor:
                
                //The strings converts to type
                effortMaxDeltaFactor = atof((*runner).data());
                break;

            case ParseTypeEffortMinDeltaFactor:
                
                //The strings converts to type
                effortMinDeltaFactor = atof((*runner).data());
                break;

            case ParseTypeExtraStaminaDeltaMax:
                
                //The strings converts to type
                extraStaminaDeltaMax = atof((*runner).data());
                break;
                
            case ParseTypeExtraStaminaDeltaMin:
                
                //The strings converts to type
                extraStaminaDeltaMin = atof((*runner).data());
                break;
                                
            case ParseTypeFoulDetectProbabilityDeltaFactor:
                
                //The strings converts to type
                foulDetectProbabilityDeltaFactor = atof((*runner).data());
                break;

            case ParseTypeInertiaMomentDeltaFactor:
                
                //The strings converts to type
                inertiaMomentDeltaFactor = atof((*runner).data());
                break;
                
            case ParseTypeKickPowerRateDeltaMax:
                
                //The strings converts to type
                kickPowerRateDeltaMax = atof((*runner).data());
                break;
                
            case ParseTypeKickPowerRateDeltaMin:
                
                //The strings converts to type
                kickPowerRateDeltaMin = atof((*runner).data());
                break;

            case ParseTypeKickRandDeltaFactor:
                
                //The strings converts to type
                kickRandDeltaFactor = atof((*runner).data());
                break;
                
            case ParseTypeKickableMarginDeltaMax:
                
                //The strings converts to type
                kickableMarginDeltaMax = atof((*runner).data());
                break;
                
            case ParseTypeKickableMarginDeltaMin:
                
                //The strings converts to type
                kickableMarginDeltaMin = atof((*runner).data());
                break;

            case ParseTypeNewDashPowerRateDeltaMax:
                
                //The strings converts to type
                newDashPowerRateDeltaMax = atof((*runner).data());
                break;

            case ParseTypeNewDashPowerRateDeltaMin:
                
                //The strings converts to type
                newDashPowerRateDeltaMin = atof((*runner).data());
                break;

            case ParseTypeNewStaminaIncMaxDeltaFactor:
                
                //The strings converts to type
                newStaminaIncMaxDeltaFactor = atof((*runner).data());
                break;
                
            case ParseTypePlayerDecayDeltaMax:
                
                //The strings converts to type
                playerDecayDeltaMax = atof((*runner).data());
                break;
                
            case ParseTypePlayerDecayDeltaMin:
                
                //The strings converts to type
                playerDecayDeltaMin = atof((*runner).data());
                break;

            case ParseTypePlayerSizeDeltaFactor:
                
                //The strings converts to type
                playerSizeDeltaFactor = atof((*runner).data());
                break;

            case ParseTypePlayerSpeedMaxDeltaMax:
                
                //The strings converts to type
                playerSpeedMaxDeltaMax = atof((*runner).data());
                break;

            case ParseTypePlayerSpeedMaxDeltaMin:
                
                //The strings converts to type
                playerSpeedMaxDeltaMin = atof((*runner).data());
                break;
                
            case ParseTypePlayerTypes:
                
                //The strings converts to type
                playerTypes = atoi((*runner).data());
                break;

            case ParseTypePtMax:
                
                //The strings converts to type
                ptMax = atof((*runner).data());
                break;
                
            case ParseTypeRandomSeed:
                
                //The strings converts to type
                randomSeed = atoi((*runner).data());
                break;
                
            case ParseTypeStaminaIncMaxDeltaFactor:
                
                //The strings converts to type
                staminaIncMaxDeltaFactor = atof((*runner).data());
                break;
                
            case ParseTypeSubsMax:
                
                //The strings converts to type
                subsMax = atoi((*runner).data());
                break;
            
            //Shouldnt reach here
            default:
                cerr << MISSING_PARSE_MESSAGE << strFirst << endl;
                break;
        }
        
        
    }
    
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: TeamState Constructor                                                         *
 * The Input: map<string, ParseType>                                                            *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with input as reference map for types.         *
 * *********************************************************************************************/

TeamState::TeamState(const std::map<std::string, ParseType>& cParseMap) :
State(cParseMap, StateTypeTeam) { }

/**********************************************************************************************
 * function name: TeamState Destructor                                                        *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Destroys the current object.                                        *
 * *******************************************************************************************/

TeamState::~TeamState() { }

/**********************************************************************************************
 * function name: convert                                                                     *
 * The Input: const HearState object (reference)                                              *
 * The output: none                                                                           *
 * The Function Opertion: Parses the message and sees it it changed the current PlayMode,     *
 *                        It's the only value that can be changed for the TeamState.          *
 * *******************************************************************************************/

bool TeamState::convert(const HearState& cHearState) {
    
    //Parse the message - only PlayModes can be updated from this
    int iMessage = parseWord(cHearState.message);
    
    //Check if valid
    if (iMessage < ParseTypePMTotalNumber && iMessage >= ParseTypePMNull) {
        
        //Update the PlayMode
        playMode = static_cast<PlayMode>(iMessage);
        return true;
        
    }
    else
        //No change made
        return false;
    
}

