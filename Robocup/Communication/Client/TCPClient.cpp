/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex2                                    *
 * File description: Implementation of Communicator Class   *
 ***********************************************************/

#include "TCPClient.h"

//  ---                         PRIVATE FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: TCPClient Constructor                                                         *
 * The Input: const string (reference), unsigned short                                          *
 * The output: none                                                                             *
 * The Function Opertion: Sends the input to the super class.                                   *
 * *********************************************************************************************/

TCPClient::TCPClient(const std::string& strServerAddress, uint16_t usPort) :
Client(strServerAddress, usPort) { }


//  ---                         PUBLIC FUNCTIONS                       ---   //


/**********************************************************************************************
 * function name: TCPClient Destructor                                                        *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Nothing, the internal inherited values are removed in the superclass*
 * *******************************************************************************************/

TCPClient::~TCPClient() { }

/**********************************************************************************************
 * function name: connection                                                                  *
 * The Input: none                                                                            *
 * The output: const Connection object (pointer)                                              *
 * The Function Opertion: Creates a socket based on the TCP protocol, and if valid sets       *
 *                        the client's address (destination) as address using connect.        *
 *                        Afterwards creates a new Connection object with the created socket  *
 *                        and destination address (for Connection's use).                     *
 * *******************************************************************************************/

const Connection* TCPClient::connection() const {

    //Each connection should have it's own socket
    
    
    //Create a socket descriptor
    int iListeningSocket = (socket(AF_INET, SOCK_STREAM, 0));
    
    //If there was an error, stop and return it
    if (iListeningSocket < 0) {
        
        //Print the error
        perror("Socket error");
        
        return NULL;
        
    }
    
    //Otherwise, continue and connect to the socket
    sockaddr_in sin = getSocketAddress();
    
    //Need to connect
    int iConnectError = connect(iListeningSocket, (struct sockaddr *) &sin, sizeof(sin));
    if (iConnectError < 0) {
        
        //Close the open socket
        close(iListeningSocket);

        //Print the error
        perror("Connection error");
        
        //If recieved an error, return it
        return NULL;
        
        
    }
    
    
    //The connection can be created with the dedicated socket descriptor
    return createConnection(ProtocolTypeTCP, iListeningSocket, &sin);
    
}