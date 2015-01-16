//
//  ChangeViewNode.cpp
//  Ex3
//
//  Created by Maxim Vainshtein on 1/10/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "ChangeViewNode.h"
#include "Brain.h"
#include "Player.h"

#define CHANGE_VIEW_NODE_COMMAND "change_view"
#define CHANGE_VIEW_NODE_TARGET_ERROR "ChangeViewNode Error: No Target given"
#define CHANGE_VIEW_NODE_WIDTH_ERROR "ChangeViewNode Error: No Width type given in the Target"
#define CHANGE_VIEW_NODE_QUALITY_ERROR "ChangeViewNode Error: No Quality type given in the Target"

#define CHANGE_VIEW_NODE_WIDTH_TYPE_NARROW "narrow"
#define CHANGE_VIEW_NODE_WIDTH_TYPE_NORMAL "normal"
#define CHANGE_VIEW_NODE_WIDTH_TYPE_WIDE "wide"

#define CHANGE_VIEW_NODE_QUALITY_TYPE_HIGH "high"
#define CHANGE_VIEW_NODE_QUALITY_TYPE_LOW "low"

using namespace behavior;

ChangeViewNode::ChangeViewNode() {
    
}

ChangeViewNode::~ChangeViewNode() {
    
}

StatusType ChangeViewNode::process() {
    
    //Add the required input from the target
    BehaviorTarget *cTarget = getContext().getCurrentTarget();
    
    //If no target is present, return failed
    if (cTarget == NULL) {
        
        std::cerr << CHANGE_VIEW_NODE_TARGET_ERROR << std::endl;
        return StatusTypeFailure;
        
    }
    
    //Check if our target has an origin to move to
    const WidthType *eWidthType = cTarget->getWidthTypeValue();
    
    //If no coordinate is given, return failed
    if (eWidthType == NULL) {
        
        std::cerr << CHANGE_VIEW_NODE_WIDTH_ERROR << std::endl;
        return StatusTypeFailure;
        
    }
    
    //Check if our target has an origin to move to
    const QualityType *eQualityType = cTarget->getQualityTypeValue();
    
    //If no coordinate is given, return failed
    if (eQualityType == NULL) {
        
        std::cerr << CHANGE_VIEW_NODE_QUALITY_ERROR << std::endl;
        return StatusTypeFailure;
        
    }
    
    //Check if there is need to perform an instruction (settings already set)
    const BodyState* cBody = getContext().getPlayer().getLastBodyState();

    //Fail quietly
    if (cBody == NULL)
        return StatusTypeFailure;
        
    
    if (cBody->viewModeWidth == *eWidthType && cBody->viewModeQuality == *eQualityType) {
        
        //No need to proceed
        return StatusTypeSuccess;
        
    }
    
    
    //Construct the instruction and send it to the brain
    Instruction *cInstruction = new Instruction();
    
    //Add the required input
    cInstruction->addCommand(CHANGE_VIEW_NODE_COMMAND);
    
    //According to input type
    switch (*eWidthType) {
        case WidthTypeNarrow:
            cInstruction->addCommand(CHANGE_VIEW_NODE_WIDTH_TYPE_NARROW);
            break;
        case WidthTypeNormal:
            cInstruction->addCommand(CHANGE_VIEW_NODE_WIDTH_TYPE_NORMAL);
            break;
        case WidthTypeWide:
            cInstruction->addCommand(CHANGE_VIEW_NODE_WIDTH_TYPE_WIDE);
            break;
            
            //Shouldnt reach here
        default:
            break;
    }
    
    //According to input type
    switch (*eQualityType) {
        case QualityTypeLow:
            cInstruction->addCommand(CHANGE_VIEW_NODE_QUALITY_TYPE_LOW);
            break;
        case QualityTypeHigh:
            cInstruction->addCommand(CHANGE_VIEW_NODE_QUALITY_TYPE_HIGH);
            break;
            
            //Shouldnt reach here
        default:
            break;
    }
    
    //Can be attached to other instructions (not unique per cycle)
    cInstruction->setAttachable(true);
    
    //Send the instruction to the brain
    perform(*cInstruction);
    
    return StatusTypeSuccess;
    
}
