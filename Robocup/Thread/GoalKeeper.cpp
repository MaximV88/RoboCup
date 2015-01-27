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
            
            getBrain().setBehavior("Guard");
            break;
            
        default:
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
Player(cConnection, chTeamName) {
    
    //Create all behaviors and add them to the brain
    BehaviorTree *cTree = new BehaviorTree(*this, getBrain(), "Guard");
    
    SequenceNode *cStart = new SequenceNode();
    cStart->addChild(new SetTargetToNode(new BehaviorTarget(Coordinate(-50, 0), "GoalKeeper")));
    cStart->addChild(new MoveNode());
    cStart->addChild(new WaitSeeStateUpdateNode());
    cStart->addChild(new EndActNode());
    
    //Add Checking to see if the ball is close
    SequenceNode *cIsBallNear = new SequenceNode();
    cIsBallNear->addChild(new SetTargetToNode(new BehaviorTarget(ObservableTypeBall, "GoalKeeper")));
    cIsBallNear->addChild(new SearchNode());
    cIsBallNear->addChild(new IsCloseToTargetNode(15));
    cIsBallNear->addChild(new DashTowardsTargetNode());
    cIsBallNear->addChild(new KickBallNode());
    cIsBallNear->addChild(new WaitSeeStateUpdateNode());
    cIsBallNear->addChild(new EndActNode());
    
    cStart->addChild(new RepeatUntilFailNode(new SuccessNode(cIsBallNear)));
    
    cTree->setRoot(cStart);
    
    getBrain().addBehavior(*cTree);
    
}

/**********************************************************************************************
 * function name: GoalKeeper Destructor                                                       *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Nothing.                                                            *
 * *******************************************************************************************/

GoalKeeper::~GoalKeeper() {
    
}
