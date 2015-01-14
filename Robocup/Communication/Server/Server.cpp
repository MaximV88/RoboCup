/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex2                                    *
 * File description: Implementation of Server Class         *
 ***********************************************************/

#include "Server.h"
#include "TCPServer.h"
#include "UDPServer.h"

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: Server Constructor                                                            *
 * The Input: const string (reference), int                                                     *
 * The output: none                                                                             *
 * The Function Opertion: Sends the input to the super class, initalize member variable to false*
 * *********************************************************************************************/

Server::Server(const std::string& strAddress, uint16_t usPort) :
Communicator(strAddress, usPort) {
    
    m_bIsListening = false;
    
}

/**********************************************************************************************
 * function name: Server Destructor                                                           *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Nothing.                                                            *
 * *******************************************************************************************/

Server::~Server() { }

/**********************************************************************************************
 * function name: createServer                                                                *
 * The Input: ProtocolType (enum), uint16_t, const string object (reference)                  *
 * The output: Server object (pointer)                                                        *
 * The Function Opertion: Using the input enum value, it decides using a switch control which *
 *                        object to create and return (with input as the funcion arguments).  *
 * *******************************************************************************************/

Server* Server::createServer(ProtocolType eType, uint16_t usPort, const std::string& strAddres) {
    
    switch (eType) {
        case ProtocolTypeTCP:
            
            //Create and return a TCP server
            return new TCPServer(strAddres, usPort);
            break;
            
        case ProtocolTypeUDP:
            
            //Create and return a UDP server
            return new UDPServer(strAddres, usPort);
            break;
            
        //Shouldnt reach here
        default:break;
    }
    
}



