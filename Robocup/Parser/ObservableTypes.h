//
//  ObservableTypes.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/18/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef Robocup_ObservableTypes_h
#define Robocup_ObservableTypes_h

class Rectangle;
class Flag;
class GoalMouth;

typedef enum {
    
    ObservableTypeFlagCenter = 0,
    ObservableTypeFlagCenterTop,
    ObservableTypeFlagCenterBottom,
    ObservableTypeFlagLeftTop,
    ObservableTypeFlagLeftTop30,
    ObservableTypeFlagLeftTop20,
    ObservableTypeFlagLeftTop10,
    ObservableTypeFlagLeftBottom,
    ObservableTypeFlagLeftBottom30,
    ObservableTypeFlagLeftBottom20,
    ObservableTypeFlagLeftBottom10,
    ObservableTypeFlagRightTop,
    ObservableTypeFlagRightTop30,
    ObservableTypeFlagRightTop20,
    ObservableTypeFlagRightTop10,
    ObservableTypeFlagRightBottom,
    ObservableTypeFlagRightBottom30,
    ObservableTypeFlagRightBottom20,
    ObservableTypeFlagRightBottom10,
    ObservableTypeFlagPenLeftTop,
    ObservableTypeFlagPenLeftCenter,
    ObservableTypeFlagPenLeftBottom,
    ObservableTypeFlagPenRightTop,
    ObservableTypeFlagPenRightCenter,
    ObservableTypeFlagPenRightBottom,
    ObservableTypeFlagGoalLeftTop,
    ObservableTypeFlagGoalLeftBottom,
    ObservableTypeFlagGoalRightTop,
    ObservableTypeFlagGoalRightBottom,
    ObservableTypeGoalLeft,
    ObservableTypeGoalRight,
    ObservableTypeFlagLeft0,
    ObservableTypeFlagRight0,
    ObservableTypeFlagTop0,
    ObservableTypeFlagBottom0,
    ObservableTypeFlagTopLeft50,
    ObservableTypeFlagTopLeft40,
    ObservableTypeFlagTopLeft30,
    ObservableTypeFlagTopLeft20,
    ObservableTypeFlagTopLeft10,
    ObservableTypeFlagTopRight50,
    ObservableTypeFlagTopRight40,
    ObservableTypeFlagTopRight30,
    ObservableTypeFlagTopRight20,
    ObservableTypeFlagTopRight10,
    ObservableTypeFlagBottomLeft50,
    ObservableTypeFlagBottomLeft40,
    ObservableTypeFlagBottomLeft30,
    ObservableTypeFlagBottomLeft20,
    ObservableTypeFlagBottomLeft10,
    ObservableTypeFlagBottomRight50,
    ObservableTypeFlagBottomRight40,
    ObservableTypeFlagBottomRight30,
    ObservableTypeFlagBottomRight20,
    ObservableTypeFlagBottomRight10,
    ObservableTypeLineTop = 1000,
    ObservableTypeLineBottom,
    ObservableTypeLineRight,
    ObservableTypeLineLeft,
    ObservableTypeBall,
    ObservableTypePlayer,
    ObservableTypeGoal,
    ObservableTypeFlag,
    ObservableTypeNone
    
} ObservableType;

typedef enum {
    
    ObservablePropertyTypeDirection = 1,
    ObservablePropertyTypeDistance,
    ObservablePropertyTypeDistChange,
    ObservablePropertyTypeDirectionChange,
    ObservablePropertyTypeBodyFacingDirection,
    ObservablePropertyTypeHeadFacingDirection
    
} ObservablePropertyType;

#endif
