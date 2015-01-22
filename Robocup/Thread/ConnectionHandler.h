/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Declaration of ConnectionHandler Class *
 ***********************************************************/

#ifndef __Ex3__ConnectionHandler__
#define __Ex3__ConnectionHandler__

#include <stdio.h>
#include "Threadable.h"
#include "ThreadQueue.h"
#include "Connection.h"
#include "Instruction.h"
#include "BodyState.h"
#include "State.h"
#include "Parser.h"

#define DEBUG_SHOW_OUTGOING_MESSAGES 0

/*******************************************************************************
 * ConnectionHandler Class: Handles incoming and outgoing information.         *
 *                          Sends instructions to server and incoming          *
 *                          information to the server (using queues).          *
 ******************************************************************************/

class ConnectionHandler : public Threadable {
    
private:
    
    //  ---                         PRIVATE VARIABLES                       ---   //

    //Holds the strings recieved from the server
    ThreadQueue<std::string*>& m_qInstructionQueue;
    
    //Holds the errors recieved from the Parser
    ThreadQueue<parse::ErrorType> m_qErrorQueue;
    
    //The parser that converts the strings to States
    parse::Parser m_cParser;
    
    //This will hold the connection to the server
    const Connection* m_cConnection;
    
    //This will be the buffer to hold the c strings recieved from the server
    char m_chBuffer[4096];
    
    //  ---                         PRIVATE FUNCTIONS                       ---   //

    
    /****************************************************************************************************
     * function name: execute                                                                           *
     * The Input: none                                                                                  *
     * The output: none                                                                                 *
     * The Function Opertion: Executes the operations required from this class (it's the 'main' thread  *
     *                        of this object), in a loop.                                               *
     * *************************************************************************************************/
    
    virtual void execute();
    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: ConnectionHandler Constructor                                                 *
     * The Input: const Connection object (reference), ThreadQueue<string*> object (reference),     *
     *            ThreadQueue<State> object (reference)                                             *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input queues.                             *
     * *********************************************************************************************/
    
    ConnectionHandler(const Connection& cConnection,
                      ThreadQueue<std::string*>& qInstructionQueue,
                      ThreadQueue<State*>& qStateQueue);
    
    /**********************************************************************************************
     * function name: ConnectionHandler Destructor                                                *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~ConnectionHandler();
    
    /**********************************************************************************************
     * function name: enlistRobocup                                                               *
     * The Input: const char (pointer)                                                            *
     * The output: none                                                                           *
     * The Function Opertion: This enlists the player to the Robocup server.                      *
     * *******************************************************************************************/
    
    bool enlistRobocup(const char* chTeamName);
    
};

#endif  
