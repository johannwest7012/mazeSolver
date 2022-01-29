// File name: Point.cpp
// Author: Johann West
// userid: westjs2
// Email: johann.s.west@vanderbilt.edu
// Class: CS2201
// Assignment Number: project 7
// Honor Statement: I pledge on my honor that I have not given nor received unauthorized aid on
//this assignment.
// Description:  Represent a point via x & y coordinates.
// Last Changed: 4/9/2021


#include "Point.h"

// Class Constructor
// post: Initializes x and y to zero
Point::Point(): x(0), y(0)
{}

// Class Constructor
// post: Initializes x and y 
Point::Point(int xVal,int yVal): x(xVal), y(yVal)
{}


// Equality operators
bool Point::operator== (const Point& rhs) const
{
    return (this->x==rhs.x && this->y==rhs.y);
}
bool Point::operator!= (const Point& rhs) const
{
    return !(*this==rhs);
}


// insertion operator for printing a Point
std::ostream & operator<< (std::ostream &out, const Point& p)
{
    out << "(" << p.x << "," << p.y << ")";
    return out;
}

