//
//  Coordinate.h
//  Ex3
//
//  Created by Maxim Vainshtein on 1/10/15.
//  Copyright (c) 2015 Maxim Vainshtein. All rights reserved.
//

#ifndef __Ex3__Coordinate__
#define __Ex3__Coordinate__

#include <stdio.h>
#include <iostream>

class Coordinate {
    
private:
    
    double m_dValueX;
    double m_dValueY;
    
public:
    
    Coordinate(double dValueX, double dValueY);
    ~Coordinate();
    
    /************************************************************************************
     * function name: getX                                                              *
     * The Input: none                                                                  *
     * The output: double                                                               *
     * The Function Opertion: Returns the X value of the Vector.                        *
     * *********************************************************************************/
    
    double getX() const;
    
    /************************************************************************************
     * function name: getY                                                              *
     * The Input: none                                                                  *
     * The output: double                                                               *
     * The Function Opertion: Returns the Y value of the Vector.                        *
     * *********************************************************************************/
    
    double getY() const;
    
    /************************************************************************************
     * function name: setX                                                              *
     * The Input: double                                                                *
     * The output: none                                                                 *
     * The Function Opertion: Sets the X value of the Vector.                           *
     * *********************************************************************************/
    
    void setX(double dValueX);
    
    /************************************************************************************
     * function name: setY                                                              *
     * The Input: double                                                                *
     * The output: none                                                                 *
     * The Function Opertion: Sets the Y value of the Vector.                           *
     * *********************************************************************************/
    
    void setY(double dValueY);
    
    /************************************************************************************
     * function name: operator<<                                                        *
     * The Input: ostream object (reference), const Vector object (reference)           *
     * The output: ostream object (reference)                                           *
     * The Function Opertion: Prints the Vector to the terminal.                        *
     * *********************************************************************************/
    
    
    
    friend std::ostream& operator<<(std::ostream &out, const Coordinate &cCoordinate);
    
};

#endif
