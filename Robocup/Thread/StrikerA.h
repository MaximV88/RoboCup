/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Robocup__StrikerA__
#define __Robocup__StrikerA__

#include <stdio.h>
#include "Player.h"

/**********************************************************************************
 * Forward Class: Represents a player that plays like a Forward.                  *
 *                   It deals with the information recieved from the states       *
 *                   by sending instructions.                                     *
 *********************************************************************************/

class StrikerA : public Player {
    
private:
    
    void actPlayMode(PlayMode ePlayMode);
    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: Forward Constructor                                                           *
     * The Input: const Connection object (pointer), const char (pointer), const Vector (reference) *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input client connection,                  *
     *                        team name and position.                                               *
     * *********************************************************************************************/
    
    StrikerA(const Connection* cConnection, const char* chTeamName);
    
    /**********************************************************************************************
     * function name: Forward Destructor                                                          *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~StrikerA();
    
    
};

#endif
