/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex2                                    *
 * File description: Implementation of Communicator Class   *
 ***********************************************************/

#include "TCPConnection.h"
#include <unistd.h>

//  ---                         PRIVATE FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: TCPConnection Constructor                                                     *
 * The Input: int, sockaddr_in (pointer)                                                        *
 * The output: none                                                                             *
 * The Function Opertion: Sends the input to the super class.                                   *
 * *********************************************************************************************/

TCPConnection::TCPConnection(int iSocketDescriptor, struct sockaddr_in* sAddress) :
Connection(iSocketDescriptor, sAddress) { }

//  ---                         PUBLIC FUNCTIONS                       ---   //


/**********************************************************************************************
 * function name: TCPConnection Destructor                                                    *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Closes the open socket (there must be one, otherwise the object     *
 *                        wouldnt have been created).                                         *
 * *******************************************************************************************/

TCPConnection::~TCPConnection() {
    
    close(m_iSocketDescriptor);
    
}

/**********************************************************************************************
 * function name: transmit                                                                    *
 * The Input: void*, size_t                                                                   *
 * The output: ssize_t                                                                        *
 * The Function Opertion: Uses the send function from the sys/socket library. Sends the input *
 *                        data of input size with the stored socket descriptor and returns    *
 *                        the result.                                                         *
 * *******************************************************************************************/

ssize_t TCPConnection::transmit(const void* cData, size_t ulLength) const {
    
    ssize_t iReturn = send(m_iSocketDescriptor, cData, ulLength, 0);
    
    if (iReturn < 0) {
        
        //Print the error
        perror("Send error");
        
    }
    
    return iReturn;
    
}

/**********************************************************************************************
 * function name: recieve                                                                     *
 * The Input: void*, size_t                                                                   *
 * The output: ssize_t                                                                        *
 * The Function Opertion: Uses the recv function from the sys/socket library. stores the input*
 *                        data of input size with the stored socket descriptor and returns    *
 *                        the result.                                                         *
 * *******************************************************************************************/

ssize_t TCPConnection::recieve(void* cData, size_t ulLength) const {
    
    ssize_t iReturn = recv(m_iSocketDescriptor, cData, ulLength, 0);
    
    if (iReturn < 0) {
        
        //Print the error
        perror("Recv error");
        
    }
    
    return iReturn;
    
}

