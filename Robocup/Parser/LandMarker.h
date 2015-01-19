//
//  LandMarker.h
//  Robocup
//
//  Created by Maxim Vainshtein on 1/18/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Robocup__LandMarker__
#define __Robocup__LandMarker__

#include <map>
#include "ObservableTypes.h"
#include "Coordinate.h"

namespace landmarks {
    
    class Rectangle {
        
        friend class Flag;
        friend class GoalMouth;
        
    private:
        
        double m_dStartX;
        double m_dStartY;
        double m_dEndX;
        double m_dEndY;
        
    public:
        
        Rectangle(double dStartX, double dStartY, double dEndX, double dEndY) :
        m_dStartX(dStartX), m_dStartY(dStartY), m_dEndX(dEndX), m_dEndY(dEndY) {
            
        }
        
        ~Rectangle() { }
        
        Rectangle percentify(const Rectangle& cRectangle,
                             bool bDoStartX,
                             bool bDoStartY,
                             bool bDoEndX,
                             bool bDoEndY) const {
            
            Rectangle cSource = *this;
            
            if (bDoStartX) {
                
                cSource.m_dStartX *= 0.01;
                cSource.m_dStartX = ( cRectangle.m_dStartX * ( 1 - cSource.m_dStartX ) +
                                     cRectangle.m_dEndX * ( 1 + cSource.m_dStartX ) ) * 0.5;
            }
            if (bDoStartY) {
                
                cSource.m_dStartY *= 0.01;
                cSource.m_dStartY = ( cRectangle.m_dStartY * ( 1 - cSource.m_dStartY ) +
                                     cRectangle.m_dEndY * ( 1 + cSource.m_dStartY ) ) * 0.5;
            }
            if (bDoEndX) {
                
                cSource.m_dEndX *= 0.01;
                cSource.m_dEndX = ( cRectangle.m_dStartX * ( 1 - cSource.m_dEndX ) +
                                   cRectangle.m_dEndX * ( 1 + cSource.m_dEndX ) ) * 0.5;
            }
            if (bDoEndY) {
                
                cSource.m_dEndY *= 0.01;
                cSource.m_dEndY = ( cRectangle.m_dStartY * ( 1 - cSource.m_dEndY ) +
                                   cRectangle.m_dEndY * ( 1 + cSource.m_dEndY ) ) * 0.5;
            }
            
            return cSource;
            
        }
        
    };
    
    class Flag : public Coordinate {
        
    private:

        ObservableType m_eType;
        
    public:
        
        Flag(ObservableType eType, double dValueX, double dValueY) :
        Coordinate(dValueX, dValueY), m_eType(eType) { }
        ~Flag() { }

        Flag percentify(const Rectangle& cRectangle,
                        bool bDoX,
                        bool bDoY) const {
            
            Flag cSource = *this;
            
            if (bDoX)  {
                
                cSource.setX(cSource.getX() * 0.01);
                cSource.setX(( cRectangle.m_dStartX * ( 1 - cSource.getX() ) +
                                     cRectangle.m_dEndX * ( 1 + cSource.getX() ) ) * 0.5);
                
            }
            if (bDoY) {
                
                cSource.setY(cSource.getY() * 0.01);
                cSource.setY(( cRectangle.m_dStartY * ( 1 - cSource.getY() ) +
                                     cRectangle.m_dEndY * ( 1 + cSource.getY() ) ) * 0.5);
                
            }
            
            return cSource;
            
        }
        
        ObservableType getType() const { return m_eType; }

    };
    
    
    class GoalMouth {
        
    private:
        
        double m_dStartY;
        double m_dEndY;
        ObservableType m_eSide;
        
    public:
        
        GoalMouth(ObservableType eSide, double dStartY, double dEndY) :
        m_eSide(eSide), m_dStartY(dStartY), m_dEndY(dEndY) { }
        ~GoalMouth() { }
        
