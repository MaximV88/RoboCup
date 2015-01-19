/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Declaration of Observable Class        *
 ***********************************************************/

#ifndef __Ex3__Observable__
#define __Ex3__Observable__

#include <stdio.h>
#include <string>
#include "ObservableTypes.h"

/*************************************************************************************
 * Observable Class: Represents an object that is seen by the player.                *
 ************************************************************************************/

class Observable { 

public:
    
    //  ---                         PUBLIC VARIABLES                       ---   //
    
    
    std::string teamName;
    int uniformNumber;
    bool goalie;
    
    const ObservableType type;
    
    double distance;
    double direction;
    double distanceChange;
    double directionChange;
    double bodyFacingDirection;
    double headFacingDirection;
    
    //Stores the last known property
    ObservablePropertyType knownProperties;
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: Observable Constructor                                                        *
     * The Input: ObservableType                                                                    *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input as the object's type.               *
     * *********************************************************************************************/
    
    Observable(ObservableType eType);
    
    Observable(const Observable& cObservable);

    
    /**********************************************************************************************
     * function name: Observable Destructor                                                       *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~Observable();
    
    /************************************************************************************
     * function name: operator<<                                                        *
     * The Input: ostream object (reference), const Observable object (reference)       *
     * The output: ostream object (reference)                                           *
     * The Function Opertion: Prints the object.                                        *
     * *********************************************************************************/
    
    friend std::ostream& operator<<(std::ostream &out, const Observable &cObservable);


};

#endif  
