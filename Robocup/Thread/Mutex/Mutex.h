/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Declaration of Mutex Class             *
 ***********************************************************/

#ifndef __Ex3__Mutex__
#define __Ex3__Mutex__

#include <stdio.h>
#include <pthread.h>

/**********************************************************************************
 * Mutex Class: A lock that can be shared accross threadable classes.             *
 *                Used to synchonize resource accessing.                          *
 *********************************************************************************/

class Mutex {
    
private:
    
    friend class ConditionVariable;
    
    //  ---                         PRIVATE VARIABLES                       ---   //

    //Holds the mutual exclusion type
    pthread_mutex_t m_tMutualExclusion;
    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: Mutex Constructor                                                             *
     * The Input: none                                                                              *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object.                                               *
     * *********************************************************************************************/
    
    Mutex();
    
    /**********************************************************************************************
     * function name: Mutex Destructor                                                            *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    virtual ~Mutex();
    
    /**********************************************************************************************
     * function name: lock                                                                        *
     * The Input: none                                                                            *
     * The output: int                                                                            *
     * The Function Opertion: If unlocked, this will lock the object. If locked,                  *
     *                        this will block the calling thread Returns possible error           *
     *                        as an integer code.                                                 *
     * *******************************************************************************************/
    
    int lock();

    /**********************************************************************************************
     * function name: tryLock                                                                     *
     * The Input: none                                                                            *
     * The output: int                                                                            *
     * The Function Opertion: If already locked, will act as return,                              *
     *                        Returns possible error as an integer code.                          *
     * *******************************************************************************************/
    
    int tryLock();

    /**********************************************************************************************
     * function name: unlock                                                                      *
     * The Input: none                                                                            *
     * The output: int                                                                            *
     * The Function Opertion: Unlocks the previously made lock - the calling thread must own the  *
     *                        lock (must have made the lock to begin with)                        *
     * *******************************************************************************************/
    
    int unlock();
    
};

#endif 
