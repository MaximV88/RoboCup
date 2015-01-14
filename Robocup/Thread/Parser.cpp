/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Implementation of Parser Class         *
 ***********************************************************/

#include "Parser.h"
#include "ParserErrorDefinitions.h"
#include "ParserParseDefinitions.h"

#define ERROR_MESSAGE "Error: "
#define ERROR_MESSAGE_MISSING "Parser error: Missing a parse case"


using namespace std;
using namespace parse;

//  ---                         PRIVATE FUNCTIONS                       ---   //


/****************************************************************************************************
 * function name: execute                                                                           *
 * The Input: none                                                                                  *
 * The output: none                                                                                 *
 * The Function Opertion: Takes a string input from the queue (that had it's object inserted in the *
 *                        ConnectionHandler), and validates it. If not validated, prints and error  *
 *                        and pushes it to the error queue to be handled in the ConnectionHandler.  *
 *                        If valid, continues to parse it and sends for parsing in another function.*
 *                        That function (parseValidInput) returns a State that corresponds to the   *
 *                        input.                                                                    *
 * *************************************************************************************************/

void Parser::execute() {
    
    //Should always parse incoming data - the incoming information should have been validated before
    while (true) {
        
        //Get a string to parse from the queue - this will hold the thread
        string* strInput = m_qInputQueue.pop();

        /*
         * Check if the input is valid, the check is very short.
         */
        
        ErrorType eErrorType = validate(*strInput);
        
        if (eErrorType != ErrorTypeNone) {
            
            cerr << ERROR_MESSAGE << *strInput << endl;
            
            /*
             * An error was recieved from server.
             * Since the parser cant handle errors, make it accessible for others.
             */
            m_qErrorQueue.push(eErrorType);
            
        }
        else {
        
        
        //Parse the input and add it to the queue
        m_qStateQueue.push(parseValidInput(*strInput));
        
            
        }

        //We are done with the input
        delete strInput;
        
    }

}

/****************************************************************************************************
 * function name: parseValidInput                                                                   *
 * The Input: const string object (reference)                                                       *
 * The output: State object (pointer)                                                               *
 * The Function Opertion: Gets the first word from the input string, and assignes the string        *
 *                        for parsing with the appropriate State. The state gets updated from       *
 *                        the input and a copy is returned (as a pointer) of that state.            *
 * *************************************************************************************************/

