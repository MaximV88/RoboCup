/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Declaration of PlayerState Class       *
 ***********************************************************/

#ifndef __Ex3__PlayerState__
#define __Ex3__PlayerState__

#include <stdio.h>
#include "State.h"

/*******************************************************************************
 * PlayerState Class: Represents the Player input recieved from the server,    *
 *                    all information recieved in (player_type ...)            *
 ******************************************************************************/

class PlayerState : public State {
    
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
    
    int ID;
    double playerSpeedMax;
    double StaminaIncMax;
    double playerDecay;
    double inertiaMoment;
    double dashPowerRate;
    double playerSize;
    double kickableMargin;
    double kickRand;
    double extraStamina;
    double effortMax;
    double effortMin;
    double kickPowerRate;
    double foulDetectProbability;
    double catchableAreaLStretch;
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: PlayerState Constructor                                                       *
     * The Input: map<string, ParseType>                                                            *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input as reference map for types.         *
     * *********************************************************************************************/
    
    PlayerState(const std::map<std::string, parse::ParseType>& cParseMap);
    
    /**********************************************************************************************
     * function name: PlayerState Destructor                                                      *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~PlayerState();

};

#endif  
