//
//  StrikerB.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/28/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Robocup__StrikerB__
#define __Robocup__StrikerB__

#include <stdio.h>
#include "Player.h"

/**********************************************************************************
 * Forward Class: Represents a player that plays like a Forward.                  *
 *                   It deals with the information recieved from the states       *
 *                   by sending instructions.                                     *
 *********************************************************************************/

class StrikerB : public Player {
    
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
    
    StrikerB(const Connection* cConnection, const char* chTeamName);
    
    /**********************************************************************************************
     * function name: Forward Destructor                                                          *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~StrikerB();
    
    
};

#endif
