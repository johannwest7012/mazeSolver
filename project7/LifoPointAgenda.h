// File name: LifoPointAgenda.h
// Author: 
// userid: 
// Email: 
// Class: 
// Assignment Number:
// Honor Statement:
// Description:  
// Last Changed: 


#ifndef LifoPointAgenda_H
#define LifoPointAgenda_H
#include "PointAgenda.h"
#include "Stack_t.h"


// TODO -- Your job to fill in this file!
class LifoPointAgenda : public PointAgenda {

private:
    Stack<Point> Lifo;

public:

    // virtual Class Destructor
    virtual ~LifoPointAgenda() {}

    // isEmpty (pure virtual)
    // Checks if the agenda is empty
    virtual bool isEmpty() const{return Lifo.isEmpty();}


    // add (pure virtual)
    // adds a Point to the agenda.
    virtual void add(const Point& item){Lifo.push(item);}

    // remove (pure virtual)
    // removes the next Point from the agenda.
    virtual void remove(){Lifo.pop();}

    // peek (pure virtual)
    // Returns the next Point from the agenda without removing it from the agenda.
    virtual Point peek() const{return Lifo.top();}

    // size (pure virtual)
    // Returns the number of Points in the agenda.
    virtual size_t size() const{return Lifo.size();}


};

#endif


