/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Declaration of Instruction Class       *
 ***********************************************************/

#ifndef __Ex3__Instruction__
#define __Ex3__Instruction__

#include <stdio.h>
#include <string>

/*******************************************************************************
 * Instruction Class: Represents an instruction issued by the player,          *
 *                    that is to be sent to the server.                        *
 ******************************************************************************/

class Instruction {
    
    //  ---                         PRIVATE FUNCTIONS                       ---   //

    //Contains the parsed instruction
    std::string m_strInstruction;
    
    //Flag to indicate if a command has been given
    bool m_bHasCommand;
    
    //Can the instruction executed only once per cycle? (can be attached to another instruction)
    bool m_bIsAttachable;
        
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: Instruction Constructor                                                       *
     * The Input: none                                                                              *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object.                                               *
     * *********************************************************************************************/
    
    Instruction();
    
    /**********************************************************************************************
     * function name: Instruction Destructor                                                      *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~Instruction();
    
    /**********************************************************************************************
     * function name: addCommand                                                                  *
     * The Input: const string object (reference)                                                 *
     * The output: none                                                                           *
     * The Function Opertion: Adds a command to the instruction.                                  *
     * *******************************************************************************************/
    
    void addCommand(const std::string& strCommand);
    
    /**********************************************************************************************
     * function name: getInstruction                                                              *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Return a copy of the parsed instruction.                            *
     * *******************************************************************************************/
    
    std::string getInstruction() const;
    
    /**********************************************************************************************
     * function name: setAttachable                                                               *
     * The Input: bool                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Sets the instruction as attachable (can be added to another         *
     *                        instruction).                                                       *
     * *******************************************************************************************/
    
    void setAttachable(bool bAttachable);
    
    /**********************************************************************************************
     * function name: isAttachable                                                                *
     * The Input: none                                                                            *
     * The output: bool                                                                           *
     * The Function Opertion: Returns true if the instruction is attachble, false otherwise.      *
     * *******************************************************************************************/
    
    bool isAttachable() const;
    
};

#endif
