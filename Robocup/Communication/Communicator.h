/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex2                                    *
 * File description: Declaration of Communicator Class      *
 ***********************************************************/

#ifndef __Ex2__Communicator__
#define __Ex2__Communicator__

#include <stdio.h>
#include <string>

#include "Connection.h"

/********************************************************************
 * Communicator Class: Represents an object that has an address,    *
 *                     socket and the ability to issue connections. *
 *******************************************************************/

class Communicator {
    
private:
    
    //  ---                         PRIVATE VARIABLES                       ---   //

    
    //Stores the string address
    std::string m_strAddress;
    
    //Stores the port
    uint16_t m_usPort;
    
    //Stores the socket that belongs to this object (if it has one)
    int m_iListeningSocket;
    
    //Represents the object's stored address for compliance with sys/socket.h usage
    sockaddr_in m_sSocketAddress;
    
    
protected:
    
    //  ---                         PROTECTED FUNCTIONS                       ---   //

    
    /**********************************************************************************************
     * function name: getSocketAddress                                                            *
     * The Input: none                                                                            *
     * The output: sockaddr_in                                                                    *
     * The Function Opertion: Returns the address of this object as a struct that can be used with*
     *                        sys/socket.h functions.                                             *
     * *******************************************************************************************/
    
    sockaddr_in getSocketAddress() const;

    /**********************************************************************************************
     * function name: setListeningSocket                                                          *
     * The Input: int                                                                             *
     * The output: none                                                                           *
     * The Function Opertion: Sets the socket of the current object.                              *
     * *******************************************************************************************/
    
    void setListeningSocket(int iListeningSocket);
    
    /**********************************************************************************************
     * function name: getListeningSocket                                                          *
     * The Input: none                                                                            *
     * The output: int                                                                            *
     * The Function Opertion: Gets the socket of the current object.                              *
     * *******************************************************************************************/
    
    int getListeningSocket() const;
    
    /**********************************************************************************************
     * function name: createConnection                                                            *
     * The Input: ProtocolType (enum), int, sockaddr_in (pointer)                                 *
     * The output: Connection object (pointer)                                                    *
     * The Function Opertion: Returns a Connection object that uses the input Protocol, with the  *
     *                        input socket and address as arguments for sending and recieving data*
     * *******************************************************************************************/
    
    Connection* createConnection(ProtocolType eType, int iSocketDescriptor, struct sockaddr_in* sAddress) const;

public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: Communicator Constructor                                                      *
     * The Input: const string (reference), unsigned short                                          *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input as address                          *
     * *********************************************************************************************/

    Communicator(const std::string& strAddress, uint16_t usPort);
    
    /**********************************************************************************************
     * function name: Communicator Destructor                                                     *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    virtual ~Communicator() = 0;
    
    /**********************************************************************************************
     * function name: connection                                                                  *
     * The Input: none                                                                            *
     * The output: const Connection object (pointer)                                              *
     * The Function Opertion: Returns a connection object that is a link between this object and  *
     *                        it's destination (was given in constructor).                        *
     * *******************************************************************************************/
    
    virtual const Connection* connection() const = 0;
    
    /************************************************************************************
     * function name: operator<<                                                        *
     * The Input: ostream object (reference), const Communicator object (reference)     *
     * The output: ostream object (reference)                                           *
     * The Function Opertion: Prints the object.                                        *
     * *********************************************************************************/
    
    friend std::ostream& operator<<(std::ostream &out, const Communicator& cCommunicator);


};

#endif
