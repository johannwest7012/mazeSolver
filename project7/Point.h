// File name: Point.h
// Author: CS2201 Instructor
// userid: westjs2
// Email: johann.s.west@vanderbilt.edu
// Class: CS2201
// Assignment Number: project 7
// Honor Statement: I pledge on my honor that I have not given nor received unauthorized aid on
//this assignment.
// Description:  Represent a point via x & y coordinates.
// Last Changed: 4/9/2021

#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
public:
	int x;
	int y;

	// Class Constructor
	// post: Initializes x and y to zero
	Point();

	// Class Constructor
	// post: Initializes x and y
	Point(int x,int y);


	// Equality operators
	bool operator== (const Point& rhs) const;
	bool operator!= (const Point& rhs) const;

};

// insertion operator for output
std::ostream& operator<< (std::ostream& os, const Point &p);

#endif
