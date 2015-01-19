/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Implementation of Defender Class       *
 ***********************************************************/

#include "Defender.h"

void Defender::actPlayMode(PlayMode ePlayMode)  {
    
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: Defender Constructor                                                          *
 * The Input: const Connection object (pointer), const char (pointer), const Vector (reference) *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the base class.                                           *
 * *********************************************************************************************/

Defender::Defender(const Connection* cConnection, const char* chTeamName) :
Player(cConnection, chTeamName) {
    
}

/**********************************************************************************************
 * function name: Defender Destructor                                                         *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Nothing.                                                            *
 * *******************************************************************************************/

Defender::~Defender() {
    
}