State* Parser::parseValidInput(const std::string& strInput) {
    
    //Get the first word (until the ' ')
    size_t iBreak = strInput.find_first_of(' ');
    
    //Ignore the first '('
    string strFirst = string(strInput.data()+1, iBreak-1);
    
    switch (m_cParseMap.find(strFirst)->second) {
            
        case ParseTypeServerParameters:
            
            //This will initialize the server, thus Parse a ServerState
            m_cServerState.parseUpdatedInput(strInput);
            return new ServerState(m_cServerState);
            
        case ParseTypeInit:
            
            //This will initialize the team, this is a special case
            m_cTeamState.parseUpdatedInput(strInput);
            return new TeamState(m_cTeamState);
            
        case ParseTypePlayerParam:
            
            //This will initialize game related properties, thus Parse a GameState
            m_cTeamState.parseUpdatedInput(strInput);
            return new TeamState(m_cTeamState);
            
        case ParseTypePlayerType:
            
            //This will initialize the player, thus Parse a PlayerState
            m_cPlayerState.parseUpdatedInput(strInput);
            return new PlayerState(m_cPlayerState);
            
        case ParseTypeSenseBody:
            
            //This will initialize the body, thus Parse a BodyState
            m_cBodyState.parseUpdatedInput(strInput);
            return new BodyState(m_cBodyState);
            
        case ParseTypeSee:
            
        {
            
            //This should be renewed all the time
            SeeState *cSeeState = new SeeState(m_cParseMap);
            cSeeState->parseUpdatedInput(strInput);
            return cSeeState;
            
        }
            
        case ParseTypeHear:
            
        {
            
            //This should be renewed all the time
            HearState *cHearState = new HearState(m_cParseMap);
            cHearState->parseUpdatedInput(strInput);
            return cHearState;
            
        }
            
        default:
            
            //Missed a case- this will print to terminal to be handled manually
            cerr << ERROR_MESSAGE_MISSING << endl;
            return NULL;
            
    }
    
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: Parser Constructor                                                            *
 * The Input: ThreadQueue<State*> object (reference), ThreadQueue<ErrorType> object (reference) *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the member variable queues, and builds the map (calls     *
 *                        functions that assign each key string to it's type). Then it starts   *
 *                        the Parser's thread.                                                  *
 * *********************************************************************************************/

Parser::Parser(ThreadQueue<State*>& qStateQueue, ThreadQueue<ErrorType>& qErrorQueue) :
m_qStateQueue(qStateQueue), m_qErrorQueue(qErrorQueue), m_cServerState(m_cParseMap),
m_cTeamState(m_cParseMap), m_cBodyState(m_cParseMap), m_cPlayerState(m_cParseMap) {
    
    //Build the maps
    buildErrorMap();
    buildParseMap();
    
    //The object needs to start immidiatly
    start();
    
}

/**********************************************************************************************
 * function name: Parser Destructor                                                           *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Destroys the current object.                                        *
 * *******************************************************************************************/

Parser::~Parser() { }

/**********************************************************************************************
 * function name: parse                                                                       *
 * The Input: const char* (pointer)                                                           *
 * The output: none                                                                           *
 * The Function Opertion: Pushes a c string input into a queue as a c++ string, that queue    *
 *                        will be used by another function to take that c++ string out and    *
 *                        parse it.                                                           *
 * *******************************************************************************************/

void Parser::parse(const char *chInput) {
    
    //The queue can handle multiple thread accesses and no need to lock an object that locks
    m_qInputQueue.push(new string(chInput));
    
}

/**********************************************************************************************
 * function name: validate                                                                    *
 * The Input: const string object (reference)                                                 *
 * The output: ErrorType                                                                      *
 * The Function Opertion: Takes the first word from the input string, and checks if its not   *
 *                        of a warning or error type. Returns the type inferred.              *
 * *******************************************************************************************/

ErrorType Parser::validate(const std::string& strInput) {
    
    //Get the first word (until the ' ')
    size_t iBreak = strInput.find_first_of(' ');
    
    //Ignore the first '('
    string strFirst = string(strInput.data()+1, iBreak-1);
    
    //Check for Error/Warning
    switch (m_cParseMap.find(strFirst)->second) {
        case ParseTypeError:
        case ParseTypeWarning:
            
            //The Error/Warning type is stored in the error map
            return m_cErrorMap.find(string(strInput.data()+iBreak+1, strInput.length() - iBreak - 2))->second;
            break;
        default:
            
            //The input is valid
            return ErrorTypeNone;
            break;
    }
    
}

//  ---                         PRIVATE FUNCTIONS                       ---   //


/****************************************************************************************************
 * function name: buildErrorMap                                                                     *
 * The Input: none                                                                                  *
 * The output: none                                                                                 *
 * The Function Opertion: Assignes each string key to it's type value.                              *
 * *************************************************************************************************/

void Parser::buildErrorMap() {
    
    //In order to convert strings to enums, in a constant time, a map is used
    m_cErrorMap[PARSER_KEYWORD_ERROR_ILLEGAL_COMMAND_FORM] = ErrorTypeErrorIlligalCommandForm;
    m_cErrorMap[PARSER_KEYWORD_ERROR_ILLEGAL_MODE] = ErrorTypeErrorIllegalMode;
    m_cErrorMap[PARSER_KEYWORD_ERROR_ILLEGAL_OBJECT_FORM] = ErrorTypeErrorIllegalObjectForm;
    m_cErrorMap[PARSER_KEYWORD_ERROR_NO_MORE_TEAM_OR_PLAYER] = ErrorTypeErrorNoMoreTeamOrPlayer;
    m_cErrorMap[PARSER_KEYWORD_ERROR_NO_MORE_TEAM_OR_PLAYER_OR_GOALIE] = ErrorTypeErrorNoMoreTeamOrPlayerOrGoalie;
    m_cErrorMap[PARSER_KEYWORD_ERROR_NO_MORE_PLAYER_OR_GOALIE_OR_ILLEGAL_CLIENT_VERSION] = ErrorTypeErrorNoMorePlayerOrGoalieorIllegalClientVersion;
    m_cErrorMap[PARSER_KEYWORD_ERROR_SAID_TOO_MANY_MESSAGES] = ErrorTypeErrorSaidTooManyMessages;
    m_cErrorMap[PARSER_KEYWORD_ERROR_TOO_MANY_MOVES] = ErrorTypeErrorTooManyMoves;
    m_cErrorMap[PARSER_KEYWORD_ERROR_UNKNOWN_COMMAND] = ErrorTypeErrorUnknownCommand;
    m_cErrorMap[PARSER_KEYWORD_WARNING_CANNOT_CHANGE_GOALIE] = ErrorTypeWarningCannotChangeGoalie;
    m_cErrorMap[PARSER_KEYWORD_WARNING_CANNOT_SUB_WHILE_PLAYON] = ErrorTypeWarningCannotSubWhilePlayon;
    m_cErrorMap[PARSER_KEYWORD_WARNING_COMPRESSION_UNSUPPORTED] = ErrorTypeWarningCompressionUnsupported;
    m_cErrorMap[PARSER_KEYWORD_WARNING_MAX_OF_THAT_TYPE_ON_FIELD] = ErrorTypeWarningMaxOfThatTypeOnField;
    m_cErrorMap[PARSER_KEYWORD_WARNING_NO_SUBS_LEFT] = ErrorTypeWarningNoSubsLeft;
    m_cErrorMap[PARSER_KEYWORD_WARNING_NO_SUCH_PLAYER] = ErrorTypeWarningNoSuchPlayer;
    m_cErrorMap[PARSER_KEYWORD_WARNING_NO_TEAM_FOUND] = ErrorTypeWarningNoTeamFound;
    
}

/****************************************************************************************************
 * function name: buildParseMap                                                                     *
 * The Input: none                                                                                  *
 * The output: none                                                                                 *
 * The Function Opertion: Assignes each string key to it's type value.                              *
 * *************************************************************************************************/

void Parser::buildParseMap() {
    
    //In order to convert strings to enums, in a constant time, a map is used
    m_cParseMap[PARSER_KEYWORD_WARNING] = ParseTypeWarning;
    m_cParseMap[PARSER_KEYWORD_ERROR] = ParseTypeError;
    m_cParseMap[PARSER_KEYWORD_INIT] = ParseTypeInit;
    m_cParseMap[PARSER_KEYWORD_SERVER_PARAMETERS] = ParseTypeServerParameters;
    m_cParseMap[PARSER_KEYWORD_AUDIO_CUT_DISTANCE] = ParseTypeAudioCutDistance;
    m_cParseMap[PARSER_KEYWORD_AUTO_MODE] = ParseTypeAutoMode;
    m_cParseMap[PARSER_KEYWORD_BACK_DASH_RATE] = ParseTypeBackDashRate;
    m_cParseMap[PARSER_KEYWORD_BACK_PASSES] = ParseTypeBackPasses;
    m_cParseMap[PARSER_KEYWORD_BALL_ACCELERATION_MAX] = ParseTypeBallAccelerationMax;
    m_cParseMap[PARSER_KEYWORD_BALL_DECAY] = ParseTypeBallDecay;
    m_cParseMap[PARSER_KEYWORD_BALL_RANDOM] = ParseTypeBallRandom;
    m_cParseMap[PARSER_KEYWORD_BALL_SIZE] = ParseTypeBallSize;
    m_cParseMap[PARSER_KEYWORD_BALL_SPEED_MAX] = ParseTypeBallSpeedMax;
    m_cParseMap[PARSER_KEYWORD_BALL_STUCK_AREA] = ParseTypeBallStuckArea;
    m_cParseMap[PARSER_KEYWORD_BALL_WEIGHT] = ParseTypeBallWeight;
    m_cParseMap[PARSER_KEYWORD_CATCH_BAN_CYCLE] = ParseTypeCatchBanCycle;
    m_cParseMap[PARSER_KEYWORD_CATCH_PROBABILITY] = ParseTypeCatchProbability;
    m_cParseMap[PARSER_KEYWORD_CATCHABLE_AREA_L] = ParseTypeCatchableAreaL;
    m_cParseMap[PARSER_KEYWORD_CATCHABLE_AREA_W] = ParseTypeCatchableAreaW;
    m_cParseMap[PARSER_KEYWORD_CKICK_MARGIN] = ParseTypeCKickMargin;
    m_cParseMap[PARSER_KEYWORD_CLANG_ADVICE_WIN] = ParseTypeClangAdviceWin;
    m_cParseMap[PARSER_KEYWORD_CLANG_DEFINE_WIN] = ParseTypeClangDefineWin;
    m_cParseMap[PARSER_KEYWORD_CLANG_DEL_WIN] = ParseTypeClangDelWin;
    m_cParseMap[PARSER_KEYWORD_CLANG_INFO_WIN] = ParseTypeClangInfoWin;
    m_cParseMap[PARSER_KEYWORD_CLANG_MESS_DELAY] = ParseTypeClangMessDelay;
    m_cParseMap[PARSER_KEYWORD_CLANG_MESS_PER_CYCLE] = ParseTypeClangMessPerCycle;
    m_cParseMap[PARSER_KEYWORD_CLANG_META_WIN] = ParseTypeClangMetaWin;
    m_cParseMap[PARSER_KEYWORD_CLANG_RULE_WIN] = ParseTypeClangRuleWin;
    m_cParseMap[PARSER_KEYWORD_CLANG_WIN_SIZE] = ParseTypeClangWinSize;
    m_cParseMap[PARSER_KEYWORD_COACH] = ParseTypeCoach;
    m_cParseMap[PARSER_KEYWORD_COACH_PORT] = ParseTypeCoachPort;
    m_cParseMap[PARSER_KEYWORD_COACH_WITH_REFEREE] = ParseTypeCoachWithReferee;
    m_cParseMap[PARSER_KEYWORD_CONNECT_WAIT] = ParseTypeConnectWait;
    m_cParseMap[PARSER_KEYWORD_CONTROL_RADIUS] = ParseTypeControlRadius;
    m_cParseMap[PARSER_KEYWORD_DASH_ANGLE_STEP] = ParseTypeDashAngleStep;
    m_cParseMap[PARSER_KEYWORD_DASH_POWER_RATE] = ParseTypeDashPowerRate;
    m_cParseMap[PARSER_KEYWORD_DROP_BALL_TIME] = ParseTypeDropBallTime;
    m_cParseMap[PARSER_KEYWORD_EFFORT_DECAY] = ParseTypeEffortDecrement;
    m_cParseMap[PARSER_KEYWORD_EFFORT_DECAY_THR] = ParseTypeEffortDecrementThreshold;
    m_cParseMap[PARSER_KEYWORD_EFFORT_INCREASE] = ParseTypeEffortIncrease;
    m_cParseMap[PARSER_KEYWORD_EFFORT_INCREASE_THR] = ParseTypeEffortIncreaseThreshold;
    m_cParseMap[PARSER_KEYWORD_EFFORT_INIT] = ParseTypeEffortInit;
    m_cParseMap[PARSER_KEYWORD_EFFORT_MIN] = ParseTypeEffortMin;
    m_cParseMap[PARSER_KEYWORD_EXTRA_HALF_TIME] = ParseTypeExtraHalfTime;
    m_cParseMap[PARSER_KEYWORD_EXTRA_STAMINA] = ParseTypeExtraStamina;
    m_cParseMap[PARSER_KEYWORD_FORBID_KICKOFF_OFFSIDE] = ParseTypeForbidKickOffOffside;
    m_cParseMap[PARSER_KEYWORD_FOUL_CYCLES] = ParseTypeFoulCycles;
    m_cParseMap[PARSER_KEYWORD_FOUL_DETECT_PROBABILITY] = ParseTypeFoulDetectProbability;
    m_cParseMap[PARSER_KEYWORD_FOUL_EXPONENT] = ParseTypeFoulExponent;
    m_cParseMap[PARSER_KEYWORD_FREE_KICK_FAULTS] = ParseTypeFreeKickFaults;
    m_cParseMap[PARSER_KEYWORD_FREEFORM_SEND_PERIOD] = ParseTypeFreeformSendPeriod;
    m_cParseMap[PARSER_KEYWORD_FREEFORM_WAIT_PERIOD] = ParseTypeFreeformWaitPeriod;
    m_cParseMap[PARSER_KEYWORD_FULL_STATE_L] = ParseTypeFullStateL;
    m_cParseMap[PARSER_KEYWORD_FULL_STATE_R] = ParseTypeFullStateR;
    m_cParseMap[PARSER_KEYWORD_GAME_LOG_COMPRESSION] = ParseTypeGameLogCompression;
    m_cParseMap[PARSER_KEYWORD_GAME_LOG_DATED] = ParseTypeGameLogDated;
    m_cParseMap[PARSER_KEYWORD_GAME_LOG_DIRECTORY] = ParseTypeGameLogDirectory;
    m_cParseMap[PARSER_KEYWORD_GAME_LOG_FIXED] = ParseTypeGameLogFixed;
    m_cParseMap[PARSER_KEYWORD_GAME_LOG_FIXED_NAME] = ParseTypeGameLogFixedName;
    m_cParseMap[PARSER_KEYWORD_GAME_LOG_VERSION] = ParseTypeGameLogVersion;
    m_cParseMap[PARSER_KEYWORD_GAME_LOGGING] = ParseTypeGameLogging;
    m_cParseMap[PARSER_KEYWORD_GAME_OVER_WAIT] = ParseTypeGameOverWait;
    m_cParseMap[PARSER_KEYWORD_GOAL_WIDTH] = ParseTypeGoalWidth;
    m_cParseMap[PARSER_KEYWORD_GOALIE_MAX_MOVES] = ParseTypeGoalieMaxMoves;
    m_cParseMap[PARSER_KEYWORD_GOLDEN_GOAL] = ParseTypeGoldenGoal;
    m_cParseMap[PARSER_KEYWORD_HALF_TIME] = ParseTypeHalfTime;
    m_cParseMap[PARSER_KEYWORD_HEAR_DECAY] = ParseTypeHearDecay;
    m_cParseMap[PARSER_KEYWORD_HEAR_INC] = ParseTypeHearInc;
    m_cParseMap[PARSER_KEYWORD_HEAR_MAX] = ParseTypeHearMax;
    m_cParseMap[PARSER_KEYWORD_INERTIA_MOMENT] = ParseTypeInertiaMoment;
    m_cParseMap[PARSER_KEYWORD_KEEP_AWAY] = ParseTypeKeepAway;
    m_cParseMap[PARSER_KEYWORD_KEEP_AWAY_LENGTH] = ParseTypeKeepAwayLength;
    m_cParseMap[PARSER_KEYWORD_KEEP_AWAY_LOG_DATED] = ParseTypeKeepAwayLogDated;
    m_cParseMap[PARSER_KEYWORD_KEEP_AWAY_LOG_DIR] = ParseTypeKeepAwayLogDir;
    m_cParseMap[PARSER_KEYWORD_KEEP_AWAY_LOG_FIXED] = ParseTypeKeepAwayLogFixed;
    m_cParseMap[PARSER_KEYWORD_KEEP_AWAY_LOG_FIXED_NAME] = ParseTypeKeepAwayLogFixedName;
    m_cParseMap[PARSER_KEYWORD_KEEP_AWAY_LOGGING] = ParseTypeKeepAwayLogging;
    m_cParseMap[PARSER_KEYWORD_KEEP_AWAY_START] = ParseTypeKeepAwayStart;
    m_cParseMap[PARSER_KEYWORD_KEEP_AWAY_WIDTH] = ParseTypeKeepAwayWidth;
    m_cParseMap[PARSER_KEYWORD_KICKOFF_WAIT] = ParseTypeKickOffWait;
    m_cParseMap[PARSER_KEYWORD_KICK_POWER_RATE] = ParseTypeKickPowerRate;
    m_cParseMap[PARSER_KEYWORD_KICK_RAND] = ParseTypeKickRand;
    m_cParseMap[PARSER_KEYWORD_KICK_RAND_FACTOR_L] = ParseTypeKickRandFactorL;
    m_cParseMap[PARSER_KEYWORD_KICK_RAND_FACTOR_R] = ParseTypeKickRandFactorR;
    m_cParseMap[PARSER_KEYWORD_KICKABLE_MARGIN] = ParseTypeKickableMargin;
    m_cParseMap[PARSER_KEYWORD_LANDMARK_FILE] = ParseTypeLandmarkFile;
    m_cParseMap[PARSER_KEYWORD_LOG_DATE_FORMAT] = ParseTypeLogDateFormat;
    m_cParseMap[PARSER_KEYWORD_LOG_TIMES] = ParseTypeLogTimes;
    m_cParseMap[PARSER_KEYWORD_MAX_BACK_TACKLE_POWER] = ParseTypeMaxBackTacklePower;
    m_cParseMap[PARSER_KEYWORD_MAX_DASH_ANGLE] = ParseTypeMaxDashAngle;
    m_cParseMap[PARSER_KEYWORD_MAX_DASH_POWER] = ParseTypeMaxDashPower;
    m_cParseMap[PARSER_KEYWORD_MAX_GOAL_KICKS] = ParseTypeMaxGoalKicks;
    m_cParseMap[PARSER_KEYWORD_MAX_TACKLE_POWER] = ParseTypeMaxTacklePower;
    m_cParseMap[PARSER_KEYWORD_MAX_MOMENT] = ParseTypeMaxMoment;
    m_cParseMap[PARSER_KEYWORD_MAX_NECK_ANGLE] = ParseTypeMaxNeckAngle;
    m_cParseMap[PARSER_KEYWORD_MAX_NECK_MOMENT] = ParseTypeMaxNeckMoment;
    m_cParseMap[PARSER_KEYWORD_MAX_POWER] = ParseTypeMaxPower;
    m_cParseMap[PARSER_KEYWORD_MIN_DASH_ANGLE] = ParseTypeMinDashAngle;
    m_cParseMap[PARSER_KEYWORD_MIN_DASH_POWER] = ParseTypeMinDashPower;
    m_cParseMap[PARSER_KEYWORD_MIN_MOMENT] = ParseTypeMinMoment;
    m_cParseMap[PARSER_KEYWORD_MIN_NECK_ANGLE] = ParseTypeMinNeckAngle;
    m_cParseMap[PARSER_KEYWORD_MIN_NECK_MOMENT] = ParseTypeMinNeckMoment;
    m_cParseMap[PARSER_KEYWORD_MIN_POWER] = ParseTypeMinPower;
    m_cParseMap[PARSER_KEYWORD_NR_EXTRA_HALFS] = ParseTypeNRExtraHalfs;
    m_cParseMap[PARSER_KEYWORD_NR_NORMAL_HALFS] = ParseTypeNRNormalHalfs;
    m_cParseMap[PARSER_KEYWORD_OFFSIDE_ACTIVE_AREA_SIZE] = ParseTypeOffsideActiveAreaSize;
    m_cParseMap[PARSER_KEYWORD_OFFSIDE_KICK_MARGIN] = ParseTypeOffsideKickMargin;
    m_cParseMap[PARSER_KEYWORD_OL_COACH_PORT] = ParseTypeOlCoachPort;
    m_cParseMap[PARSER_KEYWORD_OLD_COACH_HEAR] = ParseTypeOldCoachHear;
    m_cParseMap[PARSER_KEYWORD_PEN_ALLOW_MULTIPLE_KICKS] = ParseTypePenAllowMultipleKicks;
    m_cParseMap[PARSER_KEYWORD_PEN_BEFORE_SETUP_WAIT] = ParseTypePenBeforeSetupWait;
    m_cParseMap[PARSER_KEYWORD_PEN_COACH_MOVES_PLAYERS] = ParseTypePenCoachMovesPlayers;
    m_cParseMap[PARSER_KEYWORD_PEN_DISTANCE_X] = ParseTypePenDistanceX;
    m_cParseMap[PARSER_KEYWORD_PEN_MAX_EXTRA_KICKS] = ParseTypePenMaxExtraKicks;
    m_cParseMap[PARSER_KEYWORD_PEN_MAX_GOALIE_DISTANCE_X] = ParseTypePenMaxGoalieDistanceX;
    m_cParseMap[PARSER_KEYWORD_PEN_NR_KICKS] = ParseTypePenNRKicks;
    m_cParseMap[PARSER_KEYWORD_PEN_RANDOM_WINNER] = ParseTypePenRandomWinner;
    m_cParseMap[PARSER_KEYWORD_PEN_READY_WAIT] = ParseTypePenReadyWait;
    m_cParseMap[PARSER_KEYWORD_PEN_SETUP_WAIT] = ParseTypePenSetupWait;
    m_cParseMap[PARSER_KEYWORD_PEN_TAKEN_WAIT] = ParseTypePenTakenWait;
    m_cParseMap[PARSER_KEYWORD_PENALTY_SHOOT_OUTS] = ParseTypePenaltyShootOuts;
    m_cParseMap[PARSER_KEYWORD_PLAYER_ACCELERATION_MAX] = ParseTypePlayerAccelerationMax;
    m_cParseMap[PARSER_KEYWORD_PLAYER_DECAY] = ParseTypePlayerDecay;
    m_cParseMap[PARSER_KEYWORD_PLAYER_RAND] = ParseTypePlayerRand;
    m_cParseMap[PARSER_KEYWORD_PLAYER_SIZE] = ParseTypePlayerSize;
    m_cParseMap[PARSER_KEYWORD_PLAYER_SPEED_MAX] = ParseTypePlayerSpeedMax;
    m_cParseMap[PARSER_KEYWORD_PLAYER_SPEED_MAX_MIN] = ParseTypePlayerSpeedMaxMin;
    m_cParseMap[PARSER_KEYWORD_PLAYER_WEIGHT] = ParseTypePlayerWeight;
    m_cParseMap[PARSER_KEYWORD_POINTS_TO_BAN] = ParseTypePointsToBan;
    m_cParseMap[PARSER_KEYWORD_POINTS_TO_DURATION] = ParseTypePointsToDuration;
    m_cParseMap[PARSER_KEYWORD_PORT] = ParseTypePort;
    m_cParseMap[PARSER_KEYWORD_PRAND_FACTOR_L] = ParseTypePRandFactorL;
    m_cParseMap[PARSER_KEYWORD_PRAND_FACTOR_R] = ParseTypePRandFactorR;
    m_cParseMap[PARSER_KEYWORD_PROFILE] = ParseTypeProfile;
    m_cParseMap[PARSER_KEYWORD_PROPER_GOAL_KICKS] = ParseTypeProperGoalKicks;
    m_cParseMap[PARSER_KEYWORD_QUANTIZE_STEP] = ParseTypeQuantizeStep;
    m_cParseMap[PARSER_KEYWORD_QUANTIZE_STEP_L] = ParseTypeQuantizeStepL;
    m_cParseMap[PARSER_KEYWORD_RECORD_MESSAGES] = ParseTypeRecordMessages;
    m_cParseMap[PARSER_KEYWORD_RECOVER_DEC] = ParseTypeRecoverDec;
    m_cParseMap[PARSER_KEYWORD_RECOVER_DEC_THR] = ParseTypeRecoverDecThr;
    m_cParseMap[PARSER_KEYWORD_RECOVER_INIT] = ParseTypeRecoverInit;
    m_cParseMap[PARSER_KEYWORD_RECOVER_MIN] = ParseTypeRecoverMin;
    m_cParseMap[PARSER_KEYWORD_RECIEVE_STEP] = ParseTypeRecieveStep;
    m_cParseMap[PARSER_KEYWORD_RED_CARD_PROBABILITY] = ParseTypeRedCardProbability;
    m_cParseMap[PARSER_KEYWORD_SAY_COACH_CNT_MAX] = ParseTypeSayCoachCntMax;
    m_cParseMap[PARSER_KEYWORD_SAY_COACH_MESSAGE_SIZE] = ParseTypeSayCoachMessageSize;
    m_cParseMap[PARSER_KEYWORD_SAY_MESSAGE_SIZE] = ParseTypeSayMessageSize;
    m_cParseMap[PARSER_KEYWORD_SEND_COMMS] = ParseTypeSendComms;
    m_cParseMap[PARSER_KEYWORD_SEND_STEP] = ParseTypeSendStep;
    m_cParseMap[PARSER_KEYWORD_SEND_VI_STEP] = ParseTypeSendViStep;
    m_cParseMap[PARSER_KEYWORD_SENSE_BODY_STEP] = ParseTypeSenseBodyStep;
    m_cParseMap[PARSER_KEYWORD_SIDE_DASH_RATE] = ParseTypeSideDashRate;
    m_cParseMap[PARSER_KEYWORD_SIMULATOR_STEP] = ParseTypeSimulatorStep;
    m_cParseMap[PARSER_KEYWORD_SLOW_DOWN_FACTOR] = ParseTypeSlowDownFactor;
    m_cParseMap[PARSER_KEYWORD_SLOWNESS_ON_TOP_FOR_LEFT_TEAM] = ParseTypeSlownessOnTopForLeftTeam;
    m_cParseMap[PARSER_KEYWORD_SLOWNESS_ON_TOP_FOR_RIGHT_TEAM] = ParseTypeSlownessOnTopForRightTeam;
    m_cParseMap[PARSER_KEYWORD_STAMINA_CAPACITY] = ParseTypeStaminaCapacity;
    m_cParseMap[PARSER_KEYWORD_STAMINA_INC_MAX] = ParseTypeStaminaIncMax;
    m_cParseMap[PARSER_KEYWORD_STAMINA_MAX] = ParseTypeStaminaMax;
    m_cParseMap[PARSER_KEYWORD_START_GOAL_L] = ParseTypeStartGoalL;
    m_cParseMap[PARSER_KEYWORD_START_GOAL_R] = ParseTypeStartGoalR;
    m_cParseMap[PARSER_KEYWORD_STOPPED_BALL_VEL] = ParseTypeStoppedBallVel;
    m_cParseMap[PARSER_KEYWORD_SYNCH_MICRO_SLEEP] = ParseTypeSynchMicroSleep;
    m_cParseMap[PARSER_KEYWORD_SYNCH_MODE] = ParseTypeSynchMode;
    m_cParseMap[PARSER_KEYWORD_SYNCH_OFFSET] = ParseTypeSynchOffset;
    m_cParseMap[PARSER_KEYWORD_SYNCH_SEE_OFFSET] = ParseTypeSynchSeeOffset;
    m_cParseMap[PARSER_KEYWORD_TACKLE_BACK_DIST] = ParseTypeTackleBackDist;
    m_cParseMap[PARSER_KEYWORD_TACKLE_CYCLES] = ParseTypeTackleCycles;
    m_cParseMap[PARSER_KEYWORD_TACKLE_DIST] = ParseTypeTackleDist;
    m_cParseMap[PARSER_KEYWORD_TACKLE_EXPONENT] = ParseTypeTackleExponent;
    m_cParseMap[PARSER_KEYWORD_TACKLE_POWER_RATE] = ParseTypeTacklePowerRate;
    m_cParseMap[PARSER_KEYWORD_TACKLE_RAND_FACTOR] = ParseTypeTackleRandFactor;
    m_cParseMap[PARSER_KEYWORD_TACKLE_WIDTH] = ParseTypeTackleWidth;
    m_cParseMap[PARSER_KEYWORD_TEAM_ACTUATOR_NOISE] = ParseTypeTeamActuatorNoise;
    m_cParseMap[PARSER_KEYWORD_TEAM_L_START] = ParseTypeTeamLStart;
    m_cParseMap[PARSER_KEYWORD_TEAM_R_START] = ParseTypeTeamRStart;
    m_cParseMap[PARSER_KEYWORD_TEXT_LOG_COMPRESSION] = ParseTypeTextLogCompression;
    m_cParseMap[PARSER_KEYWORD_TEXT_LOG_DATED] = ParseTypeTextLogDated;
    m_cParseMap[PARSER_KEYWORD_TEXT_LOG_DIR] = ParseTypeTextLogDir;
    m_cParseMap[PARSER_KEYWORD_TEXT_LOG_FIXED] = ParseTypeTextLogFixed;
    m_cParseMap[PARSER_KEYWORD_TEXT_LOG_FIXED_NAME] = ParseTypeTextLogFixedName;
    m_cParseMap[PARSER_KEYWORD_TEXT_LOGGING] = ParseTypeTextLogging;
    m_cParseMap[PARSER_KEYWORD_USE_OFFSIDE] = ParseTypeUseOffside;
    m_cParseMap[PARSER_KEYWORD_VERBOSE] = ParseTypeVerbose;
    m_cParseMap[PARSER_KEYWORD_VISIBLE_ANGLE] = ParseTypeVisibleAngle;
    m_cParseMap[PARSER_KEYWORD_VISIBLE_DISTANCE] = ParseTypeVisibleDistance;
    m_cParseMap[PARSER_KEYWORD_WIND_ANG] = ParseTypeWindAng;
    m_cParseMap[PARSER_KEYWORD_WIND_DIR] = ParseTypeWindDir;
    m_cParseMap[PARSER_KEYWORD_WIND_FORCE] = ParseTypeWindForce;
    m_cParseMap[PARSER_KEYWORD_WIND_NONE] = ParseTypeWindNone;
    m_cParseMap[PARSER_KEYWORD_WIND_RAND] = ParseTypeWindRand;
    m_cParseMap[PARSER_KEYWORD_WIND_RANDOM] = ParseTypeWindRandom;
    m_cParseMap[PARSER_KEYWORD_PLAYER_PARAM] = ParseTypePlayerParam;
    m_cParseMap[PARSER_KEYWORD_ALLOW_MULTIPLE_DEFAULT_TYPE] = ParseTypeAllowMultipleDefaultType;
    m_cParseMap[PARSER_KEYWORD_CATCHABLE_AREA_L_STRETCH_MAX] = ParseTypeCatchableAreaLStretchMax;
    m_cParseMap[PARSER_KEYWORD_CATCHABLE_AREA_L_STRETCH_MIN] = ParseTypeCatchableAreaLStretchMin;
    m_cParseMap[PARSER_KEYWORD_DASH_POWER_RATE_DELTA_MAX] = ParseTypeDashPowerRateDeltaMax;
    m_cParseMap[PARSER_KEYWORD_DASH_POWER_RATE_DELTA_MIN] = ParseTypeDashPowerRateDeltaMin;
    m_cParseMap[PARSER_KEYWORD_EFFORT_MAX_DELTA_FACTOR] = ParseTypeEffortMaxDeltaFactor;
    m_cParseMap[PARSER_KEYWORD_EFFORT_MIN_DELTA_FACTOR] = ParseTypeEffortMinDeltaFactor;
    m_cParseMap[PARSER_KEYWORD_EXTRA_STAMINA_DELTA_MAX] = ParseTypeExtraStaminaDeltaMax;
    m_cParseMap[PARSER_KEYWORD_EXTRA_STAMINA_DELTA_MIN] = ParseTypeExtraStaminaDeltaMin;
    m_cParseMap[PARSER_KEYWORD_FOUL_DETECT_PROBABILITY_DELTA_FACTOR] = ParseTypeFoulDetectProbabilityDeltaFactor;
    m_cParseMap[PARSER_KEYWORD_INERTIA_MOMENT_DELTA_FACTOR] = ParseTypeInertiaMomentDeltaFactor;
    m_cParseMap[PARSER_KEYWORD_KICK_POWER_RATE_DELTA_MAX] = ParseTypeKickPowerRateDeltaMax;
    m_cParseMap[PARSER_KEYWORD_KICK_POWER_RATE_DELTA_MIN] = ParseTypeKickPowerRateDeltaMin;
    m_cParseMap[PARSER_KEYWORD_KICK_RAND_DELTA_FACTOR] = ParseTypeKickRandDeltaFactor;
    m_cParseMap[PARSER_KEYWORD_KICKABLE_MARGIN_DELTA_MAX] = ParseTypeKickableMarginDeltaMax;
    m_cParseMap[PARSER_KEYWORD_KICKABLE_MARGIN_DELTA_MIN] = ParseTypeKickableMarginDeltaMin;
    m_cParseMap[PARSER_KEYWORD_NEW_DASH_POWER_RATE_DELTA_MAX] = ParseTypeNewDashPowerRateDeltaMax;
    m_cParseMap[PARSER_KEYWORD_NEW_DASH_POWER_RATE_DELTA_MIN] = ParseTypeNewDashPowerRateDeltaMin;
    m_cParseMap[PARSER_KEYWORD_NEW_STAMINA_INC_MAX_DELTA_FACTOR] = ParseTypeStaminaIncMaxDeltaFactor;
    m_cParseMap[PARSER_KEYWORD_PLAYER_DECAY_DELTA_MAX] = ParseTypePlayerDecayDeltaMax;
    m_cParseMap[PARSER_KEYWORD_PLAYER_DECAY_DELTA_MIN] = ParseTypePlayerDecayDeltaMin;
    m_cParseMap[PARSER_KEYWORD_PLAYER_SIZE_DELTA_FACTOR] = ParseTypePlayerSizeDeltaFactor;
    m_cParseMap[PARSER_KEYWORD_PLAYER_SPEED_MAX_DELTA_MAX] = ParseTypePlayerSpeedMaxDeltaMax;
    m_cParseMap[PARSER_KEYWORD_PLAYER_SPEED_MAX_DELTA_MIN] = ParseTypePlayerSpeedMaxDeltaMin;
    m_cParseMap[PARSER_KEYWORD_PLAYER_TYPES] = ParseTypePlayerTypes;
    m_cParseMap[PARSER_KEYWORD_PT_MAX] = ParseTypePtMax;
    m_cParseMap[PARSER_KEYWORD_RANDOM_SEED] = ParseTypeRandomSeed;
    m_cParseMap[PARSER_KEYWORD_STAMINA_INC_MAX_DELTA_FACTOR] = ParseTypeStaminaIncMaxDeltaFactor;
    m_cParseMap[PARSER_KEYWORD_SUBS_MAX] = ParseTypeSubsMax;
    m_cParseMap[PARSER_KEYWORD_PLAYER_TYPE] = ParseTypePlayerType;
    m_cParseMap[PARSER_KEYWORD_ID] = ParseTypeID;
    m_cParseMap[PARSER_KEYWORD_PM_NULL] = ParseTypePMNull;
    m_cParseMap[PARSER_KEYWORD_PM_BEFORE_KICKOFF] = ParseTypePMBeforeKickOff;
    m_cParseMap[PARSER_KEYWORD_PM_TIME_OVER] = ParseTypePMTimeOver;
    m_cParseMap[PARSER_KEYWORD_PM_PLAY_ON] = ParseTypePMPlayOn;
    m_cParseMap[PARSER_KEYWORD_PM_KICKOFF_LEFT] = ParseTypePMKickOffLeft;
    m_cParseMap[PARSER_KEYWORD_PM_KICKOFF_RIGHT] = ParseTypePMKickOffRight;
    m_cParseMap[PARSER_KEYWORD_PM_KICK_IN_LEFT] = ParseTypePMKickInLeft;
    m_cParseMap[PARSER_KEYWORD_PM_KICK_IN_RIGHT] = ParseTypePMKickInRight;
    m_cParseMap[PARSER_KEYWORD_PM_FREE_KICK_LEFT] = ParseTypePMFreeKickLeft;
    m_cParseMap[PARSER_KEYWORD_PM_FREE_KICK_RIGHT] = ParseTypePMFreeKickRight;
    m_cParseMap[PARSER_KEYWORD_PM_CORNER_KICK_LEFT] = ParseTypePMCornerKickLeft;
    m_cParseMap[PARSER_KEYWORD_PM_CORNER_KICK_RIGHT] = ParseTypePMCornerKickRight;
    m_cParseMap[PARSER_KEYWORD_PM_GOAL_KICK_LEFT] = ParseTypePMGoalKickLeft;
    m_cParseMap[PARSER_KEYWORD_PM_GOAL_KICK_RIGHT] = ParseTypePMGoalKickRight;
    m_cParseMap[PARSER_KEYWORD_PM_AFTER_GOAL_LEFT] = ParseTypePMAfterGoalLeft;
    m_cParseMap[PARSER_KEYWORD_PM_AFTER_GOAL_RIGHT] = ParseTypePMAfterGoalRight;
    m_cParseMap[PARSER_KEYWORD_PM_DROP_BALL] = ParseTypePMDropBall;
    m_cParseMap[PARSER_KEYWORD_PM_OFFSIDE_LEFT] = ParseTypePMOffsideLeft;
    m_cParseMap[PARSER_KEYWORD_PM_OFFSIDE_RIGHT] = ParseTypePMOffsideRight;
    m_cParseMap[PARSER_KEYWORD_PM_MAX] = ParseTypePMMax;
    m_cParseMap[PARSER_KEYWORD_EFFORT_MAX] = ParseTypeEffortMax;
    m_cParseMap[PARSER_KEYWORD_CATCHABLE_AREA_L_STRETCH] = ParseTypeCatchableAreaLStretch;
    m_cParseMap[PARSER_KEYWORD_SENSE_BODY] = ParseTypeSenseBody;
    m_cParseMap[PARSER_KEYWORD_VIEW_MODE] = ParseTypeViewMode;
    m_cParseMap[PARSER_KEYWORD_STAMINA] = ParseTypeStamina;
    m_cParseMap[PARSER_KEYWORD_SPEED] = ParseTypeSpeed;
    m_cParseMap[PARSER_KEYWORD_HEAD_ANGLE] = ParseTypeHeadAngle;
    m_cParseMap[PARSER_KEYWORD_KICK] = ParseTypeKick;
    m_cParseMap[PARSER_KEYWORD_DASH] = ParseTypeDash;
    m_cParseMap[PARSER_KEYWORD_TURN] = ParseTypeTurn;
    m_cParseMap[PARSER_KEYWORD_SAY] = ParseTypeSay;
    m_cParseMap[PARSER_KEYWORD_TURN_NECK] = ParseTypeTurnNeck;
    m_cParseMap[PARSER_KEYWORD_CATCH] = ParseTypeCatch;
    m_cParseMap[PARSER_KEYWORD_MOVE] = ParseTypeMove;
    m_cParseMap[PARSER_KEYWORD_CHANGE_VIEW] = ParseTypeChangeView;
    m_cParseMap[PARSER_KEYWORD_ARM] = ParseTypeArm;
    m_cParseMap[PARSER_KEYWORD_MOVABLE] = ParseTypeMovable;
    m_cParseMap[PARSER_KEYWORD_EXPIRES] = ParseTypeExpires;
    m_cParseMap[PARSER_KEYWORD_TARGET] = ParseTypeTarget;
    m_cParseMap[PARSER_KEYWORD_COUNT] = ParseTypeCount;
    m_cParseMap[PARSER_KEYWORD_FOCUS] = ParseTypeFocus;
    m_cParseMap[PARSER_KEYWORD_TACKLE] = ParseTypeTackle;
    m_cParseMap[PARSER_KEYWORD_COLLISION] = ParseTypeCollision;
    m_cParseMap[PARSER_KEYWORD_FOUL] = ParseTypeFoul;
    m_cParseMap[PARSER_KEYWORD_CHARGED] = ParseTypeCharged;
    m_cParseMap[PARSER_KEYWORD_CARD] = ParseTypeCard;
    m_cParseMap[PARSER_KEYWORD_SEE] = ParseTypeSee;
    m_cParseMap[PARSER_KEYWORD_VIEWMODE_QUALITY_LOW] = ParseTypeViewModeQualityLow;
    m_cParseMap[PARSER_KEYWORD_VIEWMODE_QUALITY_HIGH] = ParseTypeViewModeQualityHigh;
    m_cParseMap[PARSER_KEYWORD_VIEWMODE_WIDTH_NARROW] = ParseTypeViewModeWidthNarrow;
    m_cParseMap[PARSER_KEYWORD_VIEWMODE_WIDTH_NORMAL] = ParseTypeViewModeWidthNormal;
    m_cParseMap[PARSER_KEYWORD_VIEWMODE_WIDTH_WIDE] = ParseTypeViewModeWidthWide;
    m_cParseMap[PARSER_KEYWORD_HEAR] = ParseTypeHear;
    m_cParseMap[PARSER_KEYWORD_REFEREE] = ParseTypeReferee;
    m_cParseMap[PARSER_KEYWORD_F]= ParseTypeF;
    m_cParseMap[PARSER_KEYWORD_B]= ParseTypeB;
    m_cParseMap[PARSER_KEYWORD_L]= ParseTypeL;
    m_cParseMap[PARSER_KEYWORD_R]= ParseTypeR;
    m_cParseMap[PARSER_KEYWORD_C]= ParseTypeC;
    m_cParseMap[PARSER_KEYWORD_T] = ParseTypeT;
    m_cParseMap[PARSER_KEYWORD_G] = ParseTypeG;
    m_cParseMap[PARSER_KEYWORD_P] = ParseTypeP;
    m_cParseMap[PARSER_KEYWORD_P_CLOSE] = ParseTypePClose;
    m_cParseMap[PARSER_KEYWORD_G_CLOSE] = ParseTypeGClose;
    m_cParseMap[PARSER_KEYWORD_B_CLOSE] = ParseTypeBClose;
    m_cParseMap[PARSER_KEYWORD_F_CLOSE] = ParseTypeFClose;
    m_cParseMap[PARSER_KEYWORD_0] = ParseType0;
    m_cParseMap[PARSER_KEYWORD_10] = ParseType10;
    m_cParseMap[PARSER_KEYWORD_20] = ParseType20;
    m_cParseMap[PARSER_KEYWORD_30] = ParseType30;
    m_cParseMap[PARSER_KEYWORD_40] = ParseType40;
    m_cParseMap[PARSER_KEYWORD_50] = ParseType50;

}
