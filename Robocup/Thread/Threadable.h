/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Declaration of Threadable Class        *
 ***********************************************************/

#ifndef __Ex3__Threadable__
#define __Ex3__Threadable__

#include <stdio.h>
#include <pthread.h>
#include <iostream>

/**********************************************************************************
 * ThreadQueue Class: Handles the thread operations, of creating, closing, exiting*
 *                    joining and detaching a thread. Its an abstract class,      *
 *                    that objects who inherate from this class have to implement *
 *                    the function that runs on a special thread.                 *
 *********************************************************************************/

class Threadable {
    
private:
    
    //  ---                         PRIVATE VARIABLES                       ---   //

    //Holds the Thread type
    pthread_t m_sThreadID;
    
    //Flag if the Thread has been created
    bool m_bIsCreated;
    
    //Flag if the Thread is detached
    bool m_bIsDetached;
    
    //  ---                         PRIVATE FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: executeThreadable                                                             *
     * The Input: void*                                                                             *
     * The output: none                                                                             *
     * The Function Opertion: Performs the execute virtual function as static for use with a thread.*
     * *********************************************************************************************/
    
    static void executeThreadable(void* cThreadable);
    
protected:
    
    //  ---                         PROTECTED FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: waitCompletion                                                                *
     * The Input: Threadable object (reference)                                                     *
     * The output: Threadable object (pointer)                                                      *
     * The Function Opertion: Wait until the argument object finished running and get it's result,  *
     *                        should be used inside execute.                                        *
     * *********************************************************************************************/

    Threadable* waitCompletion(Threadable& cThreadable);

    /************************************************************************************************
     * function name: endExecution                                                                  *
     * The Input: none                                                                              *
     * The output: none                                                                             *
     * The Function Opertion: End the execution with a return value, or just finish executing       *
     *                        to remove the thread - should be used inside execute.                 *
     * *********************************************************************************************/
    
    void endExecution();

    /************************************************************************************************
     * function name: detach                                                                        *
     * The Input: none                                                                              *
     * The output: int                                                                              *
     * The Function Opertion: Detach the current running thread, meaning that after endExecution    *
     *                        it will terminate, returns the error as an int (or                    *
     *                        0 if there was no error).                                             *
     * *********************************************************************************************/
    
    int detach();
    
    /************************************************************************************************
     * function name: initialize                                                                    *
     * The Input: none                                                                              *
     * The output: none                                                                             *
     * The Function Opertion: Initialize the member variables.                                      *
     * *********************************************************************************************/
    
    void initialize();
    
    /************************************************************************************************
     * function name: execute                                                                       *
     * The Input: none                                                                              *
     * The output: none                                                                             *
     * The Function Opertion: This will be default behaviour, the execution of the object.          *
     * *********************************************************************************************/
    
    virtual void execute() = 0;

public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: Threadable Constructor                                                        *
     * The Input: none                                                                              *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object.                                               *
     * *********************************************************************************************/
    
    Threadable();
    
    /**********************************************************************************************
     * function name: Threadable Destructor                                                       *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: closes any existing thread in this object.                          *
     * *******************************************************************************************/
    
    virtual ~Threadable();
   
    /**********************************************************************************************
     * function name: waitCompletion                                                              *
     * The Input: none                                                                            *
     * The output: Threadable object (pointer)                                                    *
     * The Function Opertion: Wait until this Threadable object is finished executing.            *
     * *******************************************************************************************/
    
    Threadable* waitCompletion();
    
    /**********************************************************************************************
     * function name: start                                                                       *
     * The Input: none                                                                            *
     * The output: int                                                                            *
     * The Function Opertion: Create a new thread and start running execute. Returns the result   *
     *                        of starting to execute as error codes (0 if no errors).             *
     * *******************************************************************************************/
    
    int start();
    
    /************************************************************************************
     * function name: operator<<                                                        *
     * The Input: ostream object (reference), const Threadable object (reference)       *
     * The output: ostream object (reference)                                           *
     * The Function Opertion: Prints the object.                                        *
     * *********************************************************************************/
    
    friend std::ostream& operator<<(std::ostream &out, const Threadable& cThreadable);
    
};

#endif
