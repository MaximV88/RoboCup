/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Implementation of Threadable Class     *
 ***********************************************************/

#include "Threadable.h"

#define THREADABLE_START_ERROR "Threadable start error"
#define THREADABLE_DETACH_ERROR "Threadable detach error"
#define THREADABLE_WAITCOMPLETION_ERROR "Threadable waitCompletion error"
#define THREADABLE_WAITCOMPLETION_START_ERROR "Threadable waitCompletion error: Must performs on started Threadable objects."

//  ---                         PRIVATE FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: executeThreadable                                                             *
 * The Input: void*                                                                             *
 * The output: none                                                                             *
 * The Function Opertion: Calls for the execution of the inherited execute function. The        *
 *                        called execute gets called inside a thread, thus executed inside a    *
 *                        thread.                                                               *
 * *********************************************************************************************/

void Threadable::executeThreadable(void* cThreadable) {
    
    //Run the inherited virtual function
    static_cast<Threadable*>(cThreadable)->execute();
    
}

//  ---                         PROTECTED FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: waitCompletion                                                                *
 * The Input: Threadable object (reference)                                                     *
 * The output: Threadable object (pointer)                                                      *
 * The Function Opertion: Checks if both objects have a thread. If so the called on object      *
 *                        waits until the completion of the argument object (using join),       *
 *                        and then returns the result. if one of the objects has not been       *
 *                        with a created thread, it will print an error and return NULL.        *
 * *********************************************************************************************/

Threadable* Threadable::waitCompletion(Threadable& cThreadable) {
    
    //Can only join threads if they are created
    if (m_bIsCreated && cThreadable.m_bIsCreated) {
        
        void* vResultObject = NULL;
        
        //Get the result into an object
        int iJoinError = pthread_join(cThreadable.m_sThreadID, &vResultObject);
        
        //That object is ensured to be a Threadable object
        Threadable* cResultObject = static_cast<Threadable*>(vResultObject);
        
        if (iJoinError != 0) {
            
            //Print that an error has occured
            perror(THREADABLE_WAITCOMPLETION_ERROR);
        }
        else {
            
            //Should detach (end after exit) once finished completion
            m_bIsDetached = true;
            
        }
        
        //Return the given object that we waited for
        return cResultObject;
        
    }
    else
        std::cerr << THREADABLE_WAITCOMPLETION_START_ERROR << std::endl;
    
    //If not running, dont return anything
    return NULL;
    
}

/************************************************************************************************
 * function name: endExecution                                                                  *
 * The Input: none                                                                              *
 * The output: none                                                                             *
 * The Function Opertion: Detaches the thread, changes the active thread flag and returns the   *
 *                        object using the pthread_exit c function.                             *
 * *********************************************************************************************/

void Threadable::endExecution() {
    
    //This will no longer be running
    m_bIsCreated = false;
    
    //If the thread has not yet been detached, detach it
    if (!m_bIsDetached) {
        
        //Detach the running thread
        pthread_detach(m_sThreadID);
        
    }
    
    //This will return the value to waitCompletion for joined to thread, if there is one
    pthread_exit(this);
    
}

/************************************************************************************************
 * function name: detach                                                                        *
 * The Input: none                                                                              *
 * The output: int                                                                              *
 * The Function Opertion: Checks if the thread is already detached (and active). if so returns  *
 *                        0, otherwise detaches the thread and check if there was an error.     *
 *                        if so it prints it and returns, otherwise changes the detach flag and *
 *                        returns the reuslt.                                                   *
 * *********************************************************************************************/

int Threadable::detach() {
    
    //If the thread has been created and hasnt been marked for detachment earlier (by being joined with another thread)
    if (m_bIsCreated && !m_bIsDetached) {
        
        int iDetachError = pthread_detach(m_sThreadID);
        
        if (iDetachError != 0) {
            
            //Print possible error
            perror(THREADABLE_DETACH_ERROR);
            
        }
        else {
            
            //Marked as detached and shouldnt be detached again by the destructor
            m_bIsDetached = true;
            
        }
        
        return iDetachError;
        
    }
    
    //It was not possible to detach, but not due to error
    return 0;
    
}

/************************************************************************************************
 * function name: initialize                                                                    *
 * The Input: none                                                                              *
 * The output: none                                                                             *
 * The Function Opertion: Initialize the member variables to default values.                    *
 * *********************************************************************************************/

void Threadable::initialize() {
    
    //This will mark if the thread should be detached in the destructor
    m_bIsDetached = false;
    
    //Threads dont create until required to so by this object
    m_bIsCreated = false;
    
    /*
     * Create thread only when required to (since it may return an error,
     * it it wiser to give an option to handle an error later on.
     */
    
    m_sThreadID = 0;
    
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: Threadable Constructor                                                        *
 * The Input: none                                                                              *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the member variables using the initialize function.       *
 * *********************************************************************************************/

Threadable::Threadable() {
    
    //Initialize the member variables
    initialize();
    
}

/**********************************************************************************************
 * function name: Threadable Destructor                                                       *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Detaches the thread if not detached yet, and then cancels it.       *
 * *******************************************************************************************/

Threadable::~Threadable() {
    
    //If the thread is not detached yet, detach it
    if (!m_bIsDetached && m_bIsCreated) {
        
        //Detach the running thread
        pthread_detach(m_sThreadID);
        
    }
    
    //After the thread has been potentialy detached, close it
    if (m_bIsCreated) {
        
        //Close the thread
        pthread_cancel(m_sThreadID);
        
    }
    
}

/**********************************************************************************************
 * function name: waitCompletion                                                              *
 * The Input: none                                                                            *
 * The output: Threadable object (pointer)                                                    *
 * The Function Opertion: This will just wait until the execution is completed,               *
 *                        It calls the waitCompletion function with itself as the argument.   *
 * *******************************************************************************************/

Threadable* Threadable::waitCompletion() {
    
    //If no argument is provided, then we wait for ourselfs
    return waitCompletion(*this);
    
}

/**********************************************************************************************
 * function name: start                                                                       *
 * The Input: none                                                                            *
 * The output: int                                                                            *
 * The Function Opertion: Creates a new thread, if recieved errors prints them and returns,   *
 *                        otherwise changes the active thread flag to true and returns.       *
 * *******************************************************************************************/

int Threadable::start() {
    
    //Create a thread if one doesnt exist yet
    int iCreateError = pthread_create(&m_sThreadID, NULL, (void* (*)(void*))&executeThreadable, this);
    
    if (iCreateError != 0) {
        
        //Print error if one exists
        perror(THREADABLE_START_ERROR);
        
    }
    else {
        
        //Mark the thread as created
        m_bIsCreated = true;
        
    }
    
    //Return the result
    return iCreateError;
    
}

/************************************************************************************
 * function name: operator<<                                                        *
 * The Input: ostream object (reference), const SeeState object (reference)         *
 * The output: ostream object (reference)                                           *
 * The Function Opertion: Prints the object's member variable into the input        *
 *                        ostream object, and returns it afterwards.                *
 * *********************************************************************************/

std::ostream& operator<<(std::ostream &out, const Threadable& cThreadable) {
    
    out << "(ThreadID: " << cThreadable.m_sThreadID << ")";
    return out;
    
}
