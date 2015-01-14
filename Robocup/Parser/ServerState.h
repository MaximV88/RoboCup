/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Declaration of ServerState Class       *
 ***********************************************************/

#ifndef __Ex3__ServerState__
#define __Ex3__ServerState__

#include <stdio.h>
#include "State.h"

/*******************************************************************************
 * ServerState Class: Represents the Server input recieved from the server,    *
 *                    all information recieved in (server_param ...)           *
 ******************************************************************************/

class ServerState : public State {
    
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

    
    //Each type is taken from serverparam.h
    double audioCutDistance;         /* audio cut off distance */
    bool autoMode;

    double ballAccelerationMax;      /* ball acceleration max */
    double ballDecay;                /* ball decay */
    double ballRand;                 /* ball rand */
    double ballSize;                 /* ball size */
    double ballSpeedMax;             /* ball speed max */
    double ballWeight;               /* ball weight */
    
    int catchBanCycle;               /* goalie catch ban cycle */
    double catchProbability;         /* goalie catchable possibility */
    double catchableAreaL;           /* goalie catchable area length */
    double catchableAreaW;           /* goalie catchable area width */
    int goalieMaxMoves;              /* goalie max moves after a catch */
    double cornerKickMargin;         /* corner kick margin */
    
    int coachLanguageAdviceWindow;   /* coach language: advice messages per window */
    int coachLanguageDefineWindow;   /* coach language: define messages per window */
    int coachLanguageDelWindow;
    int coachLanguageInfoWindow;     /* coach language: info messages per window */
    int coachLanguageMessDelay;      /* coach language: delay between receive and send */
    int coachLanguageMessPerCycle;   /* coach language: number of messages to flush per cycle */
    int coachLanguageMetaWindow;     /* coach language: meta messages per window */
    int coachLanguageRuleWindow;
    int coachLanguageWindowSize;     /* coach language: time window size */
    int coachMaxSayCount;            /* max count of coach SAY (freeform) */
    int coachMaxMessageSize;         /* max length of coach SAY (freeform) */
    bool coachMode;                  /* coach mode */
    int coachPort;                   /* coach port number */
    bool oldCoachHearFormat;         /* old format for hear command (coach) */
    int onlineCoachPort;             /* online coach port number */
    bool coachWithRefereeMode;       /* coach with referee mode */
    double ballStuckArea;            /* threshold distance checked by BallStuckRef */
    bool backPasses;
    int sendViStep;                  /* online coach's look interval step */

    int connectWait;
    double controlRadius;            /* control radius */
    double dashAngleStep;
    double dashPowerRate;            /* dash power rate */
    double backDashRate;
    double inertiaMoment;            /* intertia moment for turn */
    
    int dropBallTime;                /* cycles for dropping
                                         the ball after a free kick,
                                         corner kick message and
                                         noone kicking the ball.
                                         0 means don't drop
                                         automatically  */
    
    
    double dashEffortDecriment;          /* player dash effort decriment */
    double dashEffortDecrimentThreshold; /* player dash effort decriment threshold */
    double dashEffortIncriment;          /* player dash effort incriment */
    double dashEffortIncrimentThreshold; /* player dash effort incriment threshold */
    double dashEffortInit;               /* player dash effort init */
    double dashEffortMin;                /* player dash effrot min */
    int playerHearDecay;                 /* player hear_capacity_decay */
    int playerHearInc;                   /* player hear_capacity_inc */
    int playerHearMax;                   /* player hear_capacity_max */
    double playerAccelerationMax;        /* player acceleration max */
    double playerDecay;                  /* player decay */
    double playerRand;                   /* player rand */
    double playerSize;                   /* player size */
    double playerSpeedMax;               /* player speed max */
    double playerSpeedMaxMin;            /* minumum value of player speed max */
    double playerWeight;                 /* player weight */
    double playerStaminaIncrement;       /* The maximum player stamina increament */
    double playerStaminaMax;             /* The maximum stamina of players */

    double playerRecoveryDecriment;           /* player recovery decriment */
    double playerRecoveryDecrimentThreshold;  /* player recovery decriment threshold */
    double playerRecoveryInit;                /* player recovery init */
    double playerRecoveryMin;                 /* player recovery min */
    
    int extraHalfTime;
    double extraStamina;
    bool forbidKickOffOffside;       /* flag for permit kick off offside */
    int foulCycles;
    double foulDetectProbability;
    double foulExponent;
    bool freeKickFaults;
    int freeformSendPeriod;
    int freeformWaitPeriod;
    bool fullstateL;                 /* flag to send fullstate messages to left team; supresses visual info */
    bool fullstateR;                 /* flag to send fullstate messages to right team; supresses visual info */
    
    int gameLogCompression;
    bool gameLogDated;
    std::string gameLogDirectory;
    bool gameLogFixed;
    std::string gameLogFixedName;
    int gameLogVersion;
    bool gameLogging;
    int gameOverWait;
    std::string landmarkFile;
    std::string logDateFormat;
    bool logTimes;
    
    int textLogCompression;
    bool textLogDated;
    std::string textLogDirectory;
    bool textLogFixed;
    std::string textLogFixedName;
    bool textLogging;
    
    
    
