/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Declaration of Parser Class            *
 ***********************************************************/

#ifndef __Ex3__Parser__
#define __Ex3__Parser__

#include <stdio.h>
#include <string>
#include <map>

#include "Threadable.h"
#include "ThreadQueue.h"
#include "ParserCommonDefinitions.h"
#include "ParserTypeDefinitions.h"

#include "BodyState.h"
#include "ServerState.h"
#include "PlayerState.h"
#include "TeamState.h"
#include "HearState.h"
#include "SeeState.h"

namespace parse {
    
    /*******************************************************************************
     * Parser Class: Parses the strings recieved from the server and sends them    *
     *               to their correct states to be parsed on.                      *
     *               Pushes the initialized states (and thus parsed on this thread)*
     *               to the queue to be handled by the player.                     *
     ******************************************************************************/
    
    class Parser : public Threadable {
        
    private:
        
        //  ---                         PRIVATE VARIABLES                       ---   //

        //Holds the states
        ThreadQueue<State*>& m_qStateQueue;
        
        //Holds the errors recieved from server
        ThreadQueue<parse::ErrorType>& m_qErrorQueue;
        
        //Holds the input recieved from the server
        ThreadQueue<std::string*> m_qInputQueue;
        
        //Maps the values recieved from the server (strings) to their types (ints)
        std::map<std::string, parse::ParseType> m_cParseMap;

        //Maps the errors recieved from the server (strings) to their types (ints)
        std::map<std::string, parse::ErrorType> m_cErrorMap;
        
        //Holds the last server state
        ServerState m_cServerState;
        
        //Holds the last player state
        PlayerState m_cPlayerState;
        
        //Holds the last team state
        TeamState m_cTeamState;
        
        //Holds the last body state
        BodyState m_cBodyState;
        
        //  ---                         PRIVATE FUNCTIONS                       ---   //

        
        /****************************************************************************************************
         * function name: execute                                                                           *
         * The Input: none                                                                                  *
         * The output: none                                                                                 *
         * The Function Opertion: Executes the operations required from this class (it's the 'main' thread  *
         *                        of this object), in a loop.                                               *
         * *************************************************************************************************/
        
        virtual void execute();
        
        /****************************************************************************************************
         * function name: buildErrorMap                                                                     *
         * The Input: none                                                                                  *
         * The output: none                                                                                 *
         * The Function Opertion: Maps the error input from the server to their types.                      *
         * *************************************************************************************************/
        
        void buildErrorMap();
        
        /****************************************************************************************************
         * function name: buildParseMap                                                                     *
         * The Input: none                                                                                  *
         * The output: none                                                                                 *
         * The Function Opertion: Maps the valid input from the server to their types.                      *
         * *************************************************************************************************/
        
        void buildParseMap();
        
        /****************************************************************************************************
         * function name: parseValidInput                                                                   *
         * The Input: const string object (reference)                                                       *
         * The output: State object (pointer)                                                               *
         * The Function Opertion: Gets the input string to their associated state.                          *
         * *************************************************************************************************/
        
        State* parseValidInput(const std::string& strInput);
        
    public:
        
        //  ---                         PUBLIC FUNCTIONS                       ---   //
        
        
        /************************************************************************************************
         * function name: Parser Constructor                                                            *
         * The Input: ThreadQueue<State*> object (reference), ThreadQueue<ErrorType> object (reference) *
         * The output: none                                                                             *
         * The Function Opertion: Initializes the object with input queues.                             *
         * *********************************************************************************************/
        
        Parser(ThreadQueue<State*>& qStateQueue, ThreadQueue<parse::ErrorType>& qErrorQueue);
        
        /**********************************************************************************************
         * function name: Parser Destructor                                                           *
         * The Input: none                                                                            *
         * The output: none                                                                           *
         * The Function Opertion: Destroys the current object.                                        *
         * *******************************************************************************************/
        
        ~Parser();
        
        /**********************************************************************************************
         * function name: parse                                                                       *
         * The Input: const char* (pointer)                                                           *
         * The output: none                                                                           *
         * The Function Opertion: Parses a c string.                                                  *
         * *******************************************************************************************/
        
        void parse(const char* chInput);
        
        /**********************************************************************************************
         * function name: validate                                                                    *
         * The Input: const string object (reference)                                                 *
         * The output: ErrorType                                                                      *
         * The Function Opertion: Validates that the input is not an error or a warning.              *
         * *******************************************************************************************/
        
        parse::ErrorType validate(const std::string& strInput);
        
    };
    
}

#endif
