/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Declaration of MidFielder Class        *
 ***********************************************************/

#ifndef __Ex3__MidFielder__
#define __Ex3__MidFielder__

#include <stdio.h>
#include "Player.h"

/**********************************************************************************
 * MidFielder Class: Represents a player that plays like a MidFielder.            *
 *                   It deals with the information recieved from the states       *
 *                   by sending instructions.                                     *
 *********************************************************************************/

class MidFielder : public Player {
    
private:
    
    void actPlayMode(PlayMode ePlayMode);

public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: MidFielder Constructor                                                        *
     * The Input: const Connection object (pointer), const char (pointer), const Vector (reference) *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input client connection,                  *
     *                        team name and position.                                               *
     * *********************************************************************************************/
    
    MidFielder(const Connection* cConnection, const char* chTeamName);
    
    /**********************************************************************************************
     * function name: MidFielder Destructor                                                       *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~MidFielder();
    

};

#endif
