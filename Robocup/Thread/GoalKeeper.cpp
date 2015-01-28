/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Implementation of GoalKeeper Class     *
 ***********************************************************/

#include "GoalKeeper.h"
#include "Behavior.h"

using namespace behavior;

void GoalKeeper::actPlayMode(PlayMode ePlayMode)  {
    
    //Decide which Behavior to perform based on the PlayMode
    switch (ePlayMode) {
        case PlayModePlayOn:
            getBrain().setBehavior("Guard");
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
 * function name: GoalKeeper Constructor                                                        *
 * The Input: const Connection object (pointer), const char (pointer), const Vector (reference) *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the base class.                                           *
 * *********************************************************************************************/

GoalKeeper::GoalKeeper(const Connection* cConnection, const char* chTeamName) :
Player(cConnection, chTeamName, true) {
    
    //      ---     MOVE TO POSITION      ---     //

    BehaviorTree *cMove = new BehaviorTree(*this, getBrain(), "MoveToPosition");
    
    SequenceNode *cMoveStart = new SequenceNode();
    cMoveStart->addChild(new SetTargetToNode(new BehaviorTarget(Coordinate(-50, 0), "GoalKeeper")));
    cMoveStart->addChild(new MoveNode());
    cMoveStart->addChild(new SetTargetToNode(new BehaviorTarget(ObservableTypeBall, "GoalKeeper")));
    cMoveStart->addChild(new RepeatForeverNode( new TurnTowardsTypeNode()));
    
    cMove->setRoot(cMoveStart);
    
    //      ---     GO TO POSITION      ---     //
    
    BehaviorTree *cGo = new BehaviorTree(*this, getBrain(), "GoToPosition");
    
    SequenceNode *cGoStart = new SequenceNode();
    cGoStart->addChild(new SetTargetToTeamGoalNode());
    cGoStart->addChild(new DashTowardsTargetNode());
    cGoStart->addChild(new SetTargetToNode(new BehaviorTarget(ObservableTypeBall, "GoalKeeper")));
    cGoStart->addChild(new RepeatForeverNode(new TurnTowardsTypeNode()));
    
    cGo->setRoot(cGoStart);
    
    //      ---     GUARD      ---     //
    
    BehaviorTree *cGuard = new BehaviorTree(*this, getBrain(), "Guard");

    //Add Checking to see if the ball is close
    SequenceNode *cIsBallNear = new SequenceNode();
    cIsBallNear->addChild(new SetTargetToNode(new BehaviorTarget(ObservableTypeBall, "GoalKeeper")));
    cIsBallNear->addChild(new TurnTowardsTypeNode());
    cIsBallNear->addChild(new IsCloseToTargetNode(15));
    cIsBallNear->addChild(new DashTowardsTargetUntilDistanceNode(15));
    cIsBallNear->addChild(new CatchBallNode());
    cIsBallNear->addChild(new SetTargetToOpponentGoalNode());
    cIsBallNear->addChild(new KickBallNode());
    cIsBallNear->addChild(new EndActNode());
    
    cGuard->setRoot(cIsBallNear);
    
    
    getBrain().addBehavior(*cGuard);
    getBrain().addBehavior(*cMove);
    getBrain().addBehavior(*cGo);
    
}

/**********************************************************************************************
 * function name: GoalKeeper Destructor                                                       *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Nothing.                                                            *
 * *******************************************************************************************/

GoalKeeper::~GoalKeeper() {
    
}
