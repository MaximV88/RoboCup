/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex2                                    *
 * File description: Declaration of UDPServer Class         *
 ***********************************************************/

#ifndef __Ex2__UDPServer__
#define __Ex2__UDPServer__

#include <stdio.h>
#include "Server.h"

/********************************************************************************************
 * UDPServer Class: Represents a Server. It has the ability to accept incoming connections, *
 *               and repsond to those connections (that are represented by                  *
 *               connection class). Uses the UDP protocol.                                  *
 *******************************************************************************************/

class UDPServer : public Server {
    
private:
    
    friend class Server;
    
    //  ---                         PRIVATE FUNCTIONS                       ---   //


    /************************************************************************************************
     * function name: UDPServer Constructor                                                         *
     * The Input: const string (reference), int                                                     *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the Server with input as port and IP address.             *
     * *********************************************************************************************/
    
    UDPServer(const std::string& strAddress, uint16_t usPort);
    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /**********************************************************************************************
     * function name: TCPServer Destructor                                                        *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~UDPServer();
    
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
     * The Function Opertion: Returns a connection object that is a link to this server           *
     * *******************************************************************************************/
    
    virtual const Connection* connection() const;
};

#endif
