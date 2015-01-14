/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex2                                    *
 * File description: Implementation of Client Class         *
 ***********************************************************/

#include "Client.h"
#include "TCPClient.h"
#include "UDPClient.h"

/************************************************************************************************
 * function name: Client Constructor                                                            *
 * The Input: const string (reference), unsigned short                                          *
 * The output: none                                                                             *
 * The Function Opertion: Sends the input to the super class.                                   *
 * *********************************************************************************************/

Client::Client(const std::string& strServerAddress, uint16_t usPort) :
Communicator(strServerAddress, usPort) { }

/**********************************************************************************************
 * function name: Client Destructor                                                           *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Nothing, the internal inherited values are removed in the superclass*
 * *******************************************************************************************/

Client::~Client() { }

/**********************************************************************************************
 * function name: createClient                                                                *
 * The Input: ProtocolType (enum), uint16_t, const string object (reference)                  *
 * The output: Client object (pointer                                                         *
 * The Function Opertion: Creates a new Client from a switch control, and creates the client  *
 *                        as a TCP or UDP object with arguments as input.                     *
 * *******************************************************************************************/

Client* Client::createClient(ProtocolType eType, uint16_t usPort, const std::string& strServerAddress) {
    
    switch (eType) {
        case ProtocolTypeTCP:
            
            //Create and return a TCP server
            return new TCPClient(strServerAddress, usPort);
            break;
            
        case ProtocolTypeUDP:
            
            //Create and return a UDP server
            return new UDPClient(strServerAddress, usPort);
            break;
            
            //Shouldnt reach here
        default:break;
    }
    
}

