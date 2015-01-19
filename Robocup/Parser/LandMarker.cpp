//
//  LandMarker.cpp
//  Robocup
//
//  Created by Maxim Vainshtein on 1/18/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include <stack>
#include <iostream>
#include "LandMarker.h"

using namespace landmarks;

//Values taken from landmarkreader.cpp in server source code

LandMarker::LandMarker() :
m_cDefaultPitch(-52.5, -34.0, 52.5, 34.0),
m_cOuterPitch(-57.5, -39.0, 57.5, 39.0),
m_cPenRight(36.0, -20.16, 100, 20.16),
m_cPenLeft(-36.0, -20.16, -100, 20.16),
m_cGoalMouthRight(ObservableTypeGoalRight, -7.01, 7.01),
m_cGoalMouthLeft(ObservableTypeGoalLeft, -7.01, 7.01),
m_cFlagCenter(ObservableTypeFlagCenter , 0.0, 0.0),
m_cFlagCenterTop(ObservableTypeFlagCenterTop, 0.0, -100.0),
m_cFlagCenterBottom(ObservableTypeFlagCenterBottom, 0.0, 100.0),
m_cFlagRightTop(ObservableTypeFlagRightTop, 100.0, -100.0),
m_cFlagRightBottom(ObservableTypeFlagRightBottom, 100.0, 100.0),
m_cFlagLeftTop(ObservableTypeFlagLeftTop, -100.0, -100.0),
m_cFlagLeftBottom(ObservableTypeFlagLeftBottom, -100.0, 100.0),
m_cFlagGoalRightBottom(ObservableTypeFlagGoalRightBottom, 0.0, 100.0),
m_cGoalRight(ObservableTypeGoalRight, 0.0, 0.0),
m_cFlagGoalRightTop(ObservableTypeFlagGoalRightTop, 0.0, -100.0),
m_cFlagGoalLeftBottom(ObservableTypeFlagGoalLeftBottom, 0.0, 100.0),
m_cGoalLeft(ObservableTypeGoalLeft, 0.0, 0.0),
m_cFlagGoalLeftTop(ObservableTypeFlagGoalLeftTop, 0.0, -100.0),
m_cFlagPenRightBottom(ObservableTypeFlagPenRightBottom, -100.0, 100.0),
m_cFlagPenRightCenter(ObservableTypeFlagPenRightCenter, -100.0, 0.0),
m_cFlagPenRightTop(ObservableTypeFlagPenRightTop, -100.0, -100.0),
m_cFlagPenLeftBottom(ObservableTypeFlagPenLeftBottom, -100.0, 100.0),
m_cFlagPenLeftCenter(ObservableTypeFlagPenLeftCenter, -100.0, 0.0),
m_cFlagPenLeftTop(ObservableTypeFlagPenLeftTop, -100.0, -100.0),
m_cFlagTop0(ObservableTypeFlagTop0, 0.0, -100.0),
m_cFlagTopRight10(ObservableTypeFlagTopRight10, 10.0, -100.0),
m_cFlagTopRight20(ObservableTypeFlagTopRight20, 20.0, -100.0),
m_cFlagTopRight30(ObservableTypeFlagTopRight30, 30.0, -100.0),
m_cFlagTopRight40(ObservableTypeFlagTopRight40, 40.0, -100.0),
m_cFlagTopRight50(ObservableTypeFlagTopRight50, 50.0, -100.0),
m_cFlagTopLeft10(ObservableTypeFlagTopLeft10, -10.0, -100.0),
m_cFlagTopLeft20(ObservableTypeFlagTopLeft20, -20.0, -100.0),
m_cFlagTopLeft30(ObservableTypeFlagTopLeft30, -30.0, -100.0),
m_cFlagTopLeft40(ObservableTypeFlagTopLeft40, -40.0, -100.0),
m_cFlagTopLeft50(ObservableTypeFlagTopLeft50, -50.0, -100.0),
m_cFlagBottom0(ObservableTypeFlagBottom0, 0.0, 100.0),
m_cFlagBottomRight10(ObservableTypeFlagBottomRight10, 10.0, 100.0),
m_cFlagBottomRight20(ObservableTypeFlagBottomRight20, 20.0, 100.0),
m_cFlagBottomRight30(ObservableTypeFlagBottomRight30, 30.0, 100.0),
m_cFlagBottomRight40(ObservableTypeFlagBottomRight40, 40.0, 100.0),
m_cFlagBottomRight50(ObservableTypeFlagBottomRight50, 50.0, 100.0),
m_cFlagBottomLeft10(ObservableTypeFlagBottomLeft10, -10.0, 100.0),
m_cFlagBottomLeft20(ObservableTypeFlagBottomLeft20, -20.0, 100.0),
m_cFlagBottomLeft30(ObservableTypeFlagBottomLeft30, -30.0, 100.0),
m_cFlagBottomLeft40(ObservableTypeFlagBottomLeft40, -40.0, 100.0),
m_cFlagBottomLeft50(ObservableTypeFlagBottomLeft50, -50.0, 100.0),
m_cFlagRight0(ObservableTypeFlagRight0, 100.0, 0.0),
m_cFlagRightTop10(ObservableTypeFlagRightTop10, 100.0, -10.0),
m_cFlagRightTop20(ObservableTypeFlagRightTop20, 100.0, -20.0),
m_cFlagRightTop30(ObservableTypeFlagRightTop30, 100.0, -30.0),
m_cFlagRightBottom10(ObservableTypeFlagRightBottom10, 100.0, 10.0),
m_cFlagRightBottom20(ObservableTypeFlagRightBottom20, 100.0, 20.0),
m_cFlagRightBottom30(ObservableTypeFlagRightBottom30, 100.0, 30.0),
m_cFlagLeft0(ObservableTypeFlagLeft0, -100.0, 0.0),
m_cFlagLeftTop10(ObservableTypeFlagLeftTop10, -100.0, -10.0),
m_cFlagLeftTop20(ObservableTypeFlagLeftTop20, -100.0, -20.0),
m_cFlagLeftTop30(ObservableTypeFlagLeftTop30, -100.0, -30.0),
m_cFlagLeftBottom10(ObservableTypeFlagLeftBottom10, -100.0, 10.0),
m_cFlagLeftBottom20(ObservableTypeFlagLeftBottom20, -100.0, 20.0),
m_cFlagLeftBottom30(ObservableTypeFlagLeftBottom30, -100.0, 30.0)
{

    //Set the values to the map
    initialize();

}

