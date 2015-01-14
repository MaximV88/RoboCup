/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex2                                    *
 * File description: Implementation of Communicator Class   *
 ***********************************************************/

#include "UDPClient.h"

//  ---                         PRIVATE FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: TCPClient Constructor                                                         *
 * The Input: const string (reference), unsigned short                                          *
 * The output: none                                                                             *
 * The Function Opertion: Sends the input to the super class.                                   *
 * *********************************************************************************************/

UDPClient::UDPClient(const std::string& strServerAddress, uint16_t usPort) :
Client(strServerAddress, usPort) { }

//  ---                         PUBLIC FUNCTIONS                       ---   //


/**********************************************************************************************
 * function name: UDPClient Destructor                                                        *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Nothing, the internal inherited values are removed in the superclass*
 * *******************************************************************************************/

UDPClient::~UDPClient() { }

/**********************************************************************************************
 * function name: connection                                                                  *
 * The Input: none                                                                            *
 * The output: const Connection object (pointer)                                              *
 * The Function Opertion: Creates a socket based on the UDP protocol, and if valid,           *
 *                        creates a new Connection object with the created socket             *
 *                        and destination address (for Connection's use).                     *
 * *******************************************************************************************/

const Connection* UDPClient::connection() const {
    
    //Each connection should have it's own socket
    
    
    //Create a socket descriptor
    int iListeningSocket = (socket(AF_INET, SOCK_DGRAM, 0));
    
    //If there was an error, stop and return it
    if (iListeningSocket < 0){
        
        //Print the error
        perror("Socket error");
        
        return NULL;
        
    }
    
    //Otherwise, continue and connect to the socket
    sockaddr_in sin = getSocketAddress();
    
    
    //The connection can be created with the dedicated socket descriptor
    return createConnection(ProtocolTypeUDP, iListeningSocket, &sin);
    
}
