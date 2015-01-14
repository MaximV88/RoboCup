/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Implementation of BodyState Class      *
 ***********************************************************/

#include "BodyState.h"
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <iterator>

#define ASSIGNED_NONE "none"
#define MISSING_PARSE_MESSAGE "BodyState error: Missing a parse case- "
#define MISSING_PARSE_EXTRACTION ", Printing incoming stack: "

using namespace std;
using namespace parse;

//  ---                         PRIVATE FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: assignValues                                                                  *
 * The Input: vector<string> (reference)                                                        *
 * The output: none                                                                             *
 * The Function Opertion: Iterates over the input segmented strings and assignes each type      *
 *                        accordingly. The process if specified in the remarks.                 *
 * *********************************************************************************************/

void BodyState::assignValues(const std::vector<std::string>& vcSentences) {
    
    for (vector<string>::const_iterator iter = vcSentences.begin() ; iter != vcSentences.end() ;) {
        
        //Assign it to a string stream
        stringstream rstream(*iter);
        
        istream_iterator<string> runner(rstream);
        
        //This holds the main attribute of the sentence, meaning what to do with the information
        string strFirst = *runner;
        
        //Go to the value stored
        ++runner;
        
        switch (parseWord(strFirst)) {
                
                //Each of the following cases just assignes values
            case ParseTypeViewMode:
                
                //This is also parsed
                switch (parseWord(*runner)) {
                    case ParseTypeViewModeQualityHigh:
                        viewModeQuality = QualityTypeHigh;
                        break;
                        
                    case ParseTypeViewModeQualityLow:
                        viewModeQuality = QualityTypeLow;
                        break;
                        
                    default:
                        break;
                }
                
                
                //Now for the width
                ++runner;
                
                switch (parseWord(*runner)) {
                    case ParseTypeViewModeWidthNarrow:
                        viewModeWidth = WidthTypeNarrow;
                        break;
                        
                    case ParseTypeViewModeWidthNormal:
                        viewModeWidth = WidthTypeNormal;
                        break;
                        
                    case ParseTypeViewModeWidthWide:
                        viewModeWidth = WidthTypeWide;
                        break;
                        
                    default:
                        break;
                }
                
                //End of view mode
                break;
                
            case ParseTypeSenseBody:
                
                time = atoi((*runner).data());
                break;
                
            case ParseTypeStamina:
                
                //First value is the stamina
                stamina = atof((*runner).data());
                
                //The second one is the effort - CHECK BUG ON CONSULE, ' ' instead of '.'
                ++runner;
                ++runner;
                effort = atof((*runner).data());
                
                break;
                
            case ParseTypeSpeed:
                
                //First value is the speed magnitude
                speedMagnitude = atof((*runner).data());
                
                //The second one is the speed direction
                ++runner;
                speedDirection = atof((*runner).data());
                
                break;
                
            case ParseTypeHeadAngle:
                
                headAngle = atof((*runner).data());
                break;

            case ParseTypeKick:
                
                kickCount = atoi((*runner).data());
                break;
                
            case ParseTypeDash:
                
                dashCount = atoi((*runner).data());
                break;

            case ParseTypeTurn:
                
                turnCount = atoi((*runner).data());
                break;
                
            case ParseTypeSay:
                
                sayCount = atoi((*runner).data());
                break;
                
            case ParseTypeTurnNeck:
                
                turnNeckCount = atoi((*runner).data());
                break;
                
            case ParseTypeCatch:
                
                catchCount = atoi((*runner).data());
                break;
                
            case ParseTypeMove:
                
                moveCount = atoi((*runner).data());
                break;

            case ParseTypeChangeView:
                
                changeViewCount = atoi((*runner).data());
                break;
                
            case ParseTypeCollision:
                
                collision = *runner;

                if (collision != ASSIGNED_NONE) {
                    
                    ++iter;
                    collision = *iter;
                    
                }
                
                break;

            //This case holds other cases, which is best treated as a loop by itself
            case ParseTypeArm:
                
            {

                //Advance to the contained types
                for (unsigned short usIndex = 0 ; usIndex < 4 ; usIndex++) {
                    
                    ++iter;
                    stringstream cstream(*iter);
                    istream_iterator<string> chaser(cstream);
                    
                    string strType = *chaser;
                    
                    //Get to the value
                    ++chaser;
                    
                    switch (parseWord(strType)) {
                        case ParseTypeMovable:
                            
                            armMovable = atoi((*chaser).data());
                            break;
                            
                        case ParseTypeExpires:
                            
                            armExpires = atoi((*chaser).data());
                            break;
                            
                        case ParseTypeTarget:
                            
                        {
                            
                            double dX;
                            double dY;
                            dX = atof((*chaser).data());
                            
                            //The second one is the speed direction
                            ++runner;
                            dY = atof((*chaser).data());
                            
                            
                            armTarget = Vector(dX, dY);
                            
                            break;
                            
                        }
                            
                        case ParseTypeCount:
                            
                            armCount = atoi((*chaser).data());
                            break;
                            
                        default:
                            break;
                    }
                    
                }
                
                break;
                
            }
                
                //This case holds other cases, which is best treated as a loop by itself
            case ParseTypeFocus:
                
                for (unsigned short usIndex = 0 ; usIndex < 2 ; usIndex++) {
                    
                    ++iter;
                    stringstream cstream(*iter);
                    istream_iterator<string> chaser(cstream);
                    
                    string strType = *chaser;
                    
                    //Get to the value
                    ++chaser;
                    
                    switch (parseWord(strType)) {
                        case ParseTypeTarget:
                            
                            focusSide = *chaser;

                            //There are two possibilities here, either its none or it has a value
                            if (*chaser != ASSIGNED_NONE) {
                                
                                ++chaser;
                                
                                //Its the target 'side' and then the 'unum'
                                focusUnum = atoi((*runner).data());

                            }
                            
                            break;
                            
                        case ParseTypeCount:
                            
                            focusCount = atoi((*chaser).data());
                            break;
                            
                        default:
                            break;
                    }
                    
                    
                }
                
                break;

            case ParseTypeTackle:

                for (unsigned short usIndex = 0 ; usIndex < 2 ; usIndex++) {
                    
                    ++iter;
                    stringstream cstream(*iter);
                    istream_iterator<string> chaser(cstream);
                    
                    string strType = *chaser;
                    
                    //Get to the value
                    ++chaser;
                    
                    switch (parseWord(strType)) {
                        case ParseTypeExpires:
                            
                            tackleExpires = atoi((*chaser).data());

                            break;
                            
                        case ParseTypeCount:
                            
                            tackleCount = atoi((*chaser).data());
                            break;
                            
                        default:
                            break;
                    }
                    
                }
                
                break;
                
            case ParseTypeFoul:
                
                for (unsigned short usIndex = 0 ; usIndex < 2 ; usIndex++) {
                    
                    ++iter;
                    stringstream cstream(*iter);
                    istream_iterator<string> chaser(cstream);
                    
                    string strType = *chaser;
                    
                    //Get to the value
                    ++chaser;
                    
                    switch (parseWord(strType)) {
                        case ParseTypeCharged:
                            
                            foulCharged = atoi((*chaser).data());
                            
                            break;
                            
                        case ParseTypeCard:
                            
                            foulCard = *chaser;
                            break;
                            
                        default:
                            break;
                    }
                    
                }
                
                break;
                
            //Shouldnt reach here
            default:
                cerr << MISSING_PARSE_MESSAGE << strFirst << MISSING_PARSE_EXTRACTION << endl;
                
                //Message stack printing
                for (vector<string>::const_iterator chaser = vcSentences.begin() ;
                     chaser != vcSentences.end() ;
                     chaser++) {
                    
                    cout << *chaser << endl;
                    
                }
                
                break;
        }
     
        //Increment the count
        ++iter;
        
    }
    
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: BodyState Constructor                                                         *
 * The Input: map<string, ParseType>                                                            *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with input as reference map for types.         *
 * *********************************************************************************************/

BodyState::BodyState(const std::map<std::string, ParseType>& cParseMap) :
State(cParseMap, StateTypeBody) {
    
}

/**********************************************************************************************
 * function name: BodyState Destructor                                                        *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Destroys the current object.                                        *
 * *******************************************************************************************/

BodyState::~BodyState() { }

/************************************************************************************
 * function name: operator<<                                                        *
 * The Input: ostream object (reference), const SeeState object (reference)         *
 * The output: ostream object (reference)                                           *
 * The Function Opertion: Prints the object's member variables into the input       *
 *                        ostream object, and returns it afterwards. It tries       *
 *                        to match a string to every type, and then prints the      *
 *                        member variables.                                         *
 * *********************************************************************************/

std::ostream& operator<<(std::ostream &out, const BodyState &cBodyState) {
    
    string strViewModeWidth;
    
    switch (cBodyState.viewModeWidth) {
        case WidthTypeNone:
            strViewModeWidth = "None";
            break;
            
        case WidthTypeNarrow:
            strViewModeWidth = "Narrow";
            break;
            
        case WidthTypeNormal:
            strViewModeWidth = "Normal";
            break;
            
        case WidthTypeWide:
            strViewModeWidth = "Wide";
            break;
            
        default:
            break;
    }
    
    string strViewModeQuality;
    
    switch (cBodyState.viewModeQuality) {
        case QualityTypeNone:
            strViewModeQuality = "None";
            break;
            
        case QualityTypeLow:
            strViewModeQuality = "Low";
            break;
            
        case QualityTypeHigh:
            strViewModeQuality = "High";
            break;
            
        default:
            break;
    }

    out << "(ViewModeWidth: " << strViewModeWidth << ", ViewModeQuality: " << strViewModeQuality << ", Stamina:" << cBodyState.stamina
    << ", Effort: " << cBodyState.effort << ", SpeedMagnitude: " << cBodyState.speedMagnitude <<
    ", SpeedDirection: " << cBodyState.speedDirection << ", HeadAngle: " << cBodyState.headAngle << ", Collision: " << cBodyState.collision << ")";
          
    return out;
    
}
