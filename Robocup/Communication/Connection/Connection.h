/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex2                                    *
 * File description: Declaration of Connection Class        *
 ***********************************************************/

#ifndef __Ex2__Connection__
#define __Ex2__Connection__

#include <stdio.h>
#include <netinet/in.h>
#include <string>
#include <iostream>

typedef enum {
    ProtocolTypeTCP,
    ProtocolTypeUDP
}ProtocolType;

/*************************************************************************************
 * Connection Class: Represents a connections to a destination, that has the         *
 *                   ability to send and recieve information from that destination.  *
 ************************************************************************************/

class Connection {
    
private:
    
    friend class Communicator;
    
    //  ---                         PRIVATE FUNCTIONS                       ---   //
    
    
    /**********************************************************************************************
     * function name: createConnection                                                            *
     * The Input: ProtocolType (enum), int, sockaddr_in (pointer)                                 *
     * The output: Connection object (pointer)                                                    *
     * The Function Opertion: A factory method that returns a new Connection object with arguments*
     *                        as Protocol, Socket and address for sending and recieving data.     *
     * *******************************************************************************************/
    
    static Connection* createConnection(ProtocolType eType, int iSocketDescriptor, struct sockaddr_in* sAddress);

    
    //  ---                         PRIVATE VARIABLES                       ---   //


    //Stores the destination IP, used to debug printing
    std::string m_strDestIP;
    
    //Stores the destination port, used to debug print
    uint16_t m_usDestPort;
    
protected:
    
    //  ---                         PRIVATE VARIABLES                       ---   //

    
    //Stores the socket descriptor of this object
    const int m_iSocketDescriptor;
    
    //  ---                         PROTECTED FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: Connection Constructor                                                        *
     * The Input: int, sockaddr_in (pointer)                                                        *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input as socket and address to be used.   *
     * *********************************************************************************************/
    
    Connection(int iSocketDescriptor, struct sockaddr_in* sAddress);

    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //

    
    /**********************************************************************************************
     * function name: Connection Destructor                                                       *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
        
    virtual ~Connection();
    
    /**********************************************************************************************
     * function name: transmit                                                                    *
     * The Input: void*, size_t                                                                   *
     * The output: ssize_t                                                                        *
     * The Function Opertion: Sends the input data, of a specific length, to the destination that *
     *                        the connection was created with. Returns the number of bytes that   *
     *                        have been sent (or -1 if an error occured).                         *
     * *******************************************************************************************/
    
    virtual ssize_t transmit(const void* cData, size_t ulLength) const = 0;
    
    /**********************************************************************************************
     * function name: recieve                                                                     *
     * The Input: void*, size_t                                                                   *
     * The output: ssize_t                                                                        *
     * The Function Opertion: Recieves data to input buffer, of a specific length, from the       *
     *                        destination that the connection was created with. Returns the number*
     *                        of bytes that have been recieved (or -1 if an error occured), or 0  *
     *                        if the destination has closed the link.                             *
     * *******************************************************************************************/
    
    virtual ssize_t recieve(void* cData, size_t ulLength) const = 0;
    
    /************************************************************************************
     * function name: operator<<                                                        *
     * The Input: ostream object (reference), const Communicator object (reference)     *
     * The output: ostream object (reference)                                           *
     * The Function Opertion: Prints the object.                                        *
     * *********************************************************************************/
    
    friend std::ostream& operator<<(std::ostream &out, const Connection& cConnection);

};

#endif