LandMarker::~LandMarker() {

    for (std::map<ObservableType, const Flag*>::const_iterator iter = m_cReference.begin() ;
         iter != m_cReference.end() ;
         iter++) {
        
        delete (iter->second);
        
    }

}

LandMarker& LandMarker::getInstance() {
    
    static LandMarker instance; // Guaranteed to be destroyed.
    // Instantiated on first use.
    return instance;
    
}

void LandMarker::initialize() {
    
    std::stack<Rectangle> cRectStack;
    
    cRectStack.push(m_cDefaultPitch);
    
    addFlag(m_cFlagCenter.percentify(cRectStack.top(), true, true ));
    addFlag(m_cFlagCenterTop.percentify(cRectStack.top(),true, true ));
    addFlag(m_cFlagCenterBottom.percentify(cRectStack.top(), true, true ));
    addFlag(m_cFlagRightTop.percentify(cRectStack.top(), true, true ) );
    addFlag(m_cFlagRightBottom.percentify(cRectStack.top(), true, true ) );
    addFlag(m_cFlagLeftTop.percentify(cRectStack.top(), true, true ) );
    addFlag(m_cFlagLeftBottom.percentify(cRectStack.top(), true, true ) );
    
    cRectStack.push(m_cGoalMouthRight.toRect(cRectStack.top()));
    
    addFlag(m_cFlagGoalRightBottom.percentify(cRectStack.top(), true, true ) );
    addFlag(m_cGoalRight.percentify(cRectStack.top(), true, true ) );
    addFlag(m_cFlagGoalRightTop.percentify(cRectStack.top(),true, true ) );
    
    cRectStack.pop();
    cRectStack.push(m_cGoalMouthLeft.toRect(cRectStack.top()));
    
    addFlag(m_cFlagGoalLeftBottom.percentify(cRectStack.top(), true, true ) );
    addFlag(m_cGoalLeft.percentify(cRectStack.top(),true, true ) );
    addFlag(m_cFlagGoalLeftTop.percentify(cRectStack.top(), true, true ) );
    
    cRectStack.pop();
    cRectStack.push(m_cPenRight.percentify(cRectStack.top(),false, false, true, false ));
    
    addFlag(m_cFlagPenRightBottom.percentify(cRectStack.top(),true, true ) );
    addFlag(m_cFlagPenRightCenter.percentify(cRectStack.top(),true, true ) );
    addFlag(m_cFlagPenRightTop.percentify(cRectStack.top(), true, true ) );
    
    cRectStack.pop();
    cRectStack.push(m_cPenLeft.percentify( cRectStack.top(),false, false,true, false ) );
    
    addFlag(m_cFlagPenLeftBottom.percentify( cRectStack.top(), true, true ) );
    addFlag(m_cFlagPenLeftCenter.percentify( cRectStack.top(), true, true ) );
    addFlag(m_cFlagPenLeftTop.percentify( cRectStack.top(),true, true ) );
    
    cRectStack.pop();
    cRectStack.push(m_cOuterPitch);
    
    addFlag(m_cFlagTop0.percentify( cRectStack.top(), false, true ) );
    addFlag(m_cFlagTopRight10.percentify( cRectStack.top(),false, true ) );
    addFlag(m_cFlagTopRight20.percentify( cRectStack.top(), false, true ) );
    addFlag(m_cFlagTopRight30.percentify( cRectStack.top(), false, true ) );
    addFlag(m_cFlagTopRight40.percentify( cRectStack.top(), false, true ) );
    addFlag(m_cFlagTopRight50.percentify( cRectStack.top(), false, true ) );
    addFlag(m_cFlagTopLeft10.percentify( cRectStack.top(), false, true ) );
    addFlag(m_cFlagTopLeft20.percentify( cRectStack.top(), false, true ) );
    addFlag(m_cFlagTopLeft30.percentify( cRectStack.top(), false, true ) );
    addFlag(m_cFlagTopLeft40.percentify( cRectStack.top(), false, true ) );
    addFlag(m_cFlagTopLeft50.percentify( cRectStack.top(), false, true ) );
    addFlag(m_cFlagBottom0.percentify( cRectStack.top(), false, true ) );
    addFlag(m_cFlagBottomRight10.percentify( cRectStack.top(), false, true ) );
    addFlag(m_cFlagBottomRight20.percentify( cRectStack.top(), false, true ) );
    addFlag(m_cFlagBottomRight30.percentify( cRectStack.top(), false, true ) );
    addFlag(m_cFlagBottomRight40.percentify( cRectStack.top(), false, true ) );
    addFlag(m_cFlagBottomRight50.percentify( cRectStack.top(), false, true ) );
    addFlag(m_cFlagBottomLeft10.percentify( cRectStack.top(), false, true ) );
    addFlag(m_cFlagBottomLeft20.percentify( cRectStack.top(), false, true ) );
    addFlag(m_cFlagBottomLeft30.percentify( cRectStack.top(), false, true ) );
    addFlag(m_cFlagBottomLeft40.percentify( cRectStack.top(), false, true ) );
    addFlag(m_cFlagBottomLeft50.percentify( cRectStack.top(), false, true ) );
    addFlag(m_cFlagRight0.percentify( cRectStack.top(), true, false ) );
    addFlag(m_cFlagRightTop10.percentify( cRectStack.top(), true, false ) );
    addFlag(m_cFlagRightTop20.percentify( cRectStack.top(), true, false ) );
    addFlag(m_cFlagRightTop30.percentify( cRectStack.top(), true, false ) );
    addFlag(m_cFlagRightBottom10.percentify( cRectStack.top(), true, false ) );
    addFlag(m_cFlagRightBottom20.percentify( cRectStack.top(), true, false ) );
    addFlag(m_cFlagRightBottom30.percentify( cRectStack.top(), true, false ) );
    addFlag(m_cFlagLeft0.percentify( cRectStack.top(), true, false ) );
    addFlag(m_cFlagLeftTop10.percentify( cRectStack.top(), true, false ) );
    addFlag(m_cFlagLeftTop20.percentify( cRectStack.top(), true, false ) );
    addFlag(m_cFlagLeftTop30.percentify( cRectStack.top(), true, false ) );
    addFlag(m_cFlagLeftBottom10.percentify( cRectStack.top(), true, false ) );
    addFlag(m_cFlagLeftBottom20.percentify( cRectStack.top(), true, false ) );
    addFlag(m_cFlagLeftBottom30.percentify( cRectStack.top(), true, false ) );
    
    cRectStack.pop();
    cRectStack.pop();
    
}

void LandMarker::addFlag(const Flag &cFlag) {
    
    //Set each one to the table
    m_cReference[cFlag.getType()] = new Flag(cFlag);
    
}

Coordinate* LandMarker::getOriginByType(ObservableType eType) const {
    
    std::map<ObservableType, const Flag*>::const_iterator iter = m_cReference.find(eType);
    
    //If no flag exists for that key - return nothing
    if (iter == m_cReference.end())
        return NULL;
    else
        return new Coordinate(*iter->second);
        
}
