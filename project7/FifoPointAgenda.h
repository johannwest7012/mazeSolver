// File name: FifoPointAgenda.h
// Author: 
// userid: 
// Email: 
// Class: 
// Assignment Number:
// Honor Statement:
// Description:  
// Last Changed: 


#ifndef FifoPointAgenda_H
#define FifoPointAgenda_H
#include "PointAgenda.h"
#include "Queue_t.h"

// TODO -- Your job to fill in this file!

class FifoPointAgenda : public PointAgenda {

private:
    Queue<Point> Fifo;

public:

    // virtual Class Destructor
    virtual ~FifoPointAgenda() {}

    // isEmpty (pure virtual)
    // Checks if the agenda is empty
    virtual bool isEmpty() const{return Fifo.isEmpty();}


    // add (pure virtual)
    // adds a Point to the agenda.
    virtual void add(const Point& item){Fifo.enqueue(item);}

    // remove (pure virtual)
    // removes the next Point from the agenda.
    virtual void remove(){Fifo.dequeue();}

    // peek (pure virtual)
    // Returns the next Point from the agenda without removing it from the agenda.
    virtual Point peek() const{return Fifo.front();}

    // size (pure virtual)
    // Returns the number of Points in the agenda.
    virtual size_t size() const{return Fifo.size();}


};


#endif

