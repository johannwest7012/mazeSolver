// File name: Queue_t.cpp
// Author: Johann West
// userid: westjs2
// Email: johann.s.west@vanderbilt.edu
// Class: CS2201
// Assignment Number: project 7
// Honor Statement: I pledge on my honor that I have not given nor received unauthorized aid on
//this assignment.
// Description: This is the .cpp file for the queue class
// Last Changed: 4/9/2021

// TODO -- Your job to fill in this file!

// Ignore the message from CLion telling you this file does not belong to any project target

#include <cstddef>
#include <stdexcept>
#include <string>
#include <iostream>


//Constructor
template <typename ItemType>
Queue<ItemType>::Queue(): numValues(0), top(nullptr), bottom(nullptr){}

//Copy Constructor
// pre:  Class object, aQueue, exists
// post: Object is initialized to be a copy of the parameter
template <typename ItemType>
Queue<ItemType>::Queue(const Queue<ItemType>& aQueue): numValues(aQueue.numValues),
                                            top(nullptr),bottom(nullptr){
    if (aQueue.top != nullptr) {
        top = new QueueNode;
        top->data = aQueue.top->data;
        top->next = nullptr;

        QueueNodePtr newPtr = top;
        QueueNodePtr origPtr = aQueue.top;
        while (origPtr->next != nullptr) {
            origPtr = origPtr->next;
            newPtr->next = new QueueNode;
            newPtr->data = origPtr->data;
            newPtr->next = nullptr;
            if (origPtr->next->next == nullptr) {
                origPtr = origPtr->next;
                bottom = new QueueNode;
                bottom->data = origPtr->data;
                bottom->next = nullptr;
                break;
            }
        }
    }
}

//Destructor
// Destroys a queue
// pre:  Class object exists
// post: Class object does not exist
template <typename ItemType>
Queue<ItemType>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }

    numValues = 0;
}

//Assignment Operator
// Assigns a queue to another
// pre: both class objects exist
// post: this class object gets assigned a copy of the parameter class object
template <typename ItemType>
const Queue<ItemType> &Queue<ItemType>::operator=(const Queue<ItemType> &rhs) {
    if (this != &rhs) {
        Queue<ItemType> temp(rhs);
        std::swap(top,temp.top);
        std::swap(numValues,temp.numValues);
        std::swap(bottom,temp.bottom);
    }
    return *this;
}


// isEmpty
// Checks if the queue is empty
// pre:  A queue exists.
// post: Returns true if it IS empty, false if NOT empty.
template <typename ItemType>
bool Queue<ItemType>::isEmpty() const {
    return (numValues == 0);
}

// enqueue
// enqueues an item to back of the queue.
// pre:  Queue exists and item is passed.
// post: adds the given item to the end of the queue.
template <typename ItemType>
void Queue<ItemType>::enqueue(const ItemType& item) {
    QueueNode* newItem = new QueueNode;
    newItem->data = item;
    newItem->next = nullptr;
    if (numValues == 0) {
        top = newItem;
        bottom = newItem;
        numValues++;
    }
    else {
        bottom->next = newItem;
        bottom = newItem;
        numValues++;
    }
}

// dequeue
// dequeues the front item off the queue
// pre:  Queue exists.
// post: Removes item on front of the queue. If the queue
//       was already empty, throws an std::underflow_error exception.
template <typename ItemType>
void Queue<ItemType>::dequeue(){
    if (numValues == 0) {
        throw std::underflow_error("Cannot deque an empty que");
    }
    else {
        QueueNodePtr temp;
        temp = top;
        top = top->next;
        delete temp;
        numValues--;
    }
    if (numValues == 0) {
        bottom = nullptr;
    }
}


// front
// Returns the front item of the queue without dequeueing it.
// pre:  Queue exists.
// post: Returns item at front of queue.  If the queue is empty,
//       throws an std::underflow_error exception.
template <typename ItemType>
ItemType Queue<ItemType>::front() const{
    if (numValues == 0) {
        throw std::underflow_error("Queue is empty");
    }
    else {
        return top->data;
    }
}

// size
// Returns the number of items on the queue.
template <typename ItemType>
size_t Queue<ItemType>::size() const {
    return numValues;
}
