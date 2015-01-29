/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Declaration of Forward Class           *
 ***********************************************************/

#ifndef __Ex3__Forward__
#define __Ex3__Forward__

#include <stdio.h>
#include "Player.h"

/**********************************************************************************
 * Forward Class: Represents a player that plays like a Forward.                  *
 *                   It deals with the information recieved from the states       *
 *                   by sending instructions.                                     *
 *********************************************************************************/

class Striker : public Player {
    
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
    
    Striker(const Connection* cConnection, const char* chTeamName);
    
    /**********************************************************************************************
     * function name: Forward Destructor                                                          *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~Striker();
    

};

#endif 
