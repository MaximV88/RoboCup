/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Declaration of ThreadQueue Class       *
 ***********************************************************/

#ifndef __Ex3__ThreadQueue__
#define __Ex3__ThreadQueue__

#include <stdio.h>
#include <queue>
#include <pthread.h>

/**********************************************************************************
 * ThreadQueue Class: A queue that can be shared with different threads.          *
 *********************************************************************************/

template <typename T>
class ThreadQueue {
    
private:
    
    //  ---                         PRIVATE VARIABLES                       ---   //

    //Holds the queue contained in the class
    std::queue<T> m_qQueue;
    
    //Dont use the classes Mutex, ConditionVariable to avoid overhead (there is no need to share them across classes)
    
    //Holds the mutual exclusion type
    pthread_mutex_t m_sMutualExclusion;
    
    //Holds the condition variable type
    pthread_cond_t m_sConditionVariable;
    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: ThreadQueue Constructor                                                       *
     * The Input: none                                                                              *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object.                                               *
     * *********************************************************************************************/
    
    ThreadQueue();
    
    /**********************************************************************************************
     * function name: ThreadQueue Destructor                                                      *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~ThreadQueue();
    
    /**********************************************************************************************
     * function name: push                                                                        *
     * The Input: Type object                                                                     *
     * The output: none                                                                           *
     * The Function Opertion: Pushes the input into the queue.                                    *
     * *******************************************************************************************/
    
    void push(T tObject);
    
    /**********************************************************************************************
     * function name: pop                                                                         *
     * The Input: none                                                                            *
     * The output: Type object                                                                    *
     * The Function Opertion: Pops the first object from the queue and returns it.                *
     * *******************************************************************************************/
    
    T pop();
    
    /**********************************************************************************************
     * function name: size                                                                        *
     * The Input: none                                                                            *
     * The output: size_t                                                                         *
     * The Function Opertion: Returns the number of objects that are in the queue.                *
     * *******************************************************************************************/
    
    size_t size();
    
    /**********************************************************************************************
     * function name: empty                                                                       *
     * The Input: none                                                                            *
     * The output: bool                                                                           *
     * The Function Opertion: Returns true if the queue is empty, false otherwise.                *
     * *******************************************************************************************/
    
    bool empty();

};

#include "ThreadQueue.cpp"

#endif 
