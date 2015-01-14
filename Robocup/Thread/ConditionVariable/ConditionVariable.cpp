/****************************************************************
 * Student Name:     Maxim Vainshtein                           *
 * Exercise Name:    Ex3                                    *
 * File description: Implementation of ConditionVariable Class  *
 ***************************************************************/

#include "ConditionVariable.h"

#define CONDITION_VARIABLE_WAIT_ERROR "ConditionVariable wait error"
#define CONDITION_VARIABLE_SIGNAL_ERROR "ConditionVariable signal error"
#define CONDITION_VARIABLE_BROADCAST_ERROR "ConditionVariable broadcast error"

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: ConditionVariable Constructor                                                 *
 * The Input: Mutex object (reference)                                                          *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with input mutex as it's lock, and initializes *
 *                        the condition variable.                                               *
 * *********************************************************************************************/

ConditionVariable::ConditionVariable(Mutex &cMutex) : m_sMutualExclusion(cMutex.m_tMutualExclusion) {
    
    //Initialize the member variable
    pthread_cond_init(&m_sConditionVariable, NULL);
    
}

/**********************************************************************************************
 * function name: ConditionVariable Destructor                                                *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Destroys the condition variable.                                    *
 * *******************************************************************************************/

ConditionVariable::~ConditionVariable() {
    
    pthread_cond_destroy(&m_sConditionVariable);
    
}

/**********************************************************************************************
 * function name: wait                                                                        *
 * The Input: none                                                                            *
 * The output: int                                                                            *
 * The Function Opertion: Calls for the cond_wait c function with input member variables,     *
 *                        prints an error if occured, and returns the result.                 *
 * *******************************************************************************************/

int ConditionVariable::wait() {
    
    //Unlocks the mutex and waits for a signal - the mutex must be locked before calling
    int iWaitError = pthread_cond_wait(&m_sConditionVariable, &m_sMutualExclusion);
    
    //Print error if exists
    if (iWaitError != 0)
        perror(CONDITION_VARIABLE_WAIT_ERROR);
    
    return iWaitError;
    
}

/**********************************************************************************************
 * function name: signal                                                                      *
 * The Input: none                                                                            *
 * The output: int                                                                            *
 * The Function Opertion: Calls for the cond_singnal c function with input member variables,  *
 *                        prints an error if occured, and returns the result.                 *
 * *******************************************************************************************/

int ConditionVariable::signal() {
    
    //Unblocks one thread that is waiting
    int iSignalError = pthread_cond_signal(&m_sConditionVariable);
    
    //Print error if exists
    if (iSignalError != 0)
        perror(CONDITION_VARIABLE_SIGNAL_ERROR);
    
    return iSignalError;
    
}

/**********************************************************************************************
 * function name: broadcast                                                                   *
 * The Input: none                                                                            *
 * The output: int                                                                            *
 * The Function Opertion: Calls for the cond_broadcast c function with input member variables,*
 *                        prints an error if occured, and returns the result.                 *
 * *******************************************************************************************/

int ConditionVariable::broadcast() {
    
    //Unblocks all threads that are waiting
    int iBroadcastError = pthread_cond_broadcast(&m_sConditionVariable);
    
    //Print error if exists
    if (iBroadcastError != 0)
        perror(CONDITION_VARIABLE_BROADCAST_ERROR);
    
    return iBroadcastError;
    
}
