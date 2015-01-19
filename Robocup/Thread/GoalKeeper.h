/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Declaration of GoalKeeper Class        *
 ***********************************************************/

#ifndef __Ex3__GoalKeeper__
#define __Ex3__GoalKeeper__

#include <stdio.h>
#include "Player.h"

/**********************************************************************************
 * GoalKeeper Class: Represents a player that plays like a GoalKeeper.            *
 *                   It deals with the information recieved from the states       *
 *                   by sending instructions.                                     *
 *********************************************************************************/

class GoalKeeper : public Player {
    
private:
    
    void actPlayMode(PlayMode ePlayMode);

    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: GoalKeeper Constructor                                                        *
     * The Input: const Connection object (pointer), const char (pointer), const Vector (reference) *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input client connection,                  *
     *                        team name and position.                                               *
     * *********************************************************************************************/
    
    GoalKeeper(const Connection* cConnection, const char* chTeamName);
    
    /**********************************************************************************************
     * function name: GoalKeeper Destructor                                                       *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~GoalKeeper();
    
};

#endif
