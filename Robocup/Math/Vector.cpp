/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Implementation of Vector Class         *
 ***********************************************************/

#include "Vector.h"

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: Vector Constructor                                                            *
 * The Input: none                                                                              *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object's member varialbes to default values.          *
 * *********************************************************************************************/

Vector::Vector() {
    
    //Assign to 0
    m_dValueX = 0;
    m_dValueY = 0;
    
}

/************************************************************************************************
 * function name: Vector Constructor                                                            *
 * The Input: double, double                                                                    *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with input as X and Y (in this order)          *
 * *********************************************************************************************/

Vector::Vector(double dValueX, double dValueY) {
    
    //Assign to input
    m_dValueX = dValueX;
    m_dValueY = dValueY;
    
}

/************************************************************************************************
 * function name: Vector Copy Constructor                                                       *
 * The Input: const Vector object (reference)                                                   *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object as a copy of the input object.                 *
 * *********************************************************************************************/

Vector::Vector(const Vector& cVector) {
    
    //Assign to input
    m_dValueX = cVector.m_dValueX;
    m_dValueY = cVector.m_dValueY;
    
}

/************************************************************************************************
 * function name: Vector Copy Constructor                                                       *
 * The Input: const Vector object (reference)                                                   *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with input's member variables.                 *
 * *********************************************************************************************/

Vector& Vector::operator=(const Vector &cVector) {
    
    if (this != &cVector) {
        
        //Just copy the types into the member variables
        m_dValueX = cVector.m_dValueX;
        m_dValueY = cVector.m_dValueY;
        
    }
    
    return *this;
    
}

/**********************************************************************************************
 * function name: Vector Destructor                                                           *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Destroys the current object.                                        *
 * *******************************************************************************************/

Vector::~Vector() {
    
}

/************************************************************************************
 * function name: getX                                                              *
 * The Input: none                                                                  *
 * The output: double                                                               *
 * The Function Opertion: Returns a copy of the X value.                            *
 * *********************************************************************************/

double Vector::getX() const {
    
    //Return a copy
    return m_dValueX;
    
}

/************************************************************************************
 * function name: getY                                                              *
 * The Input: none                                                                  *
 * The output: double                                                               *
 * The Function Opertion: Returns a copy of the Y value.                            *
 * *********************************************************************************/

double Vector::getY() const {
    
    //Return a copy
    return m_dValueY;
    
}

/************************************************************************************
 * function name: setX                                                              *
 * The Input: double                                                                *
 * The output: none                                                                 *
 * The Function Opertion: Sets the member variable that holds the X value.          *
 * *********************************************************************************/

void Vector::setX(double dValueX) {
    
    m_dValueX = dValueX;
    
}

/************************************************************************************
 * function name: setY                                                              *
 * The Input: double                                                                *
 * The output: none                                                                 *
 * The Function Opertion: Sets the member variable that holds the Y value.          *
 * *********************************************************************************/

void Vector::setY(double dValueY) {
    
    m_dValueY = dValueY;
    
}

/**********************************************************************************************
 * function name: operator==                                                                  *
 * The Input: const Coordinate object (reference)                                             *
 * The output: bool                                                                           *
 * The Function Opertion: Returns true if the input vector's values match the current object, *
 *                        false otherwise.                                                    *
 * *******************************************************************************************/

bool Vector::operator==(const Vector &cVector) const {
    
    return ((m_dValueX == cVector.m_dValueX) && (m_dValueY == cVector.m_dValueY));

}

/**********************************************************************************************
 * function name: operator!=                                                                  *
 * The Input: const Vector object (reference)                                                 *
 * The output: bool                                                                           *
 * The Function Opertion: Returns false if the input vector's values match the current object,*
 *                        true otherwise.                                                     *
 * *******************************************************************************************/

bool Vector::operator!=(const Vector &cVector) const {
    
    return ((m_dValueX != cVector.m_dValueX) || (m_dValueY != cVector.m_dValueY));
    
}

/**********************************************************************************************
 * function name: operator+                                                                   *
 * The Input: const Vector object (reference)                                                 *
 * The output: const Vector object                                                            *
 * The Function Opertion: Copies the current object into a temporary object, performs the     *
 *                        operator+= on them, and return the temporary object.                *
 * *******************************************************************************************/

const Vector Vector::operator+(const Vector &cVector) const {
    
    //Copy the coordinate
    Vector cResult = *this;
    
    cResult += cVector;
    
    return cResult;
    
}

/**********************************************************************************************
 * function name: operator+=                                                                  *
 * The Input: const Vector object (reference)                                                 *
 * The output: const Vector object                                                            *
 * The Function Opertion: Performs the operator+ on the coordinates of the current            *
 *                        object, with those of the input.                                    *
 * *******************************************************************************************/

Vector& Vector::operator+=(const Vector &cVector) {
    
    //Normal vector math
    m_dValueX += cVector.m_dValueX;
    m_dValueY += cVector.m_dValueY;
    
    return *this;
}

/**********************************************************************************************
 * function name: operator-                                                                   *
 * The Input: const Vector object (reference)                                                 *
 * The output: const Vector object                                                            *
 * The Function Opertion: Copies the current object into a temporary object, performs the     *
 *                        operator-= on them, and return the temporary object.                *
 * *******************************************************************************************/

const Vector Vector::operator-(const Vector &cVector) const {
    
    //Copy the coordinate
    Vector cResult = *this;
    
    cResult -= cVector;
    
    return cResult;
    
}

/**********************************************************************************************
 * function name: operator-=                                                                  *
 * The Input: const Vector object (reference)                                                 *
 * The output: const Vector object                                                            *
 * The Function Opertion: Performs the operator- on the coordinates of the current            *
 *                        object, with those of the input.                                    *
 * *******************************************************************************************/

Vector& Vector::operator-=(const Vector &cVector) {
    
    //Normal vector math
    m_dValueX -= cVector.m_dValueX;
    m_dValueY -= cVector.m_dValueY;
    
    return *this;
}

/************************************************************************************
 * function name: operator<<                                                        *
 * The Input: ostream object (reference), const Vector object (reference)           *
 * The output: ostream object (reference)                                           *
 * The Function Opertion: Performs the operator<< on the ostream object, prints     *
 *                        the X and Y values, and returns the ostream object.       *
 * *********************************************************************************/

std::ostream& operator<< (std::ostream &out, const Vector &cVector) {
    
    out << "(X: " << cVector.m_dValueX << ", Y: " << cVector.m_dValueY << ")";
    return out;
    
}
