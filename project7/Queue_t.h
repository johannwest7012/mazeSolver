// File name: Queue_t.h
// Author: Johann West
// userid: westjs2
// Email: johann.s.west@vanderbilt.edu
// Class: CS2201
// Assignment Number: project 7
// Honor Statement: I pledge on my honor that I have not given nor received unauthorized aid on
//this assignment.
// Description: This is the .h file for the queue class
// Last Changed: 4/9/2021


#ifndef QUEUE_T_H
#define QUEUE_T_H

// TODO -- Your job to fill in this file!



#include <cstddef>   // make gcc & CLion happy

template <typename ItemType>

class Queue
{
private:

    struct QueueNode
    {
        ItemType data;
        QueueNode *next;
    };

    typedef QueueNode* QueueNodePtr;

    size_t numValues;
    QueueNodePtr top;
    QueueNodePtr bottom;





    // TODO -- your job to define


public:
    // Class Constructor
    Queue();

    // Copy Constructor
    // pre:  Class object, aQueue, exists
    // post: Object is initialized to be a copy of the parameter
    Queue(const Queue& aQueue);

    // Class Destructor
    // Destroys a queue
    // pre:  Class object exists
    // post: Class object does not exist
    ~Queue();

    // Assignment operator
    // Assigns a queue to another
    // pre: both class objects exist
    // post: this class object gets assigned a copy of the parameter class object
    const Queue& operator= (const Queue& rhs);

    // isEmpty
    // Checks if the queue is empty
    // pre:  A queue exists.
    // post: Returns true if it IS empty, false if NOT empty.
    bool isEmpty() const;

    // enqueue
    // enqueues an item to back of the queue.
    // pre:  Queue exists and item is passed.
    // post: adds the given item to the end of the queue.
    void enqueue(const ItemType& item);

    // dequeue
    // dequeues the front item off the queue
    // pre:  Queue exists.
    // post: Removes item on front of the queue. If the queue
    //       was already empty, throws an std::underflow_error exception.
    void dequeue();

    // front
    // Returns the front item of the queue without dequeueing it.
    // pre:  Queue exists.
    // post: Returns item at front of queue.  If the queue is empty,
    //       throws an std::underflow_error exception.
    ItemType front() const;

    // size
    // Returns the number of items on the queue.
    size_t size() const;

};


#include "Queue_t.cpp"

#endif
