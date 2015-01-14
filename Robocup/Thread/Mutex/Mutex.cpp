/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Implementation of Mutex Class          *
 ***********************************************************/


#include "Mutex.h"

#define MUTEX_LOCK_ERROR "Mutex lock error"
#define MUTEX_TRYLOCK_ERROR "Mutex tryLock error"
#define MUTEX_UNLOCK_ERROR "Mutex unlock error"

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: Mutex Constructor                                                             *
 * The Input: none                                                                              *
 * The output: none                                                                             *
 * The Function Opertion: Initializes member variable mutex.                                    *
 * *********************************************************************************************/

Mutex::Mutex() {
    
    //Just initalize the member variable
    pthread_mutex_init(&m_tMutualExclusion, NULL);
    
}

/**********************************************************************************************
 * function name: Mutex Destructor                                                            *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Destroys the member variable mutex.                                 *
 * *******************************************************************************************/

Mutex::~Mutex() {
    
    //Destroy the member variable
    pthread_mutex_destroy(&m_tMutualExclusion);
    
}

/**********************************************************************************************
 * function name: lock                                                                        *
 * The Input: none                                                                            *
 * The output: int                                                                            *
 * The Function Opertion: Calls for the mutex_lock c function with input member variables,    *
 *                        prints an error if occured, and returns the result.                 *
 * *******************************************************************************************/

int Mutex::lock() {
    
    //Lock the thread
    int iLockError = pthread_mutex_lock(&m_tMutualExclusion);
    
    //Print error if exists
    if (iLockError != 0)
        perror(MUTEX_LOCK_ERROR);
    
    return iLockError;
    
}

/**********************************************************************************************
 * function name: tryLock                                                                     *
 * The Input: none                                                                            *
 * The output: int                                                                            *
 * The Function Opertion: Calls for the mutex_trylock c function with input member variables, *
 *                        prints an error if occured, and returns the result.                 *
 * *******************************************************************************************/

int Mutex::tryLock() {
    
    //Lock the thread without waiting- will return error if already locked
    int iTryLockError = pthread_mutex_trylock(&m_tMutualExclusion);
    
    //Print error if exists
    if (iTryLockError != 0)
        perror(MUTEX_TRYLOCK_ERROR);
    
    return iTryLockError;
    
}

/**********************************************************************************************
 * function name: unlock                                                                      *
 * The Input: none                                                                            *
 * The output: int                                                                            *
 * The Function Opertion: Calls for the mutex_unlock c function with input member variables,  *
 *                        prints an error if occured, and returns the result.                 *
 * *******************************************************************************************/

int Mutex::unlock() {
    
    //Unlocks the thread
    int iUnlockError = pthread_mutex_unlock(&m_tMutualExclusion);
    
    //Print error if exists
    if (iUnlockError != 0)
        perror(MUTEX_UNLOCK_ERROR);
    
    return iUnlockError;
    
}
