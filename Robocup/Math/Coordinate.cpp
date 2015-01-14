//
//  Coordinate.cpp
//  Ex3
//
//  Created by Maxim Vainshtein on 1/10/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#include "Coordinate.h"

Coordinate::Coordinate(double dValueX, double dValueY) {
    
    m_dValueX = dValueX;
    m_dValueY = dValueY;
    
}

Coordinate::~Coordinate() {
    
}

/************************************************************************************
 * function name: getX                                                              *
 * The Input: none                                                                  *
 * The output: double                                                               *
 * The Function Opertion: Returns a copy of the X value.                            *
 * *********************************************************************************/

double Coordinate::getX() const {
    
    //Return a copy
    return m_dValueX;
    
}

/************************************************************************************
 * function name: getY                                                              *
 * The Input: none                                                                  *
 * The output: double                                                               *
 * The Function Opertion: Returns a copy of the Y value.                            *
 * *********************************************************************************/

double Coordinate::getY() const {
    
    //Return a copy
    return m_dValueY;
    
}

/************************************************************************************
 * function name: setX                                                              *
 * The Input: double                                                                *
 * The output: none                                                                 *
 * The Function Opertion: Sets the member variable that holds the X value.          *
 * *********************************************************************************/

void Coordinate::setX(double dValueX) {
    
    m_dValueX = dValueX;
    
}

/************************************************************************************
 * function name: setY                                                              *
 * The Input: double                                                                *
 * The output: none                                                                 *
 * The Function Opertion: Sets the member variable that holds the Y value.          *
 * *********************************************************************************/

void Coordinate::setY(double dValueY) {
    
    m_dValueY = dValueY;
    
}
