/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Declaration of TeamState Class         *
 ***********************************************************/

#ifndef __Ex3__GameState__
#define __Ex3__GameState__

#include <stdio.h>
#include "State.h"

typedef enum {
    
    TeamSideNull = 0,
    TeamSideRight,
    TeamSideLeft
    
}TeamSide;

typedef enum {
    
    PlayModeNull = 1000,
    PlayModeBeforeKickOff,
    PlayModeTimeOver,
    PlayModePlayOn,
    PlayModeKickOffLeft,
    PlayModeKickOffRight,
    PlayModeKickInLeft,
    PlayModeKickInRight,
    PlayModeFreeKickLeft,
    PlayModeFreeKickRight,
    PlayModeCornerKickLeft,
    PlayModeCornerKickRight,
    PlayModeGoalKickLeft,
    PlayModeGoalKickRight,
    PlayModeAfterGoalLeft,
    PlayModeAfterGoalRight,
    PlayModeDropBall,
    PlayModeOffsideLeft,
    PlayModeOffsideRight,
    PlayModeMax
    
}PlayMode;

class HearState;

/*******************************************************************************
 * TeamState Class: Represents the Team input recieved from the server,        *
 *                  all information recieved in (player_param ...)             *
 ******************************************************************************/

class TeamState : public State {

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

    TeamSide teamSide;
    PlayMode playMode;
    int unum;
    
    bool allowMultipleDefaultType; //!< whether multiple default type is allowed
    double catchableAreaLStretchMax;
    double catchableAreaLStretchMin;
    double dashPowerRateDeltaMax;      //!< maximal value wighin delta range
    double dashPowerRateDeltaMin;      //!< minimal value wighin delta range
    double effortMaxDeltaFactor;       //!< tradeoff parameter
    double effortMinDeltaFactor;       //!< tradeoff parameter
    double extraStaminaDeltaMax;       //!< maximal value wighin delta range
    double extraStaminaDeltaMin;       //!< minimal value wighin delta range
    
    double foulDetectProbabilityDeltaFactor;
    
    double inertiaMomentDeltaFactor;  //!< tradeoff parameter
    double kickPowerRateDeltaMax;
    double kickPowerRateDeltaMin;
    double kickRandDeltaFactor;       //!< tradeoff parameter
    double kickableMarginDeltaMax;    //!< maximal value wighin delta range
    double kickableMarginDeltaMin;
    double newDashPowerRateDeltaMax;
    double newDashPowerRateDeltaMin;
    double newStaminaIncMaxDeltaFactor;
    double playerDecayDeltaMax;
    double playerDecayDeltaMin;
    double playerSizeDeltaFactor;
    double playerSpeedMaxDeltaMax;
    double playerSpeedMaxDeltaMin;
    int playerTypes;
    double ptMax;
    int randomSeed;
    double staminaIncMaxDeltaFactor;
    int subsMax;
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: TeamState Constructor                                                         *
     * The Input: map<string, ParseType>                                                            *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input as reference map for types.         *
     * *********************************************************************************************/

    TeamState(const std::map<std::string, parse::ParseType>& cParseMap);
    
    /**********************************************************************************************
     * function name: TeamState Destructor                                                        *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~TeamState();
    
    /**********************************************************************************************
     * function name: convert                                                                     *
     * The Input: const HearState object (reference)                                              *
     * The output: none                                                                           *
     * The Function Opertion: Changed the appropriate member variable.                            *
     *                        Returns true if changed value, false otherwise                      *
     * *******************************************************************************************/
    
    bool convert(const HearState& cHearState);
    

};

#endif  
