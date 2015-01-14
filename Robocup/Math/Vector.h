/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Declaration of Vector Class            *
 ***********************************************************/

#ifndef __Ex3__Vector__
#define __Ex3__Vector__

#include <stdio.h>
#include <iostream>

/*******************************************************************************
 * Vector Class: Represents a Vector that can perform operations with          *
 *               each other.                                                   *
 ******************************************************************************/

class Vector {
    
    //  ---                         PRIVATE FUNCTIONS                       ---   //

    //Represents the X value
    double m_dValueX;
    
    //Represents the Y value
    double m_dValueY;
    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: Vector Constructor                                                            *
     * The Input: none                                                                              *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object.                                               *
     * *********************************************************************************************/
    
    Vector();
    
    /************************************************************************************************
     * function name: Vector Constructor                                                            *
     * The Input: double, double                                                                    *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input as X and Y (in this order)          *
     * *********************************************************************************************/
    
    Vector(double dValueX, double dValueY);
    
    /************************************************************************************************
     * function name: Vector Copy Constructor                                                       *
     * The Input: const Vector object (reference)                                                   *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object.                                               *
     * *********************************************************************************************/
    
    Vector& operator=(const Vector& cVector);

    /**********************************************************************************************
     * function name: Vector Destructor                                                           *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~Vector();
    
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
    
    /**********************************************************************************************
     * function name: operator==                                                                  *
     * The Input: const Vector object (reference)                                                 *
     * The output: bool                                                                           *
     * The Function Opertion: Returns true if the input vector matches the current object,        *
     *                        false otherwise.                                                    *
     * *******************************************************************************************/
    
    bool operator==(const Vector &cVector) const;
    
    /**********************************************************************************************
     * function name: operator!=                                                                  *
     * The Input: const Vector object (reference)                                                 *
     * The output: bool                                                                           *
     * The Function Opertion: Returns false if the input vector matches the current object,       *
     *                        true otherwise.                                                     *
     * *******************************************************************************************/
    
    bool operator!=(const Vector &cVector) const;
    
    /**********************************************************************************************
     * function name: operator+                                                                   *
     * The Input: const Vector object (reference)                                                 *
     * The output: const Vector object                                                            *
     * The Function Opertion: Returns the sum of the input object and current object.             *
     * *******************************************************************************************/

    const Vector operator+(const Vector& cVector) const;
    
    /**********************************************************************************************
     * function name: operator+=                                                                  *
     * The Input: const Vector object (reference)                                                 *
     * The output: const Vector object                                                            *
     * The Function Opertion: Performs the operator+ on the current object.                       *
     * *******************************************************************************************/
    
    Vector& operator+=(const Vector& cVector);

    /**********************************************************************************************
     * function name: operator-                                                                   *
     * The Input: const Vector object (reference)                                                 *
     * The output: const Vector object                                                            *
     * The Function Opertion: Returns the subtraction of the input object and current object.     *
     * *******************************************************************************************/
    
    const Vector operator-(const Vector& cVector) const;
    
    /**********************************************************************************************
     * function name: operator-=                                                                  *
     * The Input: const Vector object (reference)                                                 *
     * The output: const Vector object                                                            *
     * The Function Opertion: Performs the operator- on the current object.                       *
     * *******************************************************************************************/
    
    Vector& operator-=(const Vector& cVector);
    
    /************************************************************************************
     * function name: operator<<                                                        *
     * The Input: ostream object (reference), const Vector object (reference)           *
     * The output: ostream object (reference)                                           *
     * The Function Opertion: Prints the Vector to the terminal.                        *
     * *********************************************************************************/
    
    friend std::ostream& operator<<(std::ostream &out, const Vector &cVector);
    
};

#endif  
