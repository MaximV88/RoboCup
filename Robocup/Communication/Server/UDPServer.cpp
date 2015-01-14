/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex2                                    *
 * File description: Implementation of UDPServer Class      *
 ***********************************************************/

#include "UDPServer.h"

//  ---                         PRIVATE FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: UDPServer Constructor                                                         *
 * The Input: const string (reference), int                                                     *
 * The output: none                                                                             *
 * The Function Opertion: Sends the input to the super class, initalize member variable to false*
 * *********************************************************************************************/

UDPServer::UDPServer(const std::string& strAddress, uint16_t usPort) :
Server(strAddress, usPort) { }

//  ---                         PUBLIC FUNCTIONS                       ---   //


/**********************************************************************************************
 * function name: TCPServer Destructor                                                        *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Nothing.                                                            *
 * *******************************************************************************************/

UDPServer::~UDPServer() { }

/**********************************************************************************************
 * function name: start                                                                       *
 * The Input: none                                                                            *
 * The output: int                                                                            *
 * The Function Opertion: If the server is already listening then abort, otherwise create a   *
 *                        socket. If creation was ok save it as the listening socket of the   *
 *                        server. Otherwise return an error. Then bind to the recieved socket *
 *                        with the server's address. If binding failed, return error.         *
 * *******************************************************************************************/

int UDPServer::start() {
    
    //Avoid making duplicate starts - there is no error
    if (m_bIsListening == true)
        return 0;
    
    //Create a socket descriptor
    int iListeningSocket = socket(AF_INET, SOCK_DGRAM, 0);
    
    //If there was an error, stop and return it
    if (iListeningSocket < 0){
        
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
    
    //Server started listening, no need to listen to a particular socket - UDP has all
    m_bIsListening = true;
    
    //No error
    return 0;
    
}

/**********************************************************************************************
 * function name: connection                                                                  *
 * The Input: none                                                                            *
 * The output: const Connection object (pointer)                                              *
 * The Function Opertion: Checks if the server is listening, and if so creates a UDP          *
 *                        Connection object to return with the server's socket. (This object  *
 *                        will not close the connection unlike the TCP object).               *
 * *******************************************************************************************/

const Connection* UDPServer::connection() const {
    
    //A connection can be created once the server has been started
    if (m_bIsListening == false)
        return NULL;
    
    /*
     * Create a new connection and return it.
     */
    
    sockaddr_in sin = getSocketAddress();
    
    //The connection can be created with the dedicated socket descriptor
    return createConnection(ProtocolTypeUDP, getListeningSocket(), &sin);
    
}
