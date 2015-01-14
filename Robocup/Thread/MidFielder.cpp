/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Implementation of MidFielder Class     *
 ***********************************************************/

#include "MidFielder.h"

void MidFielder::actTeamState(const TeamState& cTeamState) {
    
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: MidFielder Constructor                                                        *
 * The Input: const Connection object (pointer), const char (pointer), const Vector (reference) *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the base class.                                           *
 * *********************************************************************************************/

MidFielder::MidFielder(const Connection* cConnection, const char* chTeamName) :
Player(cConnection, chTeamName) {
    
}

/**********************************************************************************************
 * function name: MidFielder Destructor                                                       *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Nothing.                                                            *
 * *******************************************************************************************/

MidFielder::~MidFielder() {
    
}
