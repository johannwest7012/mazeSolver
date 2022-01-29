// File name: MazeSolver.cpp
// Author: Johann West
// userid: westjs2
// Email: johann.s.west@vanderbilt.edu
// Class: CS2201
// Assignment Number: project 7
// Honor Statement: I pledge on my honor that I have not given nor received unauthorized aid on
//this assignment.
// Description: This is the .cpp class for mazesolver
// Last Changed: 4/9/2021


// TODO -- Your job to fill in this file!
#include "MazeSolver.h"
//Constructor
MazeSolver::MazeSolver(Maze& newMaze, PointAgenda& newAgenda):
theMaze(newMaze),theAgenda(newAgenda),totalCount(0),solved(false) {

}

//checkIfAvail()
//This function checks if the point is available, i.e in an open spot and within
// the confines of the maze
//pre: current point
//post: bool whether it is available
bool MazeSolver::checkIfAvail(Point cur) {
    if (theMaze.isOpen(cur) && cur.x < theMaze.getNumCols()
        && cur.y < theMaze.getNumRows()) {
        return true;

    }
    else {
        return false;
    }
}

//searchAndMove()
//this function performs the necessary actions of each "step"
//it identifies adjacent points, adds them to the agenda, and removes and marks
//as necessary
//post: bool whether the while loop should stop or not
bool MazeSolver::searchAndMove(){
    if (theAgenda.size() == 0) {
        return true;
    }
    else {

        Point curPoint = theAgenda.peek();
        if (theMaze.hasBeenVisited(curPoint)) {
            //if the spot has already been visited
            theAgenda.remove();
        } else {
            //add the cardinal directions if they qualify
            //mark as visited
            //delete from agenda
            if (curPoint == theMaze.getEndLocation()) {
                std::cout << "("<< curPoint.x << ","<< curPoint.y << ")" << "->" ;
                totalCount++;
                solved = true;
                return true;
            }


            Point north1(curPoint.x, curPoint.y + 1);
            Point east1(curPoint.x + 1, curPoint.y);
            Point south1(curPoint.x, curPoint.y - 1);
            Point west1(curPoint.x - 1, curPoint.y);

            theAgenda.remove();

            if (checkIfAvail(north1)) {
                theAgenda.add(north1);
            }
            if (checkIfAvail(east1)) {
                theAgenda.add(east1);
            }
            if (checkIfAvail(south1)) {
                theAgenda.add(south1);
            }
            if (checkIfAvail(west1)) {
                theAgenda.add(west1);
            }
            std::cout << "("<< curPoint.x << ","<< curPoint.y << ")" << "->" ;
            totalCount++;

            theMaze.markVisited(curPoint);

        }
        return false;
    }
}

//solve()
//The parent function, utilizes the other two helper functions to determine
//if the maze is solveable or not.
//pre: trace
//post: bool whether it is solved or not
bool MazeSolver::solve(bool trace) {
    if (trace){}
    Point curPoint(theMaze.getStartLocation());
    theMaze.markVisited(curPoint);
    totalCount++;
    std::cout << "("<< curPoint.x << ","<< curPoint.y << ")" << "->" ;

    Point north1(curPoint.x,curPoint.y+1);
    Point east1(curPoint.x+1,curPoint.y);
    Point south1(curPoint.x,curPoint.y-1);
    Point west1(curPoint.x-1,curPoint.y);



    if (checkIfAvail(north1)) {
        theAgenda.add(north1);
    }
    if (checkIfAvail(east1)) {
        theAgenda.add(east1);
    }
    if (checkIfAvail(south1)) {
        theAgenda.add(south1);
    }
    if (checkIfAvail(west1)) {
        theAgenda.add(west1);
    }


    bool check = false;
    while (!check) {
        check = searchAndMove();
    }
    if (solved) {
        std::cout << "Solution found!" << std::endl;
    }
    else{
        std::cout << "No Solution found" << std::endl;

    }
    std::cout << "Number of nodes visited: " << totalCount << std::endl;

    return solved;
}

