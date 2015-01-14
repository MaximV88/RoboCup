/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Implementation of ThreadQueue Class    *
 ***********************************************************/

#ifndef __Ex3__ThreadQueueCPP__
#define __Ex3__ThreadQueueCPP__

#include "ThreadQueue.h"

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: ThreadQueue Constructor                                                       *
 * The Input: none                                                                              *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object's member variables.                            *
 * *********************************************************************************************/

template<typename T>
ThreadQueue<T>::ThreadQueue() {
    
    //Initialize the mutual exlusion and the condition variable
    pthread_mutex_init(&m_sMutualExclusion, NULL);
    pthread_cond_init(&m_sConditionVariable, NULL);
    
}

/**********************************************************************************************
 * function name: ThreadQueue Destructor                                                      *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Destroys the object's member variables.                             *
 * *******************************************************************************************/

template<typename T>
ThreadQueue<T>::~ThreadQueue() {
    
    pthread_mutex_destroy(&m_sMutualExclusion);
    pthread_cond_destroy(&m_sConditionVariable);
    
}

/**********************************************************************************************
 * function name: push                                                                        *
 * The Input: Type object                                                                     *
 * The output: none                                                                           *
 * The Function Opertion: Locks the mutex, pushes an object, unlocks and returns.             *
 * *******************************************************************************************/

template<typename T>
void ThreadQueue<T>::push(T tObject) {

    //First need to lock access to the push_back or any other function to prevent simultanious data change
    pthread_mutex_lock(&m_sMutualExclusion);
    
    //Perform the required action
    m_qQueue.push(tObject);
    
    //Send a message to the waiting functions to continue (mainly pop_front)
    pthread_cond_signal(&m_sConditionVariable);
    
    //Unlock the queue resource
    pthread_mutex_unlock(&m_sMutualExclusion);
    
}

/**********************************************************************************************
 * function name: pop                                                                         *
 * The Input: none                                                                            *
 * The output: Type object                                                                    *
 * The Function Opertion: This requires to pop an object from the queue while others may      *
 *                        change from another thread, Thus the function will stall until such *
 *                        object can be returned, because the time in which an object was     *
 *                        requested from the queue may not be determenistic about returning   *
 *                        a "false" answer that the work has finished - thus removing         *
 *                        threads may wait until they have work!                              *
 *                        The function locks the mutex, and if the queue is empty is waits    *
 *                        using the condition variable. once awake, it pops the first object  *
 *                        and unlocks the locks, and returns the object.                      *
 * *******************************************************************************************/

template<typename T>
T ThreadQueue<T>::pop() {
    
    //First need to lock access to the pop_front or any other function to prevent simultanious data change
    pthread_mutex_lock(&m_sMutualExclusion);
    
    /*
     * Since broadcast can occure from anywhere,
     * the condition variable might continue while an object has
     * not yet been added. Thus dont continue until an object has been added.
     */
    
    while (m_qQueue.empty()) {
        
        //Wait until given signal to continue from elsewhere - release the mutex so that other functions can continue
        pthread_cond_wait(&m_sConditionVariable, &m_sMutualExclusion);
        
    }
    
    //Once continued - with the lock regained after signaled to continue - pop and return
    T tObject = m_qQueue.front();
    m_qQueue.pop();
    
    //Unlock the mutex
    pthread_mutex_unlock(&m_sMutualExclusion);
    
    return tObject;
    
}

/**********************************************************************************************
 * function name: size                                                                        *
 * The Input: none                                                                            *
 * The output: size_t                                                                         *
 * The Function Opertion: Locks the mutex, queries the queue and unlocks the mutex, and       *
 *                        returns the size.                                                   *
 * *******************************************************************************************/

template<typename T>
size_t ThreadQueue<T>::size() {
    
    //Lock the object to prevent simultanious changes that make the returned data incorrect
    pthread_mutex_lock(&m_sMutualExclusion);

    //Get the data
    size_t iQueueSize = m_qQueue.size();
    
    //Unlock to allow other threads to continue
    pthread_mutex_unlock(&m_sMutualExclusion);

    //Return the data
    return iQueueSize;
}

/**********************************************************************************************
 * function name: empty                                                                       *
 * The Input: none                                                                            *
 * The output: bool                                                                           *
 * The Function Opertion: Locks the mutex, queries the queue and unlocks the mutex, and       *
 *                        returns the result.                                                 *
 *********************************************************************************************/

template<typename T>
bool ThreadQueue<T>::empty() {
    
    //Lock the object to prevent simultanious changes that make the returned data incorrect
    pthread_mutex_lock(&m_sMutualExclusion);
    
    //Get the data
    bool bIsEmpty = m_qQueue.empty();
    
    //Unlock to allow other threads to continue
    pthread_mutex_unlock(&m_sMutualExclusion);
    
    //Return the data
    return bIsEmpty;
}

#endif
