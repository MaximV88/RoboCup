/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Robocup__MidFielderB__
#define __Robocup__MidFielderB__

#include "Player.h"

/**********************************************************************************
 * MidFielder Class: Represents a player that plays like a MidFielder.            *
 *                   It deals with the information recieved from the states       *
 *                   by sending instructions.                                     *
 *********************************************************************************/

class MidFielderB : public Player {
    
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
    
    MidFielderB(const Connection* cConnection, const char* chTeamName);
    
    /**********************************************************************************************
     * function name: MidFielder Destructor                                                       *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~MidFielderB();
    
    
};

#endif
