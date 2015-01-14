/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex2                                    *
 * File description: Declaration of UDPConnection Class     *
 ***********************************************************/

#ifndef __Ex2__UDPConnection__
#define __Ex2__UDPConnection__

#include <stdio.h>
#include "Connection.h"

/*************************************************************************************
 * UDPConnection Class: Represents a connections to a destination, that has uses the *
 *                      UDP protocol. It has the ability to send and recieve         *
 *                      information from that destination.                           *
 ************************************************************************************/

class UDPConnection : public Connection {
    
private:
    
    friend class Connection;
    
    //  ---                         PRIVATE FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: UDPConnection Constructor                                                     *
     * The Input: int, sockaddr_in (pointer)                                                        *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input as socket and address to be used.   *
     * *********************************************************************************************/
    
    UDPConnection(int iSocketDescriptor, struct sockaddr_in* sAddress);

    //  ---                         PRIVATE VARIABLES                       ---   //

    
    //Stores the address of the destination of the connection
    const sockaddr_in m_sDestAdderss;
    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /**********************************************************************************************
     * function name: TCPConnection Destructor                                                    *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~UDPConnection();
    
    /**********************************************************************************************
     * function name: transmit                                                                    *
     * The Input: void*, size_t                                                                   *
     * The output: ssize_t                                                                        *
     * The Function Opertion: Sends the input data, of a specific length, to the destination that *
     *                        the connection was created with. Returns the number of bytes that   *
     *                        have been sent (or -1 if an error occured). Using UDP.              *
     * *******************************************************************************************/
    
    virtual ssize_t transmit(const void* cData, size_t ulLength) const;
    
    /**********************************************************************************************
     * function name: recieve                                                                     *
     * The Input: void*, size_t                                                                   *
     * The output: ssize_t                                                                        *
     * The Function Opertion: Recieves data to input buffer, of a specific length, from the       *
     *                        destination that the connection was created with. Returns the number*
     *                        of bytes that have been recieved (or -1 if an error occured), or 0  *
     *                        if the destination has closed the link. Using UDP                   *
     * *******************************************************************************************/
    
    virtual ssize_t recieve(void* cData, size_t ulLength) const;
    
};


#endif  
