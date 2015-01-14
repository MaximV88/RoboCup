/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Declaration of Observable Class        *
 ***********************************************************/

#ifndef __Ex3__Observable__
#define __Ex3__Observable__

#include <stdio.h>
#include <string>
#include "Coordinate.h"

typedef enum {
  
    ObservableTypeFlagCenter,
    ObservableTypeFlagCenterTop,
    ObservableTypeFlagCenterBottom,
    ObservableTypeFlagLeft,
    ObservableTypeFlagLeftTop,
    ObservableTypeFlagLeftTop30,
    ObservableTypeFlagLeftTop20,
    ObservableTypeFlagLeftTop10,
    ObservableTypeFlagLeftBottom,
    ObservableTypeFlagLeftBottom30,
    ObservableTypeFlagLeftBottom20,
    ObservableTypeFlagLeftBottom10,
    ObservableTypeFlagRight,
    ObservableTypeFlagRightTop,
    ObservableTypeFlagRightTop30,
    ObservableTypeFlagRightTop20,
    ObservableTypeFlagRightTop10,
    ObservableTypeFlagRightBottom,
    ObservableTypeFlagRightBottom30,
    ObservableTypeFlagRightBottom20,
    ObservableTypeFlagRightBottom10,
    ObservableTypeFlagPenLeftTop,
    ObservableTypeFlagPenLeftCenter,
    ObservableTypeFlagPenLeftBottom,
    ObservableTypeFlagPenRightTop,
    ObservableTypeFlagPenRightCenter,
    ObservableTypeFlagPenRightBottom,
    ObservableTypeFlagGoalLeftTop,
    ObservableTypeFlagGoalLeftBottom,
    ObservableTypeFlagGoalRightTop,
    ObservableTypeFlagGoalRightBottom,
    ObservableTypeGoalLeft,
    ObservableTypeGoalRight,
    ObservableTypeFlagLeft0,
    ObservableTypeFlagRight0,
    ObservableTypeFlagTop0,
    ObservableTypeFlagBottom0,
    ObservableTypeFlagTopLeft50,
    ObservableTypeFlagTopLeft40,
    ObservableTypeFlagTopLeft30,
    ObservableTypeFlagTopLeft20,
    ObservableTypeFlagTopLeft10,
    ObservableTypeFlagTopRight50,
    ObservableTypeFlagTopRight40,
    ObservableTypeFlagTopRight30,
    ObservableTypeFlagTopRight20,
    ObservableTypeFlagTopRight10,
    ObservableTypeFlagBottomLeft50,
    ObservableTypeFlagBottomLeft40,
    ObservableTypeFlagBottomLeft30,
    ObservableTypeFlagBottomLeft20,
    ObservableTypeFlagBottomLeft10,
    ObservableTypeFlagBottomRight50,
    ObservableTypeFlagBottomRight40,
    ObservableTypeFlagBottomRight30,
    ObservableTypeFlagBottomRight20,
    ObservableTypeFlagBottomRight10,
    ObservableTypeLineTop,
    ObservableTypeLineBottom,
    ObservableTypeLineRight,
    ObservableTypeLineLeft,
    ObservableTypeBall,
    ObservableTypePlayer,
    ObservableTypeGoal,
    ObservableTypeFlag,
    ObservableTypeNone
    
} ObservableType;

typedef enum {
    
    ObservablePropertyTypeDistance = 1,
    ObservablePropertyTypeDirection,
    ObservablePropertyTypeDistChange,
    ObservablePropertyTypeDirectionChange,
    ObservablePropertyTypeBodyFacingDirection,
    ObservablePropertyTypeHeadFacingDirection
    
} ObservablePropertyType;

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
    
    //The Observable's origin
    Coordinate* origin;
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: Observable Constructor                                                        *
     * The Input: ObservableType                                                                    *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input as the object's type.               *
     * *********************************************************************************************/
    
    Observable(ObservableType eType);
    
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
