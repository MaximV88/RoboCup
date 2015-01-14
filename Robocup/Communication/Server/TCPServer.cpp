/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex2                                    *
 * File description: Implementation of TCPServer Class      *
 ***********************************************************/

#include "TCPServer.h"
#include <errno.h>

//  ---                         PRIVATE FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: TCPServer Constructor                                                         *
 * The Input: const string (reference), int                                                     *
 * The output: none                                                                             *
 * The Function Opertion: Sends the input to the super class, initalize member variable to false*
 * *********************************************************************************************/

TCPServer::TCPServer(const std::string& strAddress, uint16_t usPort) :
Server(strAddress, usPort) { }

//  ---                         PUBLIC FUNCTIONS                       ---   //


/**********************************************************************************************
 * function name: TCPServer Destructor                                                        *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Nothing.                                                            *
 * *******************************************************************************************/

TCPServer::~TCPServer() { }

/**********************************************************************************************
 * function name: start                                                                       *
 * The Input: none                                                                            *
 * The output: int                                                                            *
 * The Function Opertion: If the server is already listening then abort, otherwise create a   *
 *                        socket. If creation was ok save it as the listening socket of the   *
 *                        server. Otherwise return an error. Then bind to the recieved socket *
 *                        with the server's address. If binding failed, return error.         *
 *                        Otherwise proceed to listen to the socket. If there was an error    *
 *                        return it, Otherwise the server is listening and return 0 as success*
 * *******************************************************************************************/

int TCPServer::start() {
    
    //Avoid making duplicate starts - there is no error
    if (m_bIsListening == true)
        return 0;

    //Create a socket descriptor
     int iListeningSocket = socket(AF_INET, SOCK_STREAM, 0);
    
    //If there was an error, stop and return it
    if (iListeningSocket < 0) {
        
        //Print the error
        perror("Socket error");
        
        return iListeningSocket;
        
    }
    
    //The socket is ok, make it the server's socket
    setListeningSocket(iListeningSocket);
    
    //Continue and bind the socket
    sockaddr_in sin = getSocketAddress();
    
    int iBindError = bind(getListeningSocket(), (struct sockaddr *) &sin, sizeof(sin));
    if (iBindError < 0) {
        
        //Close the open socket
        close(iListeningSocket);
        
        //Print the error
        perror("Bind error");
        
        //If recieved an error, return it
        return iBindError;
        
        
    }
    
    //And start listening!
    int iListenError = listen(getListeningSocket(), 10);
    if (iListenError < 0) {
        
        //Close the open socket
        close(iListeningSocket);
        
        //Print the error
        perror("Listen error");
        
        //If recieved an error, return it
        return iListenError;
        
    }
    
    //Server started listening
    m_bIsListening = true;
    
    //No error
    return 0;
    
}

/**********************************************************************************************
 * function name: connection                                                                  *
 * The Input: none                                                                            *
 * The output: const Connection object (pointer)                                              *
 * The Function Opertion: Checks if the server is listening, and if so continues to create    *
 *                        a listening socket. It creates an address from the accepted         *
 *                        connection and if valid, creates a TCP Connection object to return. *
 * *******************************************************************************************/

const Connection* TCPServer::connection() const {
    
    //A connection can be created once the server has been started
    if (m_bIsListening == false)
        return NULL;
    
    /*
     * Create a new connection and return it.
     * A connection needs to accept communications.
     */
    
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    int client_sock = accept(getListeningSocket(), (struct sockaddr *) &client_sin, &addr_len);
    
    if (client_sock < 0) {
        
        //If recieved an error, return null
        return NULL;
        
    }
    
    //The connection can be created with the dedicated socket descriptor
    return createConnection(ProtocolTypeTCP, client_sock, &client_sin);
    
}
