/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Declaration of BodyState Class         *
 ***********************************************************/

#ifndef __Ex3__FieldState__
#define __Ex3__FieldState__

#include <stdio.h>
#include "State.h"
#include "Vector.h"

typedef enum {
    WidthTypeNarrow,
    WidthTypeNormal,
    WidthTypeWide,
    WidthTypeNone
} WidthType;

typedef enum {
    QualityTypeHigh,
    QualityTypeLow,
    QualityTypeNone
} QualityType;

/*******************************************************************************
 * BodyState Class: Represents the Sensing input recieved from the server,     *
 *                  all information recieved in (sense_body ...)               *
 ******************************************************************************/

class BodyState : public State {
    
private:
    
    //  ---                         PRIVATE FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: assignValues                                                                  *
     * The Input: vector<string> (reference)                                                        *
     * The output: none                                                                             *
     * The Function Opertion: assigns the values related to the input in the vector argument        *
     *                        to the state's member variable.                                       *
     * *********************************************************************************************/
    
    virtual void assignValues(const std::vector<std::string>& vcSentences);

public:
    
    int time;                       /* The time (in server cycles) that the
                                     *  message was sent by the simulator. */
    
    WidthType viewModeWidth;
    QualityType viewModeQuality;
    double stamina;                 /* The client's stamina. */
    double effort;                  /* The client's effort. */
    double speedMagnitude;          /* The magnitude of the client's velocity. */
    double speedDirection;          /* The heading of the client's velocity, relative to it's body direction. */
    double headAngle;               /* The client's head angle relative to it's body direction. */
    int kickCount;                  /* The number of kick commands the client has executed. */
    int dashCount;                  /* The number of dash commands the client has executed. */
    int turnCount;                  /* The number of turn commands the client has executed. */
    int sayCount;                   /* The number of say commands the client has executed. */
    int turnNeckCount;              /* The number of turn neck commands the client has executed. */
    int catchCount;                 /* The number of catch commands the client has executed. */
    int moveCount;                  /* The number of move commands the client has executed. */
    int changeViewCount;            /* The number of change view commands the client has executed. */
    

    int armMovable;    /* The number of cycles until the client or player can change where it's pointing to. */
    int armExpires;    /* The number of cycles until the client or player will automatically stop pointing. */
    int armCount;      /* The number of times the client or player has excuted a point to command. */
    Vector armTarget;  /* The co-ordinate of the point the client or player is pointing to. */
    
    
    int focusUnum;   /* The uniform number of the player the client is focued on. */
    int focusCount;  /* The number of times the client has excuted an attention to command.*/
    std::string focusSide;
    
    
    int tackleExpires;    /* The number of cycles till client finishes tackling. */
    int tackleCount;      /* The number of times the client has excuted an tackle command. */
        
    
    std::string collision;
    
    
    int foulCharged;
    
    //TODO: change to enum
    std::string foulCard;
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: BodyState Constructor                                                         *
     * The Input: map<string, ParseType>                                                            *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input as reference map for types.         *
     * *********************************************************************************************/
    
    BodyState(const std::map<std::string, parse::ParseType>& cParseMap);
    
    /**********************************************************************************************
     * function name: BodyState Destructor                                                        *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~BodyState();
    
    /************************************************************************************
     * function name: operator<<                                                        *
     * The Input: ostream object (reference), const BodyState object (reference)        *
     * The output: ostream object (reference)                                           *
     * The Function Opertion: Prints the object.                                        *
     * *********************************************************************************/
    
    friend std::ostream& operator<<(std::ostream &out, const BodyState &cBodyState);

    
};

#endif 
