/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex2                                    *
 * File description: Implementation of Communicator Class   *
 ***********************************************************/

#include "Communicator.h"
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

//  ---                         PROTECTED FUNCTIONS                       ---   //


/**********************************************************************************************
 * function name: getSocketAddress                                                            *
 * The Input: none                                                                            *
 * The output: sockaddr_in                                                                    *
 * The Function Opertion: Returns a copy of the saved sockaddr_in struct in this object.      *
 * *******************************************************************************************/

sockaddr_in Communicator::getSocketAddress() const {
    
    //Return a copy of this communicator's socket address
    return m_sSocketAddress;
    
}

/**********************************************************************************************
 * function name: setListeningSocket                                                          *
 * The Input: int                                                                             *
 * The output: none                                                                           *
 * The Function Opertion: Sets the member variable that holds the listening socket.           *
 * *******************************************************************************************/

void Communicator::setListeningSocket(int iListeningSocket) {
    
    //Just set the value
    m_iListeningSocket = iListeningSocket;
    
}

/**********************************************************************************************
 * function name: getListeningSocket                                                          *
 * The Input: none                                                                            *
 * The output: int                                                                            *
 * The Function Opertion: Returns a copy of the listening socket for this object.             *
 * *******************************************************************************************/

int Communicator::getListeningSocket() const {
    
    //Return a copy of the member variable
    return m_iListeningSocket;
    
}

/**********************************************************************************************
 * function name: createConnection                                                            *
 * The Input: ProtocolType (enum), int, sockaddr_in (pointer)                                 *
 * The output: Connection object (pointer)                                                    *
 * The Function Opertion: Returns the object that was created by the connection factory method*
 *                        using a factory method in the base class prevents friend declaration*
 *                        for child object in the Connection's subclasses.                    *
 * *******************************************************************************************/

Connection* Communicator::createConnection(ProtocolType eType, int iSocketDescriptor, struct sockaddr_in* sAddress) const {
    
    //Avoid multiple friend declarations
    return Connection::createConnection(eType, iSocketDescriptor, sAddress);
    
}

/************************************************************************************************
 * function name: Communicator Constructor                                                      *
 * The Input: const string (reference), unsigned short                                          *
 * The output: none                                                                             *
 * The Function Opertion: Creates the address struct (for sys/socket.h) using given functions   *
 *                        that are given from sys/socket.h, arpa/inet.h and unistd.h.           *
 *                        It first sets the port and address, and later creates the sockaddr_in *
 *                        to be stored in the object for later use.                             *
 * *********************************************************************************************/

Communicator::Communicator(const std::string& strAddress, uint16_t usPort) {
    
    //Copy the input arguments to internal member variables
    m_strAddress = strAddress;
    m_usPort = usPort;
    m_iListeningSocket = 0;

    //Createa a socket address for this communicator
    memset(&m_sSocketAddress, 0, sizeof(m_sSocketAddress));
    m_sSocketAddress.sin_family = AF_INET;
    m_sSocketAddress.sin_port = htons(m_usPort);
    
    //Check to see if recieved an IP, and use it. Otherwise just listen to all
    if (m_strAddress.length() != 0) {
        
        /*
         * Listen to a particular address:
         * This functions converts from string to network address,
         * and copies the result into the sin- object's address
         */
        
        inet_pton(PF_INET, m_strAddress.c_str(), &(m_sSocketAddress.sin_addr));
        
        
    }
    else {
        
        //Listen to all
        m_sSocketAddress.sin_addr.s_addr = INADDR_ANY;
        
    }
    
}

/**********************************************************************************************
 * function name: Communicator Destructor                                                     *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: If a socket has been registered with this object, close it.         *
 * *******************************************************************************************/

Communicator::~Communicator() {
    
    //If there is a connected socket, close it
    if (m_iListeningSocket > 0)
        close(m_iListeningSocket);
    
}

/************************************************************************************
 * function name: operator<<                                                        *
 * The Input: ostream object (reference), const Communicator object (reference)     *
 * The output: ostream object (reference)                                           *
 * The Function Opertion: Prints the object's member variables into the input       *
 *                        ostream object, and returns it afterwards.                *
 * *********************************************************************************/

std::ostream& operator<<(std::ostream &out, const Communicator& cCommunicator) {
    
    out <<
    "(Port: " << cCommunicator.m_usPort <<
    ", IP: " << cCommunicator.m_strAddress <<
    ", SocketDescriptor: " << cCommunicator.m_iListeningSocket << ")";
    return out;
    
}
