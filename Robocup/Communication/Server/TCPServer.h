/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex2                                    *
 * File description: Declaration of Communicator Class      *
 ***********************************************************/

#ifndef __Ex2__TCPServer__
#define __Ex2__TCPServer__

#include <stdio.h>
#include "Server.h"

/********************************************************************************************
 * TCPServer Class: Represents a Server. It has the ability to accept incoming connections, *
 *               and repsond to those connections (that are represented by                  *
 *               connection class). Uses the TCP protocol.                                  *
 *******************************************************************************************/

class TCPServer : public Server {
    
private:
    
    friend class Server;
    
    //  ---                         PRIVATE FUNCTIONS                       ---   //


    /************************************************************************************************
     * function name: TCPServer Constructor                                                         *
     * The Input: const string (reference), int                                                     *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the Server with input as port and IP address.             *
     * *********************************************************************************************/
    
    TCPServer(const std::string& strAddress, uint16_t usPort);
    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //

    /**********************************************************************************************
     * function name: TCPServer Destructor                                                        *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~TCPServer();
    
    /**********************************************************************************************
     * function name: start                                                                       *
     * The Input: none                                                                            *
     * The output: int                                                                            *
     * The Function Opertion: Sets the created server to listen for incoming transmissions.       *
     *                        Returns 0 if there was no error, or values smaller than 0 for error.*
     * *******************************************************************************************/
    
    virtual int start();
    
    /**********************************************************************************************
     * function name: connection                                                                  *
     * The Input: none                                                                            *
     * The output: const Connection object (pointer)                                              *
     * The Function Opertion: Returns a connection object that is a link between this server and  *
     *                        it's client.                                                        *
     * *******************************************************************************************/
    
    virtual const Connection* connection() const;
};

#endif 
