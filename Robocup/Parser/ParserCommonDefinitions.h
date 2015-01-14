/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Declaration of Paser Common definitions*
 ***********************************************************/

#ifndef Ex3_ParserCommonDefinitions_h
#define Ex3_ParserCommonDefinitions_h

#define PARSER_KEYWORD_ERROR_NO_MORE_PLAYER_OR_GOALIE_OR_ILLEGAL_CLIENT_VERSION "no_more_player_or_goalie_or_illegal_client_version"

namespace parse {
    
    typedef enum {
        
        ErrorTypeErrorIlligalCommandForm,
        ErrorTypeErrorUnknownCommand,
        ErrorTypeErrorNoMoreTeamOrPlayerOrGoalie,
        ErrorTypeErrorNoMorePlayerOrGoalieorIllegalClientVersion,
        ErrorTypeErrorNoMoreTeamOrPlayer,
        ErrorTypeErrorReconnect,
        ErrorTypeErrorTooManyMoves,
        ErrorTypeErrorIllegalMode,
        ErrorTypeErrorIllegalObjectForm,
        ErrorTypeErrorSaidTooManyMessages,
        ErrorTypeWarningCompressionUnsupported,
        ErrorTypeWarningNoTeamFound,
        ErrorTypeWarningNoSuchPlayer,
        ErrorTypeWarningCannotSubWhilePlayon,
        ErrorTypeWarningNoSubsLeft,
        ErrorTypeWarningMaxOfThatTypeOnField,
        ErrorTypeWarningCannotChangeGoalie,
        ErrorTypeNone
        
    } ErrorType;
    
}

#endif
