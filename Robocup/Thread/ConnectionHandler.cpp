/****************************************************************
 * Student Name:     Maxim Vainshtein                           *
 * Exercise Name:    Ex3                                        *
 * File description: Implementation of ConnectionHandler Class  *
 ***************************************************************/

#include <iostream>
#include "ConnectionHandler.h"
#include "Parser.h"

#define ERROR_MESSAGE_ENLIST_NO_MORE_PLAYERS_OR_GOALIE "Enlistment error: No more room for players or goalie."
#define ERROR_MESSAGE_SHUTTING_DOWN "Invalid enlistment. Shutting down."

#define ENLIST_MESSAGE_INITIALISATION "init"
#define ENLIST_MESSAGE_ROBOCUP_VERSION "(version 15)"

//  ---                         PRIVATE FUNCTIONS                       ---   //


/****************************************************************************************************
 * function name: execute                                                                           *
 * The Input: none                                                                                  *
 * The output: none                                                                                 *
 * The Function Opertion: Recieves a message from the server, sends it for parsing, checks for      *
 *                        errors recieved from parser and transmits messages from the instructions  *
 *                        given from the Player class.                                              *
 * *************************************************************************************************/

void ConnectionHandler::execute() {
        
    //Do it as long as the object lives
    while (true) {
        
        
        //-------RECIEVE--------//
        
        
        //First recieve from the server, and then send based on the field state
        m_cConnection->recieve(&m_chBuffer, sizeof(m_chBuffer));
        
        //Send the input for parsing if its legal
        m_cParser.parse(m_chBuffer);
        
        //-------HANDLE ERRORS--------//
        
        
        //There was an error, handle it
        if (!m_qErrorQueue.empty()) {
            
                //This needs to be implemented... depends on implementation if to wait (join) the parser.
            
        }
        
        //-------TRANSMIT--------//

        
        //Valid to continue only when there are no errors
        if (!m_qInstructionQueue.empty()) {

            //Take what was given - this will hold the thread as long as nessecery
            std::string* strToTransmit = m_qInstructionQueue.pop();
            
            if (strToTransmit != NULL) {
                
#if DEBUG_SHOW_OUTGOING_MESSAGES
      
                std::cout << *strToTransmit << std::endl;
                
#endif
                
                //Add another for ending character '\0' - this is not a threaded function so deletion is afterwards
                m_cConnection->transmit(strToTransmit->c_str(), (strToTransmit->length() + 1) * sizeof(char));
                
                //Delete the instruction
                delete strToTransmit;
                
            }
            
        }
        
    }
    
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: ConnectionHandler Constructor                                                 *
 * The Input: const Connection object (reference), ThreadQueue<string*> object (reference),     *
 *            ThreadQueue<State> object (reference)                                             *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with input queues.                             *
 * *********************************************************************************************/

ConnectionHandler::ConnectionHandler(const Connection& cConnection,
                                     ThreadQueue<std::string*>& qInstructionQueue,
                                     ThreadQueue<State*>& qStateQueue) :

m_qInstructionQueue(qInstructionQueue), m_cConnection(&cConnection), m_cParser(qStateQueue, m_qErrorQueue) {
    
}

/**********************************************************************************************
 * function name: ConnectionHandler Destructor                                                *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Deletes the input Connection object.                                *
 * *******************************************************************************************/

ConnectionHandler::~ConnectionHandler() {
    
    //No longer needs the connection
    delete m_cConnection;
    
}

/**********************************************************************************************
 * function name: enlistRobocup                                                               *
 * The Input: const char (pointer)                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Builds an instruction to enlist, transmits that instruction.        *
 *                        If successful, parses the incoming ServerState and TeamState.       *
 * *******************************************************************************************/

bool ConnectionHandler::enlistRobocup(const char* chTeamName) {
    
    //Create the enlist message
    Instruction cEnlistInstruction;
    
    //Add initialisation command
    cEnlistInstruction.addCommand(ENLIST_MESSAGE_INITIALISATION);
    
    //Followed by the team name
    cEnlistInstruction.addCommand(chTeamName);
    
    //Followed by the server version
    cEnlistInstruction.addCommand(ENLIST_MESSAGE_ROBOCUP_VERSION);
    
    std::string strToTransmit = cEnlistInstruction.getInstruction();
    
    //Enlist to the server
    m_cConnection->transmit(strToTransmit.c_str(), sizeof(char) * (strToTransmit.length() + 1));
    
    //Recieve the response
    m_cConnection->recieve(&m_chBuffer, sizeof(m_chBuffer));
    
    //Show if parsing to input is ok
    switch (m_cParser.validate(m_chBuffer)) {
            
        case parse::ErrorTypeErrorNoMorePlayerOrGoalieorIllegalClientVersion:
        case parse::ErrorTypeErrorNoMoreTeamOrPlayerOrGoalie:
            
            //Cant list more players or goalie, this is a fatal error.
            std::cerr << ERROR_MESSAGE_ENLIST_NO_MORE_PLAYERS_OR_GOALIE << std::endl;
            std::cerr << ERROR_MESSAGE_SHUTTING_DOWN << std::endl;
            return false;
            //No other possibilities for errors from server (at initialisation), so its valid
        default: break;
    }
    
    //Parse the incoming ServerState message
    m_cParser.parse(m_chBuffer);
    
    //Recieve the TeamState (player params) message
    m_cConnection->recieve(&m_chBuffer, sizeof(m_chBuffer));
    
    //Parse the TeamState message
    m_cParser.parse(m_chBuffer);
    
    return true;
    
}