    double goalWidth;                /* goal width */
    bool goldenGoal;
    int halfTime;                    /* half time */
    
    bool keepAway;                   /* keepaway mode on/off */
    double keepAwayLength;           /* keepaway region length */
    bool keepAwayLogDated;
    std::string keepAwayLogDirectory;
    bool keepAwayLogFixed;
    std::string keepAwayLogFixedName;
    bool keepAwayLogging;
    int keepAwayStart;
    double keepAwayWidth;            /* keepaway region width */
    
    int kickOffWait;
    double kickPowerRate;            /* kick power rate */
    double kickRandom;               /* noise added directly to kicks */
    double kickRandomFactorLeft;     /* factor to multiple kick_rand for left team */
    double kickRandomFactorRight;    /* factor to multiple kick_rand for right team */
    double kickableMargin;           /* kickable margin */

    double maxBackTacklePower;
    double maxDashAngle;
    double maxDashPower;
    int maxGoalKicks;
    double maxTacklePower;
    double minMoment;                /* min moment */
    double maxMoment;                /* max moment */
    double maxNeckAngle;             /* max neck angle */
    double minNeckAngle;             /* min neck angle */
    double minNeckMoment;            /* min neck moment */
    double maxNeckMoment;            /* max neck moment */
    double maxPower;                 /* max power */
    double minPower;                 /* min power */
    double minDashAngle;
    double minDashPower;
    
    int nrExtraHalfs;                /* nr of extra halfs: -1 is infinite)  */
    int nrNormalHalfs;               /* nr of normal halfs: default 2)      */
    double offsideActiveAreaSize;    /* offside active area size */
    double offsideKickMargin;        /* offside kick margin */
    bool useOffside;                 /* flag for using off side rule */
    
    bool penAllowMultipleKicks;      /* can attacker kick mult. times */
    int penBeforeSetupWait;          /* cycles waited before penalty setup*/
    bool penCoachMovesPlayers;       /* coach moves players when positioned wrongly */
    double penDistanceX;             /* distance from goal to place ball  */
    int penMaxExtraKicks;            /* max. nr of extra penalty kicks    */
    double penMaxGoalieDistanceX;    /* max distance from goal for goalie */
    int penNumberOfKicks;            /* number of penalty kicks           */
    bool penRandomWinner;            /* random winner when draw?          */
    int penReadyWait;                /* cycles waited to take penalty     */
    int penSetupWait;                /* cycles waited to setup penalty    */
    int penTakenWait;                /* cycles waited to finish penalty   */
    bool penaltyShootOuts;           /* penalty shoot outs after extra halfs*/
    double redCardProbability;
    
    int pointsToBan;
    int pointsToDuration;
    
    int port;                        /* port number */
    double teamLeftRandomFactor;     /* factor to multiple prand for left team */
    double teamRightRandomFactor;    /* factor to multiple prand for right team */
    bool profile;
    bool properGoalKicks;
    double quantizeStepDistance;         /* quantize step of distance */
    double quantizeStepDistanceLandmark; /* quantize step of distance for landmark */
    bool recordMessages;

    int recieveStep;                 /* udp recv step interval msec */
    int sayMessageSize;              /* string size of say message */
    bool sendComms;
    int sendStep;                    /* udp send step interval msec for player's default view mode*/
    double sideDashRate;
    int simulatorStep;               /* simulator step interval msec */
    int slowDownFactor;              /* factor to slow down simulator and send intervals */
    int slownessOnTopForLeftTeam;
    int slownessOnTopForRightTeam;
    double staminaCapacity;
    
    int startGoalLeft;               /* The starting score of the left team */
    int startGoalRight;              /* The starting score of the right team */
    double stoppedBallVel;
    int synchMicroSleep;             /* pfr:SYNCH the # of microseconds to sleep while waiting for players */
    bool synchMode;                  /* pfr:SYNCH whether to run in synchronized mode */
    int synchOffset;                 /* pfr:SYNCH the offset from the start of the cycle to tell players to run */
    int synchSeeOffset;              //!< synch see offset
    
    double tackleBackDistance;
    int tackleCycles;
    double tackleDistance;
    double tackleExponent;
    double tacklePowerRate;
    double tackleRandFactor;
    double tackleWidth;
    
    bool teamActuatorNoise;          /* flag whether to use team specific actuator noise */
    std::string teamLeftStart;
    std::string teamLeftRight;
    bool verbose;                    /* flag for verbose mode */

    double visibleAngle;            /* visible angle */
    double visibleDistance;         /* visible distance */
    int senseBodyStep;              /* sense_body interval step msec */
    
    double windDirection;    /* wind direction */
    double windForce;        /* wind force */
    double windAngle;        /* wind angle for rand */
    double windRand;         /* wind force for force */
    bool windNone;           /* wind factor is none */
    bool windRandom;         /* wind factor is random */
    
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: ServerState Constructor                                                       *
     * The Input: map<string, ParseType>                                                            *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input as reference map for types.         *
     * *********************************************************************************************/
    
    ServerState(const std::map<std::string, parse::ParseType>& cParseMap);
    
    /**********************************************************************************************
     * function name: ServerState Destructor                                                      *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~ServerState();
    
};

#endif
