/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Implementation of SeeState Class       *
 ***********************************************************/

#include "SeeState.h"
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <iterator>

#define START_DELIMITER "("
#define END_DELIMITER ")"


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

void SeeState::assignValues(const std::vector<std::string>& vcSentences) {
    
    unsigned int uiIndex = 0;
    
    for (vector<string>::const_iterator iter = vcSentences.begin() ; iter != vcSentences.end() && uiIndex <= vcSentences.size() ;) {

        //Assign it to a string stream
        stringstream rstream(*iter);

        istream_iterator<string> runner(rstream);
        istream_iterator<string> end;
        

        //This holds the main attribute of the sentence, meaning what to do with the information
        string strFirst = *runner;
        
        string::size_type iDelim = (*runner).find_first_of(START_DELIMITER);
        
        //If the string starts with a delimiter, it should jump to the parameters
        if (iDelim != string::npos) {
            
            while (true) {
                
                //Until not reaching the ending delimiter, continue
                string::size_type iEndDelim = (*runner).find_first_of(END_DELIMITER);
                
                //Reached
                if (iEndDelim != string::npos)
                    break;
                    
                ++runner;
                
            }
            
            ++runner;
            
        }
        
        //Clear the vector before - this is somewhat wierd that data persists...
        if (!m_vcObservables.empty()) {
            
            for (vector<Observable*>::iterator iter = m_vcObservables.begin() ;
                 iter != m_vcObservables.end() ;
                 iter++) {
                
                delete *iter;
                
            }
        
            m_vcObservables.clear();
            
        }
        
        //This input is more complex compared to the others, there can be several objects.
        switch (parseWord(strFirst)) {
                
            case ParseTypeSee:
                
                //Go to the value stored
                ++runner;
                
                time = atoi((*runner).data());
            
                //The string that says which type obseved is, is after it's properties, so go forward 2 sentences
                iter += 3;
                uiIndex += 3;
                break;
            
            //This means that the input is a player
            case ParseTypePClose:
            case ParseTypeP:
                
            {
                
                //This is the ball - add an object and set it's type
                Observable *cObservable = new Observable(ObservableTypePlayer);
                m_vcObservables.push_back(cObservable);
                
                //A player has a team name
                ++runner;
                cObservable->teamName = *runner;
                
                //A uniform number
                ++runner;
                cObservable->uniformNumber = atoi((*runner).data());
                
                //And if its a goali
                ++runner;
                cObservable->goalie = atoi((*runner).data());
                
                break;
                
            }
                
            //This means that the input is a ball
            case ParseTypeBClose:
            case ParseTypeB:
                
            {
                //This is the ball - add an object and set it's type
                Observable *cObservable = new Observable(ObservableTypeBall);
                m_vcObservables.push_back(cObservable);
                break;
                
            }
                
            //This means that the goal is close
            case ParseTypeGClose:
                
            {
                //This is the gate - add an object and set it's type
                Observable *cObservable = new Observable(ObservableTypeGoal);
                m_vcObservables.push_back(cObservable);
                break;
                
            }
                
            //This means that the flag is close
            case ParseTypeFClose:
                
            {
                //This is the gate - add an object and set it's type
                Observable *cObservable = new Observable(ObservableTypeFlag);
                m_vcObservables.push_back(cObservable);
                break;
                
            }
                
            //This means that the input is a Goal
            case ParseTypeG:
                
                //Check which side the goal is
                ++runner;
                
                switch (parseWord(*runner)) {
                    case ParseTypeL:
                        
                    {
                        //This is the goal on left - add an object and set it's type
                        Observable *cObservable = new Observable(ObservableTypeGoalLeft);
                        m_vcObservables.push_back(cObservable);
                        break;
                        
                    }
                        
                    case ParseTypeR:
                        
                    {
                        //This is the goal on right pen - add an object and set it's type
                        Observable *cObservable = new Observable(ObservableTypeGoalRight);
                        m_vcObservables.push_back(cObservable);
                        break;
                        
                    }
                        
                    default:
                        break;
                }
                
                break;
                
            //This means that the input is a line
            case ParseTypeL:
                
                ++runner;
                
                switch (parseWord(*runner)) {
                        
                    case ParseTypeT:
                        
                    {
                        //This is the line on the top - add an object and set it's type
                        Observable *cObservable = new Observable(ObservableTypeLineTop);
                        m_vcObservables.push_back(cObservable);
                        break;
                        
                    }
                        
                    case ParseTypeB:
                        
                    {
                        //This is the line on the bottom - add an object and set it's type
                        Observable *cObservable = new Observable(ObservableTypeLineBottom);
                        m_vcObservables.push_back(cObservable);
                        break;
                        
                    }

                    case ParseTypeR:
                        
                    {
                        //This is the line on the right - add an object and set it's type
                        Observable *cObservable = new Observable(ObservableTypeLineRight);
                        m_vcObservables.push_back(cObservable);
                        break;
                        
                    }
                        
                    case ParseTypeL:
                        
                    {
                        //This is the line on the left - add an object and set it's type
                        Observable *cObservable = new Observable(ObservableTypeLineLeft);
                        m_vcObservables.push_back(cObservable);
                        break;
                        
                    }
                        
                    default:
                        break;
                }
                
                break;
                
            //This means that the input is a Flag
            case ParseTypeF:
                
                ++runner;
                
                //Find out which kind of Flag
                switch (parseWord(*runner)) {
                        
                    case ParseTypeP:
                        
                        //Check which side
                        ++runner;
                        
                        switch (parseWord(*runner)) {
                            case ParseTypeL:
                                
                                //Check horizontal type
                                ++runner;
                                
                                switch (parseWord(*runner)) {
                                    case ParseTypeT:
                                        
                                    {
                                        //This is the top flag on left pen - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagPenLeftTop);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    case ParseTypeB:
                                        
                                    {
                                        //This is the bottom flag on left pen - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagPenLeftBottom);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    case ParseTypeC:
                                        
                                    {
                                        //This is the central flag on left pen - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagPenLeftCenter);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    default:
                                        break;
                                }
                                
                                break;
                                
                            case ParseTypeR:
                                
                                //Check horizontal type
                                ++runner;
                                
                                switch (parseWord(*runner)) {
                                    case ParseTypeT:
                                        
                                    {
                                        //This is the top flag on right pen - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagPenRightTop);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    case ParseTypeB:
                                        
                                    {
                                        //This is the bottom flag on right pen - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagPenRightBottom);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    case ParseTypeC:
                                        
                                    {
                                        //This is the central flag on right pen - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagPenRightCenter);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    default:
                                        break;
                                }
                                
                                break;

                                
                            default:
                                break;
                        }
                        
                        break;
                        
                    case ParseTypeG:
                        
                        //Check which goal type
                        ++runner;
                        
                        switch (parseWord(*runner)) {
                            case ParseTypeL:
                                
                                //Check which side
                                ++runner;
                                
                                switch (parseWord(*runner)) {
                                    case ParseTypeT:
                                        
                                    {
                                        //This is the top flag on left goal - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagGoalLeftTop);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    case ParseTypeB:
                                        
                                    {
                                        //This is the bottom flag on left goal - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagGoalLeftBottom);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    default:
                                        break;
                                }
                                
                                break;
                                
                            case ParseTypeR:
                                
                                //Check which side
                                ++runner;
                                
                                switch (parseWord(*runner)) {
                                    case ParseTypeT:
                                        
                                    {
                                        //This is the top flag on right goal - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagGoalRightTop);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    case ParseTypeB:
                                        
                                    {
                                        //This is the bottom flag on right goal - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagGoalRightBottom);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    default:
                                        break;
                                }
                                
                                break;
                                
                            default:
                                break;
                        }
                        
                        break;
                        
                    case ParseTypeT:
                        
                        ++runner;
                        
                        //Find out which kind of Top flag
                        switch (parseWord(*runner)) {
                            case ParseType0:
                                
                            {
                                //This is the top flag - add an object and set it's type
                                Observable *cObservable = new Observable(ObservableTypeFlagTop0);
                                m_vcObservables.push_back(cObservable);
                                break;
                                
                            }
                                
                            case ParseTypeL:
                                
                                //This means that the flag is marking the border
                                ++runner;
                                
                                switch (parseWord(*runner)) {
                                    case ParseType10:
                                        
                                    {
                                        //This is the top non center flag - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagTopLeft10);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    case ParseType20:
                                        
                                    {
                                        //This is the top non center flag - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagTopLeft20);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    case ParseType30:
                                        
                                    {
                                        //This is the top non center flag - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagTopLeft30);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    case ParseType40:
                                        
                                    {
                                        //This is the top non center flag - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagTopLeft40);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    case ParseType50:
                                        
                                    {
                                        //This is the top non center flag - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagTopLeft50);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    default:
                                        break;
                                        
                                }
                                
                                break;
                                
                            case ParseTypeR:
                                
                                //This means that the flag is marking the border
                                ++runner;
                                
                                switch (parseWord(*runner)) {
                                    case ParseType10:
                                        
                                    {
                                        //This is the top non center flag - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagTopRight10);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    case ParseType20:
                                        
                                    {
                                        //This is the top non center flag - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagTopRight20);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    case ParseType30:
                                        
                                    {
                                        //This is the top non center flag - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagTopRight30);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    case ParseType40:
                                        
                                    {
                                        //This is the top non center flag - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagTopRight40);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    case ParseType50:
                                        
                                    {
                                        //This is the top non center flag - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagTopRight50);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    default:
                                        break;
                                        
                                }
                                
                                break;

                                
                            default:
                                break;
                        }
                        
                        break;
                        
                    case ParseTypeB:
                        
                        ++runner;
                        
                        //Find out which kind of Top flag
                        switch (parseWord(*runner)) {
                            case ParseType0:
                                
                            {
                                //This is the bottom flag - add an object and set it's type
                                Observable *cObservable = new Observable(ObservableTypeFlagBottom0);
                                m_vcObservables.push_back(cObservable);
                                break;
                                
                            }
                                
                            case ParseTypeL:
                                
                                //This means that the flag is marking the border
                                ++runner;
                                
                                switch (parseWord(*runner)) {
                                    case ParseType10:
                                        
                                    {
                                        //This is the bottom non center flag - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagBottomLeft10);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    case ParseType20:
                                        
                                    {
                                        //This is the bottom non center flag - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagBottomLeft20);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    case ParseType30:
                                        
                                    {
                                        //This is the bottom non center flag - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagBottomLeft30);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    case ParseType40:
                                        
                                    {
                                        //This is the bottom non center flag - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagBottomLeft40);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    case ParseType50:
                                        
                                    {
                                        //This is the bottom non center flag - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagBottomLeft50);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    default:
                                        break;
                                        
                                }
                                
                                break;
                                
                            case ParseTypeR:
                                
                                //This means that the flag is marking the border
                                ++runner;
                                
                                switch (parseWord(*runner)) {
                                    case ParseType10:
                                        
                                    {
                                        //This is the bottom non center flag - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagBottomRight10);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    case ParseType20:
                                        
                                    {
                                        //This is the bottom non center flag - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagBottomRight20);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    case ParseType30:
                                        
                                    {
                                        //This is the bottom non center flag - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagBottomRight30);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    case ParseType40:
                                        
                                    {
                                        //This is the bottom non center flag - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagBottomRight40);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    case ParseType50:
                                        
                                    {
                                        //This is the bottom non center flag - add an object and set it's type
                                        Observable *cObservable = new Observable(ObservableTypeFlagBottomRight50);
                                        m_vcObservables.push_back(cObservable);
                                        break;
                                        
                                    }
                                        
                                    default:
                                        break;
                                        
                                }
                                
                                break;
                                
                            default:
                                break;
                        }
                        
                        break;
                        
                    case ParseTypeC:
                        
                        //This can be 2 possibilities, either its the central flag or the line bordering flag
                        ++runner;
                        
                        //If there is more input, its a border flag
                        if (runner != end) {
                            
                            switch (parseWord(*runner)) {
                                case ParseTypeT:
                                    
                                {
                                    //This is the central top flag - add an object and set it's type
                                    Observable *cObservable = new Observable(ObservableTypeFlagCenterTop);
                                    m_vcObservables.push_back(cObservable);
                                    break;
                                    
                                }
                                    
                                case ParseTypeB:
                                    
                                {
                                    //This is the central bottom flag - add an object and set it's type
                                    Observable *cObservable = new Observable(ObservableTypeFlagCenterBottom);
                                    m_vcObservables.push_back(cObservable);
                                    break;
                                    
                                }
                                    
                                default:
                                    break;
                                    
                            }
                            
                        }
                        else {
                            
                            //This is the central flag - add an object and set it's type
                            Observable *cObservable = new Observable(ObservableTypeFlagCenter);
                            m_vcObservables.push_back(cObservable);
                            
                        }

                        break;

                    //This means that the flag is left side
                    case ParseTypeL:
                        
                        ++runner;
                        
                        //Find out which kind of Flag
                        switch (parseWord(*runner)) {
                                
                            case ParseType0:
                                
                            {
                                //This is the left most flag - add an object and set it's type
                                Observable *cObservable = new Observable(ObservableTypeFlagLeft0);
                                m_vcObservables.push_back(cObservable);
                                break;
                                
                            }
                                
                            case ParseTypeT:
                                
                                //This can be 2 possibilities, either its the one bordering the pen or the border
                                ++runner;
                                
                                //If there is more input, its a border flag
                                if (runner != end) {
                                    
                                    switch (parseWord(*runner)) {
                                        case ParseType10:
                                            
                                        {
                                            //This is the left top border flag - add an object and set it's type
                                            Observable *cObservable = new Observable(ObservableTypeFlagLeftTop10);
                                            m_vcObservables.push_back(cObservable);
                                            break;
                                            
                                        }
                                            
                                        case ParseType20:
                                            
                                        {
                                            //This is the left top border flag - add an object and set it's type
                                            Observable *cObservable = new Observable(ObservableTypeFlagLeftTop20);
                                            m_vcObservables.push_back(cObservable);
                                            break;
                                            
                                        }
                                            
                                        case ParseType30:
                                            
                                        {
                                            //This is the left top border flag - add an object and set it's type
                                            Observable *cObservable = new Observable(ObservableTypeFlagLeftTop30);
                                            m_vcObservables.push_back(cObservable);
                                            break;
                                            
                                        }
                                            
                                            //Shouldnt reach here
                                        default:
                                            break;
                                            
                                    }
                                    
                                    
                                }
                                else {
                                    
                                    //This is the left top  pen flag - add an object and set it's type
                                    Observable *cObservable = new Observable(ObservableTypeFlagLeftTop);
                                    m_vcObservables.push_back(cObservable);

                                }
                                
                                break;
                                
                            case ParseTypeB:
                                
                                //This can be 2 possibilities, either its the one bordering the pen or the border
                                ++runner;
                                
                                //If there is more input, its a border flag
                                if (runner != end) {
                                    
                                    switch (parseWord(*runner)) {
                                        case ParseType10:
                                            
                                        {
                                            //This is the left bottom border flag - add an object and set it's type
                                            Observable *cObservable = new Observable(ObservableTypeFlagLeftBottom10);
                                            m_vcObservables.push_back(cObservable);
                                            break;
                                            
                                        }
                                            
                                        case ParseType20:
                                            
                                        {
                                            //This is the left bottom border flag - add an object and set it's type
                                            Observable *cObservable = new Observable(ObservableTypeFlagLeftBottom20);
                                            m_vcObservables.push_back(cObservable);
                                            break;
                                            
                                        }
                                            
                                        case ParseType30:
                                            
                                        {
                                            //This is the left bottom border flag - add an object and set it's type
                                            Observable *cObservable = new Observable(ObservableTypeFlagLeftBottom30);
                                            m_vcObservables.push_back(cObservable);
                                            break;
                                            
                                        }
                                            
                                            //Shouldnt reach here
                                        default:
                                            break;
                                            
                                    }
                                    
                                    
                                }
                                else {
                                    
                                    //This is the left bottom pen flag - add an object and set it's type
                                    Observable *cObservable = new Observable(ObservableTypeFlagLeftBottom);
                                    m_vcObservables.push_back(cObservable);
                                    
                                }
   
                                break;
                                
                            default:
                                break;
                        }
                        
                        break;
                        
                        //This means that the flag is left side
                    case ParseTypeR:
                        
                        ++runner;
                        
                        //Find out which kind of Flag
                        switch (parseWord(*runner)) {
                                
                            case ParseType0:
                                
                            {
                                //This is the left most flag - add an object and set it's type
                                Observable *cObservable = new Observable(ObservableTypeFlagRight0);
                                m_vcObservables.push_back(cObservable);
                                break;
                                
                            }
                                
                            case ParseTypeT:
                                
                                //This can be 2 possibilities, either its the one bordering the pen or the border
                                ++runner;
                                
                                //If there is more input, its a border flag
                                if (runner != end) {
                                    
                                    switch (parseWord(*runner)) {
                                        case ParseType10:
                                            
                                        {
                                            //This is the right top border flag - add an object and set it's type
                                            Observable *cObservable = new Observable(ObservableTypeFlagRightTop10);
                                            m_vcObservables.push_back(cObservable);
                                            break;
                                            
                                        }
                                            
                                        case ParseType20:
                                            
                                        {
                                            //This is the right top border flag - add an object and set it's type
                                            Observable *cObservable = new Observable(ObservableTypeFlagRightTop20);
                                            m_vcObservables.push_back(cObservable);
                                            break;
                                            
                                        }
                                            
                                        case ParseType30:
                                            
                                        {
                                            //This is the right top border flag - add an object and set it's type
                                            Observable *cObservable = new Observable(ObservableTypeFlagRightTop30);
                                            m_vcObservables.push_back(cObservable);
                                            break;
                                            
                                        }
                                            
                                            //Shouldnt reach here
                                        default:
                                            break;
                                            
                                    }
                                    
                                }
                                else {
                                    
                                    //This is the right top  pen flag - add an object and set it's type
                                    Observable *cObservable = new Observable(ObservableTypeFlagRightTop);
                                    m_vcObservables.push_back(cObservable);
                                }

                                break;
                                
                            case ParseTypeB:
                                
                                //This can be 2 possibilities, either its the one bordering the pen or the border
                                ++runner;
                                
                                //If there is more input, its a border flag
                                if (runner != end) {
                                    
                                    switch (parseWord(*runner)) {
                                        case ParseType10:
                                            
                                        {
                                            //This is the right top bottom flag - add an object and set it's type
                                            Observable *cObservable = new Observable(ObservableTypeFlagRightBottom10);
                                            m_vcObservables.push_back(cObservable);
                                            break;
                                            
                                        }
                                            
                                        case ParseType20:
                                            
                                        {
                                            //This is the right bottom border flag - add an object and set it's type
                                            Observable *cObservable = new Observable(ObservableTypeFlagRightBottom20);
                                            m_vcObservables.push_back(cObservable);
                                            break;
                                            
                                        }
                                            
                                        case ParseType30:
                                            
                                        {
                                            //This is the right bottom border flag - add an object and set it's type
                                            Observable *cObservable = new Observable(ObservableTypeFlagRightBottom30);
                                            m_vcObservables.push_back(cObservable);
                                            break;
                                            
                                        }
                                            
                                            //Shouldnt reach here
                                        default:
                                            break;
                                            
                                    }
                                    
                                    
                                }
                                else {
                                    
                                    //This is the right top pen flag - add an object and set it's type
                                    Observable *cObservable = new Observable(ObservableTypeFlagRightBottom);
                                    m_vcObservables.push_back(cObservable);
                                    
                                }
                                
                                break;
                                
                            default:
                                break;
                        }
                        
                        break;
                        
                    default:
                        break;
                }
                
                break;
                
                //This means that we have a numerical value (0 only counts inside the direction values)
                default:

                //Since this checks the number values, increment the count to compensate for the type check
                iter += 4;
                uiIndex += 4;
                
                //Make sure that there is data (can happen with no visible items)
                if (!m_vcObservables.empty()) {
                    
                    //This goes a particular order- first the distance
                    Observable *cObservable = m_vcObservables.back();
                    
                    //Check if there is only one input - it means that its the direction
                    string strDirection = *runner;
                    
                    ++runner;
                    //This means that its the direction
                    if (runner == end) {
                        
                        //Change direction and finish
                        cObservable->direction = atof(strDirection.data());
                        cObservable->knownProperties = ObservablePropertyTypeDistance;
                        break;
                        
                    }
                    
                    //This means that we proceed until the end
                    cObservable->distance = atof(strDirection.data());
                    
                    //This is the direction
                    cObservable->direction = atof((*runner).data());
                    cObservable->knownProperties = ObservablePropertyTypeDirection;
                    
                    //Check if there is more data
                    ++runner;
                    
                    if (runner == end) {
                        
                        break;
                        
                    }
                    
                    //This is the DistanceChange
                    cObservable->distanceChange = atof((*runner).data());
                    
                    //This is the DirectionChange
                    ++runner;
                    
                    cObservable->directionChange = atof((*runner).data());
                    cObservable->knownProperties = ObservablePropertyTypeDirectionChange;
                    
                    
                    //Check if more input is found
                    ++runner;
                    
                    if (runner == end) {
                        
                        break;
                        
                    }
                    
                    //This means that its the body facing direction
                    cObservable->bodyFacingDirection = atof((*runner).data());
                    
                    //And this is the head facing direction
                    ++runner;
                    cObservable->headFacingDirection = atof((*runner).data());
                    cObservable->knownProperties = ObservablePropertyTypeHeadFacingDirection;
                    
                }


                break;
                
        }
        
        --iter;
        --uiIndex;
        
    }

}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: SeeState Constructor                                                          *
 * The Input: map<string, ParseType>                                                            *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with input as reference map for types.         *
 * *********************************************************************************************/

SeeState::SeeState(const std::map<std::string, ParseType>& cParseMap) :
State(cParseMap, StateTypeSee) { }

/**********************************************************************************************
 * function name: SeeState Destructor                                                         *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Removes all of the objects contained in the observed vector.        *
 * *******************************************************************************************/

SeeState::~SeeState() {
    
    //Remove all Observed objects from the vector
    for (vector<Observable*>::iterator iter = m_vcObservables.begin() ; iter != m_vcObservables.end() ; iter++) {
        
        //Can only be deleted by the SeeState
        delete *iter;
        
    }
    
}

/************************************************************************************************
 * function name: getObservables                                                                *
 * The Input: none                                                                              *
 * The output: const vector<Observable> (reference)                                             *
 * The Function Opertion: Returns the vector that holds the observed objects.                   *
 * *********************************************************************************************/

const vector<Observable*>& SeeState::getObservables() const {
    
    return m_vcObservables;
    
}

/************************************************************************************
 * function name: operator<<                                                        *
 * The Input: ostream object (reference), const SeeState object (reference)         *
 * The output: ostream object (reference)                                           *
 * The Function Opertion: Prints the object's member variables into the input       *
 *                        ostream object, and returns it afterwards. It iterates    *
 *                        all of the observrable objects contained in the vector    *
 *                        and prints them.                                          *
 * *********************************************************************************/

std::ostream& operator<<(std::ostream &out, const SeeState &cSeeState) {

    unsigned int uiIndex = 0;
    
    for (vector<Observable*>::const_iterator iter = cSeeState.m_vcObservables.begin() ;
         iter != cSeeState.m_vcObservables.end() ;
         iter++, ++uiIndex) {
        
        
        out << uiIndex << ": " << **iter << endl;
        
    }
    
    return out;
    
}

