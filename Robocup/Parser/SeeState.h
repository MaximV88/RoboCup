/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Declaration of SeeState Class          *
 ***********************************************************/

#ifndef __Ex3__SeeState__
#define __Ex3__SeeState__

#include <stdio.h>
#include "State.h"
#include "Observable.h"

/*******************************************************************************
 * SeeState Class: Represents the Visual input recieved from the server,       *
 *                 the (see ...) command.                                      *
 ******************************************************************************/

class SeeState : public State {
    
private:
    
    //  ---                         PRIVATE VARIABLES                       ---   //

    //Stores the obsereved objects.
    std::vector<Observable*> m_vcObservables;
    
    
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
    
    //  ---                         PUBLIC VARIABLES                       ---   //

    //The time stamp
    int time;
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //

    
    /************************************************************************************************
     * function name: SeeState Constructor                                                          *
     * The Input: map<string, ParseType>                                                            *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input as reference map for types.         *
     * *********************************************************************************************/
    
    SeeState(const std::map<std::string, parse::ParseType>& cParseMap);
    
    SeeState(const SeeState& cSeeState);
    
    /**********************************************************************************************
     * function name: SeeState Destructor                                                         *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~SeeState();
    
    /************************************************************************************************
     * function name: getObservables                                                                *
     * The Input: none                                                                              *
     * The output: const vector<Observable> (reference)                                             *
     * The Function Opertion: Returns the vector that holds the observed objects.                   *
     * *********************************************************************************************/
    
    const std::vector<Observable*>& getObservables() const;
    
    /************************************************************************************
     * function name: operator<<                                                        *
     * The Input: ostream object (reference), const SeeState object (reference)         *
     * The output: ostream object (reference)                                           *
     * The Function Opertion: Prints the object.                                        *
     * *********************************************************************************/
    
    friend std::ostream& operator<<(std::ostream &out, const SeeState &cSeeState);
    
};

#endif 
