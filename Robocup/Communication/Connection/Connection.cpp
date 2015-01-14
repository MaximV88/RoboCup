/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex2                                    *
 * File description: Implementation of Connection Class     *
 ***********************************************************/

#include <arpa/inet.h>

#include "Connection.h"
#include "TCPConnection.h"
#include "UDPConnection.h"

//  ---                         PRIVATE FUNCTIONS                       ---   //


/**********************************************************************************************
 * function name: createConnection                                                            *
 * The Input: ProtocolType (enum), int, sockaddr_in (pointer)                                 *
 * The output: Connection object (pointer)                                                    *
 * The Function Opertion: Using the input enum value, it decides using a switch control which *
 *                        object to create and return (with input as the funcion arguments).  *
 * *******************************************************************************************/

Connection* Connection::createConnection(ProtocolType eType, int iSocketDescriptor, struct sockaddr_in* sAddress) {
    
    switch (eType) {
        case ProtocolTypeTCP:
            
            //Create and return a TCP server
            return new TCPConnection(iSocketDescriptor, sAddress);
            break;
            
        case ProtocolTypeUDP:
            
            //Create and return a UDP server
            return new UDPConnection(iSocketDescriptor, sAddress);
            break;
            
            //Shouldnt reach here
        default:break;
    }
    
}

//  ---                         PROTECTED FUNCTIONS                       ---   //


/*************************************************************************************************
 * function name: Connection Constructor                                                         *
 * The Input: int, sockaddr_in (pointer)                                                         *
 * The output: none                                                                              *
 * The Function Opertion: Sets the member variable that holds the port using a reverse           *
 *                        translation from the argument address (to print later on), and does    *
 *                        the same for the IP. Saves the socket descriptor to a memember variable*
 * **********************************************************************************************/

Connection::Connection(int iSocketDescriptor, struct sockaddr_in* sAddress) : m_iSocketDescriptor(iSocketDescriptor) {
    
    //Set the destination port
    m_usDestPort = ntohs(sAddress->sin_port);
    
    //Set the ip address as a string
    m_strDestIP = static_cast<std::string>(inet_ntoa(sAddress->sin_addr));
    
    
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/**********************************************************************************************
 * function name: Connection Destructor                                                       *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Nothing.                                                            *
 * *******************************************************************************************/

Connection::~Connection() { }

/************************************************************************************
 * function name: operator<<                                                        *
 * The Input: ostream object (reference), const Communicator object (reference)     *
 * The output: ostream object (reference)                                           *
 * The Function Opertion: Prints the object's member variables into the input       *
 *                        ostream object, and returns it afterwards.                *
 * *********************************************************************************/

std::ostream& operator<<(std::ostream &out, const Connection& cConnection) {
    
    out <<
    "(Destination Port: " << cConnection.m_usDestPort <<
    ", Destination IP: " << cConnection.m_strDestIP <<
    ", SocketDescriptor: " << cConnection.m_iSocketDescriptor << ")";
    return out;
    
}
