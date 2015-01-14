/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Implementation of ServerState Class    *
 ***********************************************************/

#include "ServerState.h"
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <iterator>

#define MISSING_PARSE_MESSAGE "ServerState error: Missing a parse case- "

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

void ServerState::assignValues(const std::vector<std::string>& vcSentences) {
    
    //First value always indicates the state type
    for (vector<string>::const_iterator iter = vcSentences.begin()+1 ; iter != vcSentences.end() ; iter++) {
        
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
            case ParseTypeAudioCutDistance:
                
                //The strings converts to type
                audioCutDistance = atof((*runner).data());
                break;
                
            case ParseTypeAutoMode:
                
                autoMode = atoi((*runner).data());
                break;
                
            case ParseTypeBackDashRate:
                
                backDashRate = atof((*runner).data());
                break;
                
            case ParseTypeBackPasses:
                
                backPasses = atof((*runner).data());
                break;
                
            case ParseTypeBallAccelerationMax:
                
                ballAccelerationMax = atof((*runner).data());
                break;

            case ParseTypeBallDecay:

                ballDecay = atof((*runner).data());
                break;

            case ParseTypeBallRandom:

                ballRand = atof((*runner).data());
                break;

            case ParseTypeBallSize:

                ballSize = atof((*runner).data());
                break;

            case ParseTypeBallSpeedMax:

                ballSpeedMax = atof((*runner).data());
                break;

            case ParseTypeBallWeight:
                
                ballWeight = atof((*runner).data());
                break;
                
            case ParseTypeCatchBanCycle:
                
                catchBanCycle = atoi((*runner).data());
                break;
                
            case ParseTypeCatchProbability:
                
                catchProbability = atof((*runner).data());
                break;
                
                case ParseTypeCatchableAreaL:
                
                catchableAreaL = atof((*runner).data());
                break;
                
            case ParseTypeCatchableAreaW:
                
                catchableAreaW = atof((*runner).data());
                break;

            case ParseTypeGoalieMaxMoves:
                
                goalieMaxMoves = atoi((*runner).data());
                break;
                
            case ParseTypeCKickMargin:
                
                cornerKickMargin = atof((*runner).data());
                break;

            case ParseTypeClangAdviceWin:
                
                coachLanguageAdviceWindow = atoi((*runner).data());
                break;
                
            case ParseTypeClangDefineWin:
                
                coachLanguageDefineWindow = atoi((*runner).data());
                break;
                
            case ParseTypeClangDelWin:
                
                coachLanguageDelWindow = atoi((*runner).data());
                break;
                
            case ParseTypeClangInfoWin:
                
                coachLanguageInfoWindow = atoi((*runner).data());
                break;
                
            case ParseTypeClangMessDelay:
                
                coachLanguageMessDelay = atoi((*runner).data());
                break;
                
            case ParseTypeClangMessPerCycle:
                
                coachLanguageMessPerCycle = atoi((*runner).data());
                break;

            case ParseTypeClangMetaWin:
                
                coachLanguageMetaWindow = atoi((*runner).data());
                break;
                
            case ParseTypeClangRuleWin:
                
                coachLanguageRuleWindow = atoi((*runner).data());
                break;

            case ParseTypeClangWinSize:
                
                coachLanguageWindowSize = atoi((*runner).data());
                break;
                
            case ParseTypeSayCoachCntMax:
                
                coachMaxSayCount = atoi((*runner).data());
                break;
                
            case ParseTypeSayCoachMessageSize:
                
                coachMaxMessageSize = atoi((*runner).data());
                break;

            case ParseTypeCoach:
                
                coachMode = atoi((*runner).data());
                break;

            case ParseTypeCoachPort:
                
                coachPort = atoi((*runner).data());
                break;

            case ParseTypeOldCoachHear:
                
                oldCoachHearFormat = atoi((*runner).data());
                break;

            case ParseTypeOlCoachPort:
                
                onlineCoachPort = atoi((*runner).data());
                break;
                
            case ParseTypeCoachWithReferee:
                
                coachWithRefereeMode = atoi((*runner).data());
                break;
                
            case ParseTypeBallStuckArea:
                
                ballStuckArea = atof((*runner).data());
                break;

            case ParseTypeSendViStep:
                
                sendViStep = atoi((*runner).data());
                break;
                
            case ParseTypeConnectWait:
                
                connectWait = atoi((*runner).data());
                break;
                
            case ParseTypeControlRadius:
                
                controlRadius = atof((*runner).data());
                break;

            case ParseTypeDashAngleStep:
                
                dashAngleStep = atof((*runner).data());
                break;

            case ParseTypeDashPowerRate:
                
                dashPowerRate = atof((*runner).data());
                break;
                
            case ParseTypeInertiaMoment:
                
                inertiaMoment = atof((*runner).data());
                break;

            case ParseTypeDropBallTime:
                
                dropBallTime = atoi((*runner).data());
                break;
                
            case ParseTypeEffortDecrement:
                
                dashEffortDecriment = atof((*runner).data());
                break;
                
            case ParseTypeEffortDecrementThreshold:
                
                dashEffortDecrimentThreshold = atof((*runner).data());
                break;
                
            case ParseTypeEffortIncrease:
                
                dashEffortIncriment = atof((*runner).data());
                break;
                
            case ParseTypeEffortIncreaseThreshold:
                
                dashEffortIncrimentThreshold = atof((*runner).data());
                break;
                
            case ParseTypeEffortInit:
                
                dashEffortInit = atof((*runner).data());
                break;
                
            case ParseTypeEffortMin:
                
                dashEffortMin = atof((*runner).data());
                break;
                
            case ParseTypeHearDecay:
                
                playerHearDecay = atoi((*runner).data());
                break;
                
            case ParseTypeHearInc:
                
                playerHearInc = atoi((*runner).data());
                break;
                
            case ParseTypeHearMax:
                
                playerHearMax = atoi((*runner).data());
                break;
                
            case ParseTypePlayerAccelerationMax:
                
                playerAccelerationMax = atof((*runner).data());
                break;
                
            case ParseTypePlayerDecay:
                
                playerDecay = atof((*runner).data());
                break;
                
            case ParseTypePlayerRand:
                
                playerRand = atof((*runner).data());
                break;

            case ParseTypePlayerSize:
                
                playerSize = atof((*runner).data());
                break;

            case ParseTypePlayerSpeedMax:
                
                playerSpeedMax = atof((*runner).data());
                break;
                
            case ParseTypePlayerSpeedMaxMin:
                
                playerSpeedMaxMin = atof((*runner).data());
                break;
                
            case ParseTypePlayerWeight:
                
                playerWeight = atof((*runner).data());
                break;
                
            case ParseTypeStaminaIncMax:
                
                playerStaminaIncrement = atof((*runner).data());
                break;

            case ParseTypeStaminaMax:
                
                playerStaminaMax = atof((*runner).data());
                break;

            case ParseTypeRecoverDec:
                
                playerRecoveryDecriment = atof((*runner).data());
                break;

            case ParseTypeRecoverDecThr:
                
                playerRecoveryDecrimentThreshold = atof((*runner).data());
                break;

            case ParseTypeRecoverInit:
                
                playerRecoveryInit = atof((*runner).data());
                break;
                
            case ParseTypeRecoverMin:
                
                playerRecoveryMin = atof((*runner).data());
                break;

            case ParseTypeExtraHalfTime:
                
                extraHalfTime = atoi((*runner).data());
                break;
                
            case ParseTypeExtraStamina:
                
                extraStamina = atof((*runner).data());
                break;
                
            case ParseTypeForbidKickOffOffside:
                
                forbidKickOffOffside = atoi((*runner).data());
                break;
                
            case ParseTypeFoulCycles:
                
                foulCycles = atoi((*runner).data());
                break;
                
            case ParseTypeFoulDetectProbability:
                
                foulDetectProbability = atof((*runner).data());
                break;
                
            case ParseTypeFoulExponent:
                
                foulExponent = atof((*runner).data());
                break;

            case ParseTypeFreeKickFaults:
                
                freeKickFaults = atoi((*runner).data());
                break;
                
            case ParseTypeFreeformSendPeriod:
                
                freeformSendPeriod = atoi((*runner).data());
                break;

            case ParseTypeFreeformWaitPeriod:
                
                freeformWaitPeriod = atoi((*runner).data());
                break;
                
            case ParseTypeFullStateL:
                
                fullstateL = atoi((*runner).data());
                break;
                
            case ParseTypeFullStateR:
                
                fullstateR = atoi((*runner).data());
                break;

            case ParseTypeGameLogCompression:
                
                gameLogCompression = atoi((*runner).data());
                break;
                
            case ParseTypeGameLogDated:
                
                gameLogDated = atoi((*runner).data());
                break;

            case ParseTypeGameLogDirectory:
                
                gameLogDirectory = *runner;
                break;

            case ParseTypeGameLogFixed:
                
                gameLogFixed = atoi((*runner).data());
                break;

            case ParseTypeGameLogFixedName:
                
                gameLogFixedName = *runner;
                break;
                
            case ParseTypeGameLogVersion:
                
                gameLogVersion = atoi((*runner).data());
                break;

            case ParseTypeGameLogging:
                
                gameLogging = atoi((*runner).data());
                break;

            case ParseTypeGameOverWait:
                
                gameOverWait = atoi((*runner).data());
                break;
                
            case ParseTypeLandmarkFile:
                
                landmarkFile = *runner;
                break;

            case ParseTypeLogDateFormat:
                
                logDateFormat = *runner;
                break;

            case ParseTypeLogTimes:
                
                logTimes = atoi((*runner).data());
                break;

            case ParseTypeTextLogCompression:
                
                textLogCompression = atoi((*runner).data());
                break;

            case ParseTypeTextLogDated:
                
                textLogDated = atoi((*runner).data());
                break;

            case ParseTypeTextLogDir:
                
                textLogDirectory = *runner;
                break;
                
            case ParseTypeTextLogFixed:
                
                textLogFixed = atoi((*runner).data());
                break;

            case ParseTypeTextLogFixedName:
                
                textLogFixedName = *runner;
                break;

            case ParseTypeTextLogging:
                
                textLogging = atoi((*runner).data());
                break;

            case ParseTypeGoalWidth:
                
                goalWidth = atof((*runner).data());
                break;

            case ParseTypeGoldenGoal:
                
                goldenGoal = atoi((*runner).data());
                break;
                
            case ParseTypeHalfTime:
                
                halfTime = atoi((*runner).data());
                break;
              
            case ParseTypeKeepAway:
                
                keepAway = atoi((*runner).data());
                break;
                
            case ParseTypeKeepAwayLength:
                
                keepAwayLength = atof((*runner).data());
                break;

            case ParseTypeKeepAwayLogDated:
                
                keepAwayLogDated = atoi((*runner).data());
                break;
          
            case ParseTypeKeepAwayLogDir:
                
                keepAwayLogDirectory = *runner;
                break;

            case ParseTypeKeepAwayLogFixed:
                
                keepAwayLogFixed = atoi((*runner).data());
                break;

            case ParseTypeKeepAwayLogFixedName:
                
                keepAwayLogFixedName = *runner;
                break;

            case ParseTypeKeepAwayLogging:
                
                keepAwayLogging = atoi((*runner).data());
                break;

            case ParseTypeKeepAwayStart:
                
                keepAwayStart = atoi((*runner).data());
                break;
                
            case ParseTypeKeepAwayWidth:
                
                keepAwayWidth = atof((*runner).data());
                break;

            case ParseTypeKickOffWait:
                
                kickOffWait = atoi((*runner).data());
                break;

            case ParseTypeKickPowerRate:
                
                kickPowerRate = atof((*runner).data());
                break;
                
            case ParseTypeKickRand:
                
                kickRandom = atof((*runner).data());
                break;

            case ParseTypeKickRandFactorL:
                
                kickRandomFactorLeft = atof((*runner).data());
                break;
                
            case ParseTypeKickRandFactorR:
                
                kickRandomFactorRight = atof((*runner).data());
                break;

            case ParseTypeKickableMargin:
                
                kickableMargin = atof((*runner).data());
                break;

            case ParseTypeMaxBackTacklePower:
                
                maxBackTacklePower = atof((*runner).data());
                break;

            case ParseTypeMaxDashAngle:
                
                maxDashAngle = atof((*runner).data());
                break;
                
            case ParseTypeMaxDashPower:
                
                maxDashPower = atof((*runner).data());
                break;
                
            case ParseTypeMaxGoalKicks:
                
                maxGoalKicks = atoi((*runner).data());
                break;

            case ParseTypeMaxTacklePower:
                
                maxTacklePower = atof((*runner).data());
                break;
                
            case ParseTypeMinMoment:
                
                minMoment = atof((*runner).data());
                break;

            case ParseTypeMaxMoment:
                
                maxMoment = atof((*runner).data());
                break;
   
            case ParseTypeMaxNeckAngle:
                
                maxNeckAngle = atof((*runner).data());
                break;

            case ParseTypeMinNeckAngle:
                
                minNeckAngle = atof((*runner).data());
                break;

            case ParseTypeMinNeckMoment:
                
                minNeckMoment = atof((*runner).data());
                break;

            case ParseTypeMaxNeckMoment:
                
                maxNeckMoment = atof((*runner).data());
                break;

            case ParseTypeMaxPower:
                
                maxPower = atof((*runner).data());
                break;

            case ParseTypeMinPower:
                
                minPower = atof((*runner).data());
                break;

            case ParseTypeMinDashAngle:
                
                minDashAngle = atof((*runner).data());
                break;

            case ParseTypeMinDashPower:
                
                minDashPower = atof((*runner).data());
                break;

            case ParseTypeNRExtraHalfs:
                
                nrExtraHalfs = atoi((*runner).data());
                break;
                
            case ParseTypeNRNormalHalfs:
                
                nrNormalHalfs = atoi((*runner).data());
                break;
                
            case ParseTypeOffsideActiveAreaSize:
                
                offsideActiveAreaSize = atof((*runner).data());
                break;
                
            case ParseTypeOffsideKickMargin:
                
                offsideKickMargin = atof((*runner).data());
                break;
                
            case ParseTypeUseOffside:
                
                useOffside = atoi((*runner).data());
                break;

            case ParseTypePenAllowMultipleKicks:
                
                penAllowMultipleKicks = atoi((*runner).data());
                break;

            case ParseTypePenBeforeSetupWait:
                
                penBeforeSetupWait = atoi((*runner).data());
                break;
                
            case ParseTypePenCoachMovesPlayers:
                
                penCoachMovesPlayers = atoi((*runner).data());
                break;

            case ParseTypePenDistanceX:
                
                penDistanceX = atof((*runner).data());
                break;

            case ParseTypePenMaxExtraKicks:
                
                penMaxExtraKicks = atoi((*runner).data());
                break;
                
            case ParseTypePenMaxGoalieDistanceX:
                
                penMaxGoalieDistanceX = atof((*runner).data());
                break;

            case ParseTypePenNRKicks:
                
                penNumberOfKicks = atoi((*runner).data());
                break;

            case ParseTypePenRandomWinner:
                
                penRandomWinner = atoi((*runner).data());
                break;
                
            case ParseTypePenReadyWait:
                
                penReadyWait = atoi((*runner).data());
                break;

            case ParseTypePenSetupWait:
                
                penSetupWait = atoi((*runner).data());
                break;

            case ParseTypePenTakenWait:
                
                penTakenWait = atoi((*runner).data());
                break;

            case ParseTypePenaltyShootOuts:
                
                penaltyShootOuts = atoi((*runner).data());
                break;
                
            case ParseTypeRedCardProbability:
                
                redCardProbability = atof((*runner).data());
                break;

            case ParseTypePointsToBan:
                
                pointsToBan = atoi((*runner).data());
                break;
                
            case ParseTypePointsToDuration:
                
                pointsToDuration = atoi((*runner).data());
                break;
                
            case ParseTypePort:
                
                port = atoi((*runner).data());
                break;

            case ParseTypePRandFactorL:
                
                teamLeftRandomFactor = atof((*runner).data());
                break;
                
            case ParseTypePRandFactorR:
                
                teamRightRandomFactor = atof((*runner).data());
                break;
                
            case ParseTypeProfile:
                
                profile = atoi((*runner).data());
                break;
                
            case ParseTypeProperGoalKicks:
                
                properGoalKicks = atoi((*runner).data());
                break;
                
            case ParseTypeQuantizeStep:
                
                quantizeStepDistance = atof((*runner).data());
                break;
                
            case ParseTypeQuantizeStepL:
                
                quantizeStepDistanceLandmark = atof((*runner).data());
                break;
                
            case ParseTypeRecordMessages:
                
                recordMessages = atoi((*runner).data());
                break;

            case ParseTypeRecieveStep:
                
                recieveStep = atoi((*runner).data());
                break;

            case ParseTypeSayMessageSize:
                
                sayMessageSize = atoi((*runner).data());
                break;
                
            case ParseTypeSendComms:
                
                sendComms = atoi((*runner).data());
                break;
                
            case ParseTypeSendStep:
                
                sendStep = atoi((*runner).data());
                break;
                
            case ParseTypeSideDashRate:
                
                sideDashRate = atof((*runner).data());
                break;

            case ParseTypeSimulatorStep:
                
                simulatorStep = atoi((*runner).data());
                break;

            case ParseTypeSlowDownFactor:
                
                slowDownFactor = atoi((*runner).data());
                break;
                
            case ParseTypeSlownessOnTopForLeftTeam:
                
                slownessOnTopForLeftTeam = atoi((*runner).data());
                break;
                
            case ParseTypeSlownessOnTopForRightTeam:
                
                slownessOnTopForRightTeam = atoi((*runner).data());
                break;
                
            case ParseTypeStaminaCapacity:
                
                staminaCapacity = atof((*runner).data());
                break;
                
            case ParseTypeStartGoalL:
                
                startGoalLeft = atoi((*runner).data());
                break;

            case ParseTypeStartGoalR:
                
                startGoalRight = atoi((*runner).data());
                break;
                
            case ParseTypeStoppedBallVel:
                
                stoppedBallVel = atof((*runner).data());
                break;
                
            case ParseTypeSynchMicroSleep:
                
                synchMicroSleep = atoi((*runner).data());
                break;
                
            case ParseTypeSynchMode:
                
                synchMode = atoi((*runner).data());
                break;
                
            case ParseTypeSynchOffset:
                
                synchOffset = atoi((*runner).data());
                break;
                
            case ParseTypeSynchSeeOffset:
                
                synchSeeOffset = atoi((*runner).data());
                break;
                
            case ParseTypeTackleBackDist:
                
                tackleBackDistance = atof((*runner).data());
                break;

            case ParseTypeTackleCycles:
                
                tackleCycles = atoi((*runner).data());
                break;

            case ParseTypeTackleDist:
                
                tackleDistance = atof((*runner).data());
                break;
                
            case ParseTypeTackleExponent:
                
                tackleExponent = atof((*runner).data());
                break;

            case ParseTypeTacklePowerRate:
                
                tacklePowerRate = atof((*runner).data());
                break;

            case ParseTypeTackleRandFactor:
                
                tackleRandFactor = atof((*runner).data());
                break;
                
            case ParseTypeTackleWidth:
                
                tackleWidth = atof((*runner).data());
                break;
                
            case ParseTypeTeamActuatorNoise:
                
                teamActuatorNoise = atoi((*runner).data());
                break;

            case ParseTypeTeamLStart:
                
                teamLeftStart = *runner;
                break;

            case ParseTypeTeamRStart:
                
                teamLeftRight = *runner;
                break;
                
            case ParseTypeVerbose:
                
                verbose = atoi((*runner).data());
                break;
                
            case ParseTypeVisibleAngle:
                
                visibleAngle = atof((*runner).data());
                break;
                
            case ParseTypeVisibleDistance:
                
                visibleDistance = atof((*runner).data());
                break;
                
            case ParseTypeSenseBodyStep:
                
                senseBodyStep = atoi((*runner).data());
                break;
                
            case ParseTypeWindDir:
                
                windDirection = atof((*runner).data());
                break;
                
            case ParseTypeWindForce:
                
                windForce = atof((*runner).data());
                break;
                
            case ParseTypeWindAng:
                
                windAngle = atof((*runner).data());
                break;
                
            case ParseTypeWindRand:
                
                windRand = atof((*runner).data());
                break;
                
            case ParseTypeWindNone:
                
                windNone = atoi((*runner).data());
                break;

            case ParseTypeWindRandom:
                
                windRandom = atoi((*runner).data());
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
 * function name: ServerState Constructor                                                       *
 * The Input: map<string, ParseType>                                                            *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with input as reference map for types.         *
 * *********************************************************************************************/

ServerState::ServerState(const std::map<std::string, ParseType>& cParseMap) :
State(cParseMap, StateTypeServer) { }

/**********************************************************************************************
 * function name: PlayerState Destructor                                                      *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Destroys the current object.                                        *
 * *******************************************************************************************/

ServerState::~ServerState() { }

