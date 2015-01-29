/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Implementation of Defender Class       *
 ***********************************************************/

#include "Defender.h"
#include "Behavior.h"

using namespace behavior;

void Defender::actPlayMode(PlayMode ePlayMode)  {
    
    //Decide which Behavior to perform based on the PlayMode
    switch (ePlayMode) {
        case PlayModePlayOn:
            getBrain().setBehavior("GoToPosition");
            break;
            
        case PlayModeBeforeKickOff:
            getBrain().setBehavior("MoveToPosition");
            break;
            
        default:
            getBrain().setBehavior("GoToPosition");
            break;
            
    }
    
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: Defender Constructor                                                          *
 * The Input: const Connection object (pointer), const char (pointer), const Vector (reference) *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the base class.                                           *
 * *********************************************************************************************/

Defender::Defender(const Connection* cConnection, const char* chTeamName) :
Player(cConnection, chTeamName, false) {
 
    //      ---     MOVE TO POSITION      ---     //
    
    BehaviorTree *cMove = new BehaviorTree(*this, getBrain(), "MoveToPosition");
    
    SequenceNode *cMoveStart = new SequenceNode();
    cMoveStart->addChild(new SetTargetToNode(new BehaviorTarget(Coordinate(-36, -20), "Defender")));
    cMoveStart->addChild(new MoveNode());
    cMoveStart->addChild(new SetTargetToNode(new BehaviorTarget(ObservableTypeBall, "Defender")));
    cMoveStart->addChild(new TurnTowardsTypeNode());
    cMoveStart->addChild(new EndActNode());

    cMove->setRoot(cMoveStart);
    
    //      ---     GO TO POSITION      ---     //
    
    BehaviorTree *cGo = new BehaviorTree(*this, getBrain(), "GoToPosition");
    
    SequenceNode *cGoStart = new SequenceNode();
    cGoStart->addChild(new SetTargetToNode(new BehaviorTarget(ObservableTypeFlagPenLeftTop, "Defender")));
    cGoStart->addChild(new DashTowardsTargetNode(3));
    cGoStart->addChild(new SetTargetToNode(new BehaviorTarget(ObservableTypeBall, "Defender")));
    cGoStart->addChild(new TurnTowardsTypeNode());
    cGoStart->addChild(new IsCloseToTargetNode(20));
    cGoStart->addChild(new DashTowardsTargetUntilDistanceNode(20));
    cGoStart->addChild(new SetTargetToOpponentGoalNode());
    cGoStart->addChild(new TurnTowardsTypeNode());
    cGoStart->addChild(new KickBallNode());
    cGoStart->addChild(new EndActNode());

    cGo->setRoot(cGoStart);
    
    getBrain().addBehavior(*cMove);
    getBrain().addBehavior(*cGo);
    
    
}

/**********************************************************************************************
 * function name: Defender Destructor                                                         *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Nothing.                                                            *
 * *******************************************************************************************/

Defender::~Defender() {
    
}
