/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex2                                    *
 * File description: Declaration of Server Class            *
 ***********************************************************/

#ifndef __Ex2__Server__
#define __Ex2__Server__

#include <stdio.h>
#include <netinet/in.h>
#include "Connection.h"
#include "Communicator.h"

/****************************************************************************************
 * Server Class: Represents a Server. It has the ability to accept incoming connections,*
 *               and repsond to those connections                                       *
 *               (that are represented by connection class)                             *
 ***************************************************************************************/

class Server : public Communicator {
    

protected:
    
    //  ---                         PRIVATE VARIABLES                       ---   //

    
    //Stores the listening state of the server
    bool m_bIsListening;


public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: Server Constructor                                                            *
     * The Input: const string (reference), int                                                     *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the Server with input as port and IP address.             *
     * *********************************************************************************************/
    
    Server(const std::string& strAddress, uint16_t usPort);

    /**********************************************************************************************
     * function name: Server Destructor                                                           *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/

    virtual ~Server();
    
    /**********************************************************************************************
     * function name: createServer                                                                *
     * The Input: ProtocolType (enum), uint16_t, const string object (reference)                  *
     * The output: Server object (pointer)                                                        *
     * The Function Opertion: Returns a Server object that is set with the input protocol,        *
     *                        port and address (as source of connection).                         *
     * *******************************************************************************************/
    
    static Server* createServer(ProtocolType eType, uint16_t usPort, const std::string& strAddress = "");

    /**********************************************************************************************
     * function name: start                                                                       *
     * The Input: none                                                                            *
     * The output: int                                                                            *
     * The Function Opertion: Sets the created server to listen for incoming transmissions.       *
     *                        Returns 0 if there was no error, or values smaller than 0 for error.*
     * *******************************************************************************************/
    
    virtual int start() = 0;

    
};

#endif 
