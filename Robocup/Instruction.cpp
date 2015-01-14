/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Implementation of Instruction Class    *
 ***********************************************************/

#include "Instruction.h"

#define INSTRUCTION_STARTING_CHARACTER "("
#define INSTRUCTION_ENDING_CHARACTER ")"
#define INSTRUCTION_DIFFERENTIATING_CHARACTER  " "

using namespace std;

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: Instruction Constructor                                                       *
 * The Input: none                                                                              *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object's member variable with default values.         *
 * *********************************************************************************************/

Instruction::Instruction() {

    //The starting character of every command is '('
    m_strInstruction = string(INSTRUCTION_STARTING_CHARACTER);
    
    //Marks if the instruction already has a command
    m_bHasCommand = false;
    
    //Default should not attach to other instructions to prevent bugs
    m_bIsAttachable = false;
    
}

/**********************************************************************************************
 * function name: Instruction Destructor                                                      *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Destroys the current object.                                        *
 * *******************************************************************************************/

Instruction::~Instruction() { }

/**********************************************************************************************
 * function name: addCommand                                                                  *
 * The Input: const string object (reference)                                                 *
 * The output: none                                                                           *
 * The Function Opertion: Appends the input string to the instruction string,                 *
 *                        and appends the differentiating string according to the flag.       *
 * *******************************************************************************************/

void Instruction::addCommand(const std::string &strCommand) {
    
    //If it's not the first command, then append a space before it
    if (m_bHasCommand)
        m_strInstruction.append(INSTRUCTION_DIFFERENTIATING_CHARACTER);
    
    //Append the input
    m_strInstruction.append(strCommand);
    
    //Added a command, so change the flag
    m_bHasCommand = true;
    
}

/****************************************************************************************************
 * function name: getInstruction                                                                    *
 * The Input: none                                                                                  *
 * The output: none                                                                                 *
 * The Function Opertion: Appends the ending character to the contained string's copy and returns   *
 *                        a copy of the copy (cant do better unless using pointers, since the       *
 *                        object is stack allocated (local variable).                               *
 * *************************************************************************************************/

std::string Instruction::getInstruction() const {

    //Append the ')' to end the current commands
    string strInstruction = m_strInstruction;
    strInstruction.append(INSTRUCTION_ENDING_CHARACTER);
    
    return strInstruction;
    
}

/**********************************************************************************************
 * function name: setAttachable                                                               *
 * The Input: bool                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Changed the member variable flag.                                   *
 * *******************************************************************************************/

void Instruction::setAttachable(bool bAttachable) {
 
    m_bIsAttachable = bAttachable;
    
}

/**********************************************************************************************
 * function name: isAttachable                                                                *
 * The Input: none                                                                            *
 * The output: bool                                                                           *
 * The Function Opertion: Returns a copy of the member variable.                              *
 * *******************************************************************************************/

bool Instruction::isAttachable() const {
    
    return m_bIsAttachable;

}
