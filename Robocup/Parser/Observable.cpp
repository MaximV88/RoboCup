/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Implementation of Observable Class     *
 ***********************************************************/

#include <iostream>
#include "Observable.h"
#include "LandMarker.h"

#define OUTPUT_STRING_FLAG "Flag"
#define OUTPUT_STRING_BALL "Ball"
#define OUTPUT_STRING_PLAYER "Player"
#define OUTPUT_STRING_LINE "Line"
#define OUTPUT_STRING_GOAL "Goal"

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: Observable Constructor                                                        *
 * The Input: ObservableType                                                                    *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the member variables to default values.                   *
 * *********************************************************************************************/

Observable::Observable(ObservableType eType) : type(eType) {

    //Initialize the numbers
    teamName = "";
    uniformNumber = 0;
    goalie = false;
    origin = landmarks::LandMarker::getInstance().getOriginByType(eType);
    
    distance = 0;
    direction = 0;
    distanceChange = 0;
    directionChange = 0;
    bodyFacingDirection = 0;
    headFacingDirection = 0;
    
    knownProperties = ObservablePropertyTypeDistance;
    
}

Observable::Observable(const Observable& cObservable) :
type(cObservable.type) {
    
    //Copy all member values
    teamName = cObservable.teamName;
    uniformNumber = cObservable.uniformNumber;
    goalie = cObservable.goalie;
    
    distance = cObservable.distance;
    direction = cObservable.distance;
    distanceChange = cObservable.distanceChange;
    directionChange = cObservable.directionChange;
    bodyFacingDirection = cObservable.bodyFacingDirection;
    headFacingDirection = cObservable.headFacingDirection;
    
    //Stores the last known property
    knownProperties = cObservable.knownProperties;
    
    //The Observable's origin
    if (cObservable.origin != NULL)
        origin = new Coordinate(*cObservable.origin);
    else
        origin = NULL;
    
}

/**********************************************************************************************
 * function name: Observable Destructor                                                       *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Nothing.                                                            *
 * *******************************************************************************************/

Observable::~Observable() {

    //Delete coordinate if exists
    if (origin != NULL)
        delete origin;

}

//Coordinate* Observable::calculateOrigin(double dPercentX, double dPercentY, const &c

/************************************************************************************
 * function name: operator<<                                                        *
 * The Input: ostream object (reference), const Observable object (reference)       *
 * The output: ostream object (reference)                                           *
 * The Function Opertion: Prints the object's member variables into the input       *
 *                        ostream object, and returns it afterwards. It first       *
 *                        puts into a string the type of the object, and then       *
 *                        prints all of it's attributes.                            *
 * *********************************************************************************/

std::ostream& operator<<(std::ostream &out, const Observable &cObservable) {
    
    //First get the type to a string
    std::string strObservable;
    
    switch (cObservable.type) {
        case ObservableTypeFlagCenter:
        case ObservableTypeFlagCenterTop:
        case ObservableTypeFlagCenterBottom:
        case ObservableTypeFlagLeftTop:
        case ObservableTypeFlagLeftTop30:
        case ObservableTypeFlagLeftTop20:
        case ObservableTypeFlagLeftTop10:
        case ObservableTypeFlagLeftBottom:
        case ObservableTypeFlagLeftBottom30:
        case ObservableTypeFlagLeftBottom20:
        case ObservableTypeFlagLeftBottom10:
        case ObservableTypeFlagRightTop:
        case ObservableTypeFlagRightTop30:
        case ObservableTypeFlagRightTop20:
        case ObservableTypeFlagRightTop10:
        case ObservableTypeFlagRightBottom:
        case ObservableTypeFlagRightBottom30:
        case ObservableTypeFlagRightBottom20:
        case ObservableTypeFlagRightBottom10:
        case ObservableTypeFlagPenLeftTop:
        case ObservableTypeFlagPenLeftCenter:
        case ObservableTypeFlagPenLeftBottom:
        case ObservableTypeFlagPenRightTop:
        case ObservableTypeFlagPenRightCenter:
        case ObservableTypeFlagPenRightBottom:
        case ObservableTypeFlagGoalLeftTop:
        case ObservableTypeFlagGoalLeftBottom:
        case ObservableTypeFlagGoalRightTop:
        case ObservableTypeFlagGoalRightBottom:
        case ObservableTypeFlagLeft0:
        case ObservableTypeFlagRight0:
        case ObservableTypeFlagTop0:
        case ObservableTypeFlagBottom0:
        case ObservableTypeFlagTopLeft50:
        case ObservableTypeFlagTopLeft40:
        case ObservableTypeFlagTopLeft30:
        case ObservableTypeFlagTopLeft20:
        case ObservableTypeFlagTopLeft10:
        case ObservableTypeFlagTopRight50:
        case ObservableTypeFlagTopRight40:
        case ObservableTypeFlagTopRight30:
        case ObservableTypeFlagTopRight20:
        case ObservableTypeFlagTopRight10:
        case ObservableTypeFlagBottomLeft50:
        case ObservableTypeFlagBottomLeft40:
        case ObservableTypeFlagBottomLeft30:
        case ObservableTypeFlagBottomLeft20:
        case ObservableTypeFlagBottomLeft10:
        case ObservableTypeFlagBottomRight50:
        case ObservableTypeFlagBottomRight40:
        case ObservableTypeFlagBottomRight30:
        case ObservableTypeFlagBottomRight20:
        case ObservableTypeFlagBottomRight10:
        case ObservableTypeFlag:

            strObservable = OUTPUT_STRING_FLAG;
            break;
            
        case ObservableTypeGoalLeft:
        case ObservableTypeGoalRight:
        case ObservableTypeGoal:

            strObservable = OUTPUT_STRING_GOAL;
            break;
            
        case ObservableTypeLineTop:
        case ObservableTypeLineBottom:
        case ObservableTypeLineRight:
        case ObservableTypeLineLeft:
            
            strObservable = OUTPUT_STRING_LINE;
            break;
            
        case ObservableTypeBall:
            
            strObservable = OUTPUT_STRING_BALL;
            break;
            
        case ObservableTypePlayer:
            
            strObservable = OUTPUT_STRING_PLAYER;
            break;

        default:
            break;
    }
    
    //Print
    out << "(Observable Type: " << strObservable << ", Direction: " << cObservable.direction << ", Distance: "
    << cObservable.distance << ", Direction change: " << cObservable.directionChange << ", Distance change: " <<
    cObservable.distanceChange << ", Body facing direction: " << cObservable.bodyFacingDirection <<
    ", Head facing direction: " << cObservable.headFacingDirection << ")";
    
    return out;

}
