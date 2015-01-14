/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex2                                    *
 * File description: Declaration of UDPClient Class         *
 ***********************************************************/

#ifndef __Ex2__UDPClient__
#define __Ex2__UDPClient__

#include <stdio.h>
#include "Client.h"

/*******************************************************************************
 * UDPClient Class: A Client that works with UDP protocol to connect           *
 *                  to the input address (needs to be a server).               *
 ******************************************************************************/

class UDPClient : public Client {
    
private:
    
    friend class Client;
    
    //  ---                         PRIVATE FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: UDPClient Constructor                                                         *
     * The Input: const string (reference), unsigned short                                          *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input as address                          *
     * *********************************************************************************************/

    UDPClient(const std::string& strServerAddress, uint16_t usPort);
    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /**********************************************************************************************
     * function name: UDPClient Destructor                                                        *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~UDPClient();
    
    /**********************************************************************************************
     * function name: connection                                                                  *
     * The Input: none                                                                            *
     * The output: const Connection object (pointer)                                              *
     * The Function Opertion: Returns a connection object that is a link between this object and  *
     *                        it's destination (was given in constructor).                        *
     * *******************************************************************************************/
  
    virtual const Connection* connection() const;

};

#endif  
