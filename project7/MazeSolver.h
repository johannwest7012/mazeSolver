// File name: MazeSolver.h
// Author: Johann West
// userid: westjs2
// Email: johann.s.west@vanderbilt.edu
// Class: CS2201
// Assignment Number: project 7
// Honor Statement: I pledge on my honor that I have not given nor received unauthorized aid on
//this assignment.
// Description: This is the .h for maze solver
// Last Changed: 4/9/2021

#ifndef MAZESOLVER_H
#define MAZESOLVER_H
#include "PointAgenda.h"
#include "Maze.h"



// TODO -- Your job to fill in this file!
class MazeSolver{
private:
    Maze& theMaze;
    PointAgenda &theAgenda;
    size_t totalCount;
    bool solved;

public:
    //Constructor
    MazeSolver(Maze& newMaze, PointAgenda& newAgenda);

    bool checkIfAvail(Point cur);

    bool searchAndMove();


    //Solve()
    //Solves everything
    bool solve(bool trace);



};


#endif /* ifndef */