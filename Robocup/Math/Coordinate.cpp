/************************************************************
 * Student Name:     TreeBots                               *
 * Exercise Name:    Ex6                                    *
 * File description: Implementation of Nameable Class       *
 ***********************************************************/

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

/************************************************************************************
 * function name: operator<<                                                        *
 * The Input: ostream object (reference), const Vector object (reference)           *
 * The output: ostream object (reference)                                           *
 * The Function Opertion: Performs the operator<< on the ostream object, prints     *
 *                        the X and Y values, and returns the ostream object.       *
 * *********************************************************************************/

std::ostream& operator<< (std::ostream &out, const Coordinate &cCoordinate) {
    
    out << "(X: " << cCoordinate.m_dValueX << ", Y: " << cCoordinate.m_dValueY << ")";
    return out;
    
}
