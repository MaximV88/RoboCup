/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

#include "SearchTurnNeckNode.h"
#include "IsTargetVisibleNode.h"
#include "InverterNode.h"
#include "SetTargetToNode.h"
#include "ExecuteActNode.h"
#include "RepeatUntilFailNode.h"
#include "TurnNeckNegativeNode.h"
#include "TurnNeckPositiveNode.h"
#include "TurnNeckToCenterNode.h"
#include "SuccessNode.h"
#include "TurnNode.h"

using namespace behavior;

SearchTurnNeckNode::SearchTurnNeckNode() : InverterNode(new SequenceNode()) {
    
    /************************************************
     * Check if visibile on center, otherwise turn  *
     * to right, check again, and if not turn left. *
     ***********************************************/
    
    //Take the existing child into a pointer
    SequenceNode *cCheckingSequence = static_cast<SequenceNode*>(&getChild());
    
    /*
     * If not visible, we need to continue the sequence,
     * thus we will use an Inverter. The addVisibilityCheck
     * does this process for us.
     */
    
    addVisibilityCheck(cCheckingSequence);
    
    /*
     * If not found, the sequence continues and we need to turn the neck.
     * Need to repeat the positive rotation until maximum, at which it
     * will fail. Thus we need to repeat until fail.
     */

    TurnNeckNegativeNode *cTurnNegative = new TurnNeckNegativeNode();
    
    //Also check visibility at each turn
    addVisibilityCheck(cTurnNegative);
    
    //Repeat the node until it fails
    RepeatUntilFailNode *cRepeatUntilFailNeg = new RepeatUntilFailNode(cTurnNegative);
    
    //Dont want to stop sequence here if found node or just cant proceed - it will always be true
    SuccessNode *cSuccessRepeatNeg = new SuccessNode(cRepeatUntilFailNeg);
    
    cCheckingSequence->addChild(cSuccessRepeatNeg);

    
    /*
     * At this section, we would have already turned the neck
     * to the maximum angle. We need to check again if the 
     * target is visible using an inverter just like before.
     */

    addVisibilityCheck(cCheckingSequence);
    
    
    TurnNeckPositiveNode *cTurnPositive = new TurnNeckPositiveNode();
    
    //Also check visibility at each turn
    addVisibilityCheck(cTurnPositive);
    
    //Repeat the node until it fails
    RepeatUntilFailNode *cRepeatUntilFailPos = new RepeatUntilFailNode(cTurnPositive);
    
    //Dont want to stop sequence here if found node or just cant proceed - it will always be true
    SuccessNode *cSuccessRepeatPos = new SuccessNode(cRepeatUntilFailPos);
    
    cCheckingSequence->addChild(cSuccessRepeatPos);

    /*
     * At this section, we would have already turned the neck
     * to the minimum angle. We need to check again if the
     * target is visible using an inverter just like before.
     */
    
    addVisibilityCheck(cCheckingSequence);
    
    
    /*
     * If the sequence still continues, it means that we
     * havnt found the target. Thus, turn the neck back to
     * the center.
     */

    //The result of this node should be disregarded, thus always succedes
    cCheckingSequence->addChild(new SuccessNode(new TurnNeckToCenterNode()));
    cCheckingSequence->addChild(new ExecuteActNode());
    
}

SearchTurnNeckNode::~SearchTurnNeckNode() {
    
}

void SearchTurnNeckNode::addVisibilityCheck(SequenceNode* cSequence) {

    //Inverts the result of the visibility check so that sequences can be continued
    InverterNode *cInvert = new InverterNode(new IsTargetVisibleNode());
    cSequence->addChild(cInvert);
    
}

