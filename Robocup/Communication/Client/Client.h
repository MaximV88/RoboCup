/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex2                                    *
 * File description: Declaration of Client Class            *
 ***********************************************************/

#ifndef __Ex2__Client__
#define __Ex2__Client__

#include <stdio.h>
#include <string>
#include "Communicator.h"

/*******************************************************************************
 * Client Class: Represents a client that connects to a server.                *
 *               Abstract class that has a factory method that creates clients *
 ******************************************************************************/

class Client : public Communicator {
    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: Client Constructor                                                            *
     * The Input: const string (reference), unsigned short                                          *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input as address                          *
     * *********************************************************************************************/
    
    Client(const std::string& strServerAddress, uint16_t usPort);
    
    /**********************************************************************************************
     * function name: Client Destructor                                                           *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    virtual ~Client();
    
    /**********************************************************************************************
     * function name: createClient                                                                *
     * The Input: ProtocolType (enum), uint16_t, const string object (reference)                  *
     * The output: Client object (pointer)                                                        *
     * The Function Opertion: Returns a Client object that is set with the input protocol,        *
     *                        port and address (as destination connection).                       *
     * *******************************************************************************************/

    static Client* createClient(ProtocolType eType, uint16_t usPort, const std::string& strServerAddress = "");

    
};

#endif