        Rectangle toRect(const Rectangle& cRectangle) const {
            
            Rectangle cSource(0,0,0,0);
            
            if (m_eSide == ObservableTypeGoalLeft) {
                
                cSource.m_dStartX = cSource.m_dEndX = cRectangle.m_dStartX;
                
            }
            else {
                
                cSource.m_dStartX = cSource.m_dEndX = cRectangle.m_dEndX;
                
            }
            
            cSource.m_dStartY = m_dStartY;
            cSource.m_dEndY = m_dEndY;
            
            return cSource;
            
        }
        
    };
    
    class LandMarker {
        
    private:
        
        std::map<ObservableType, const Flag*> m_cReference;
        
        //Rectangle types
        const Rectangle m_cDefaultPitch;
        const Rectangle m_cOuterPitch;
        const Rectangle m_cPenRight;
        const Rectangle m_cPenLeft;
        
        //GoalMouth types
        const GoalMouth m_cGoalMouthRight;
        const GoalMouth m_cGoalMouthLeft;
        
        //Flag types
        const Flag m_cFlagCenter;
        const Flag m_cFlagCenterTop;
        const Flag m_cFlagCenterBottom;
        const Flag m_cFlagRightTop;
        const Flag m_cFlagRightBottom;
        const Flag m_cFlagLeftTop;
        const Flag m_cFlagLeftBottom;
        const Flag m_cFlagGoalRightBottom;
        const Flag m_cGoalRight;
        const Flag m_cFlagGoalRightTop;
        const Flag m_cFlagGoalLeftBottom;
        const Flag m_cGoalLeft;
        const Flag m_cFlagGoalLeftTop;
        const Flag m_cFlagPenRightBottom;
        const Flag m_cFlagPenRightCenter;
        const Flag m_cFlagPenRightTop;
        const Flag m_cFlagPenLeftBottom;
        const Flag m_cFlagPenLeftCenter;
        const Flag m_cFlagPenLeftTop;
        const Flag m_cFlagTop0;
        const Flag m_cFlagTopRight10;
        const Flag m_cFlagTopRight20;
        const Flag m_cFlagTopRight30;
        const Flag m_cFlagTopRight40;
        const Flag m_cFlagTopRight50;
        const Flag m_cFlagTopLeft10;
        const Flag m_cFlagTopLeft20;
        const Flag m_cFlagTopLeft30;
        const Flag m_cFlagTopLeft40;
        const Flag m_cFlagTopLeft50;
        const Flag m_cFlagBottom0;
        const Flag m_cFlagBottomRight10;
        const Flag m_cFlagBottomRight20;
        const Flag m_cFlagBottomRight30;
        const Flag m_cFlagBottomRight40;
        const Flag m_cFlagBottomRight50;
        const Flag m_cFlagBottomLeft10;
        const Flag m_cFlagBottomLeft20;
        const Flag m_cFlagBottomLeft30;
        const Flag m_cFlagBottomLeft40;
        const Flag m_cFlagBottomLeft50;
        const Flag m_cFlagRight0;
        const Flag m_cFlagRightTop10;
        const Flag m_cFlagRightTop20;
        const Flag m_cFlagRightTop30;
        const Flag m_cFlagRightBottom10;
        const Flag m_cFlagRightBottom20;
        const Flag m_cFlagRightBottom30;
        const Flag m_cFlagLeft0;
        const Flag m_cFlagLeftTop10;
        const Flag m_cFlagLeftTop20;
        const Flag m_cFlagLeftTop30;
        const Flag m_cFlagLeftBottom10;
        const Flag m_cFlagLeftBottom20;
        const Flag m_cFlagLeftBottom30;
        
        LandMarker();
        
        LandMarker(LandMarker const& cLandMarker);
        
        void operator=(LandMarker const& cLandMarker);
        
        void initialize();
        
        void addFlag(const Flag& cFlag);
        
    public:
        
        static LandMarker& getInstance();
        
        ~LandMarker();
        
        Coordinate* getOriginByType(ObservableType eType) const;
        
    };
    
}

#endif
