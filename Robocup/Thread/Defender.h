/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Declaration of Defender Class          *
 ***********************************************************/

#ifndef __Ex3__Defender__
#define __Ex3__Defender__

#include <stdio.h>
#include "Player.h"

/**********************************************************************************
 * Defender Class: Represents a player that plays like a Defender.                *
 *                   It deals with the information recieved from the states       *
 *                   by sending instructions.                                     *
 *********************************************************************************/

class Defender : public Player {
    
private:
    
    void actPlayMode(PlayMode ePlayMode);

public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: Defender Constructor                                                          *
     * The Input: const Connection object (pointer), const char (pointer), const Vector (reference) *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input client connection,                  *
     *                        team name and position.                                               *
     * *********************************************************************************************/
    
    Defender(const Connection* cConnection, const char* chTeamName);
    
    /**********************************************************************************************
     * function name: Defender Destructor                                                         *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~Defender();
    

};

#endif
