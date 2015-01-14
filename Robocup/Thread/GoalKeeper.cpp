/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Implementation of GoalKeeper Class     *
 ***********************************************************/

#include "GoalKeeper.h"

void GoalKeeper::actTeamState(const TeamState& cTeamState) {
    
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: GoalKeeper Constructor                                                        *
 * The Input: const Connection object (pointer), const char (pointer), const Vector (reference) *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the base class.                                           *
 * *********************************************************************************************/

GoalKeeper::GoalKeeper(const Connection* cConnection, const char* chTeamName) :
Player(cConnection, chTeamName) {
    
}

/**********************************************************************************************
 * function name: GoalKeeper Destructor                                                       *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Nothing.                                                            *
 * *******************************************************************************************/

GoalKeeper::~GoalKeeper() {
    
}
