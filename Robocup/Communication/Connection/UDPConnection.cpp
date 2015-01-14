/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex2                                    *
 * File description: Implementation of UDPConnection Class  *
 ***********************************************************/

#include "UDPConnection.h"

//  ---                         PRIVATE FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: TCPConnection Constructor                                                     *
 * The Input: int, sockaddr_in (pointer)                                                        *
 * The output: none                                                                             *
 * The Function Opertion: Sends the input to the super class.                                   *
 * *********************************************************************************************/

UDPConnection::UDPConnection(int iSocketDescriptor, struct sockaddr_in* sAddress) :
Connection(iSocketDescriptor, sAddress), m_sDestAdderss(*sAddress) {
    
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/**********************************************************************************************
 * function name: TCPConnection Destructor                                                    *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Nothing.                                                            *
 * *******************************************************************************************/

UDPConnection::~UDPConnection() { }

/***********************************************************************************************
 * function name: transmit                                                                     *
 * The Input: void*, size_t                                                                    *
 * The output: ssize_t                                                                         *
 * The Function Opertion: Uses the sendto function from the sys/socket library. Sends the input*
 *                        data of input size with the stored socket descriptor, and the        *
 *                        stored destination address, and returns the result.                  *
 * ********************************************************************************************/

ssize_t UDPConnection::transmit(const void* cData, size_t ulLength) const {
    
    ssize_t iReturn = sendto(m_iSocketDescriptor, cData, ulLength, 0, (struct sockaddr*)&m_sDestAdderss, sizeof(m_sDestAdderss));
    
    if (iReturn < 0) {
        
        //Print the error
        perror("SendTo error");
        
    }

    return iReturn;
    
}

/****************************************************************************************************
 * function name: recieve                                                                           *
 * The Input: void*, size_t                                                                         *
 * The output: ssize_t                                                                              *
 * The Function Opertion: Uses the recvfrom function from the sys/socket library. Stores the input  *
 *                        data of input size from the stored socket descriptor together with the    *
 *                        stored destination address, and returns the result.                       *
 * *************************************************************************************************/

ssize_t UDPConnection::recieve(void* cData, size_t ulLength) const {
    
    unsigned int uiLength = sizeof(struct sockaddr_in);
    
    ssize_t iReturn = recvfrom(m_iSocketDescriptor, cData, ulLength, 0, (struct sockaddr*)&m_sDestAdderss, &uiLength);
    
    if (iReturn < 0) {
        
        //Print the error
        perror("RecvFrom error");
        
    }
    
    return iReturn;
    
}
