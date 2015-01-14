/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Declaration of ConditionVariable Class *
 ***********************************************************/

#ifndef __Ex3__ConditionVariable__
#define __Ex3__ConditionVariable__

#include <stdio.h>
#include "Mutex.h"

/********************************************************************************************
 * ConditionVariable Class: A ConditionVaraible that can be shared accross Threadables.     *
 *                          Used for waiting for a condition to be true                     *
 *******************************************************************************************/

class ConditionVariable {

private:
    
    //  ---                         PRIVATE VARIABLES                       ---   //

    //Holds the condition variable type
    pthread_cond_t m_sConditionVariable;
    
    //Holds the mutual exclusion type
    pthread_mutex_t& m_sMutualExclusion;
    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: ConditionVariable Constructor                                                 *
     * The Input: Mutex object (reference)                                                          *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input mutex as it's lock.                 *
     * *********************************************************************************************/
    
    ConditionVariable(Mutex& cMutex);
    
    /**********************************************************************************************
     * function name: ConditionVariable Destructor                                                *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    virtual ~ConditionVariable();
    
    /**********************************************************************************************
     * function name: wait                                                                        *
     * The Input: none                                                                            *
     * The output: int                                                                            *
     * The Function Opertion: Block a thread - the mutex has to be locked. Returns possible error *
     *                        as an integer code.                                                 *
     * *******************************************************************************************/
    
    int wait();
    
    /**********************************************************************************************
     * function name: signal                                                                      *
     * The Input: none                                                                            *
     * The output: int                                                                            *
     * The Function Opertion: Unblock at least one thread that is blocked by this object,         *
     *                        and locks the mutex back. Returns possible error as an integer code.*
     * *******************************************************************************************/
    
    int signal();
    
    /**********************************************************************************************
     * function name: signal                                                                      *
     * The Input: none                                                                            *
     * The output: int                                                                            *
     * The Function Opertion: Unblock all threads currently blocked by this object,               *
     *                        and locks the mutex back. Returns possible error as an integer code.*
     * *******************************************************************************************/
    
    int broadcast();
    
};

#endif
