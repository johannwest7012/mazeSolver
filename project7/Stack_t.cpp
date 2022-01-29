// File name: Stack_t.cpp
// Author: Johann West
// userid: westjs2
// Email: johann.s.west@vanderbilt.edu
// Class: CS2201
// Assignment Number: project 7
// Honor Statement: I pledge on my honor that I have not given nor received unauthorized aid on
//this assignment.
// Description: This is the .cpp file for the stack class
// Last Changed: 4/9/2021


// TODO -- Your job to fill in this file!

// Ignore the message from CLion telling you this file does not belong to any project target
#include <cstddef>
#include <stdexcept>
#include <string>
#include <iostream>



// TODO
// Define all the methods of the Stack class here


//Default constructor
// Class Constructor
// post: stack is created & initialized to be empty
template <typename ItemType>
Stack<ItemType>::Stack(): numValues(0),head(nullptr) {
}

//Copy ctor
// pre: parameter object, rhs, exists
// post: stack is created to be a copy of the parameter stack
template <typename ItemType>
Stack<ItemType>::Stack(const Stack<ItemType> &rhs): numValues(rhs.numValues),head(nullptr) {
    if (rhs.head != nullptr) {
        head = new Node;
        head->data = rhs.head->data;
        head->next= nullptr;

        NodePtr newPtr = head;
        NodePtr origPtr = rhs.head;
        while (origPtr->next != nullptr) {
            origPtr = origPtr->next;
            newPtr->next=new Node;
            newPtr->data=origPtr->data;
            newPtr->next= nullptr;
        }
    }
}

//Destructor
// pre: the stack exists
// post: the stack is destroyed and any dynamic memory is returned to the system
template <typename ItemType>
Stack<ItemType>::~Stack() {
    while (head != nullptr) {
        NodePtr temp = head;
        head = head->next;
        delete temp;
    }
    numValues = 0;
}

//Assignment operator
// Assigns a stack to another
// pre: both class objects exist
// post: this class object gets assigned a copy of the parameter class object
template <typename ItemType>
const Stack<ItemType> &Stack<ItemType>::operator= (const Stack<ItemType>& rhs) {
    if (this != &rhs) {
        Stack<ItemType> temp(rhs);
        std::swap(head,temp.head);
        std::swap(numValues, temp.numValues);
    }
    return *this;
}


//isEmpty()
// Checks if the stack is empty
// pre:  A stack exists.
// post: Returns true if it IS empty, false if NOT empty.
template <typename ItemType>
bool Stack<ItemType>::isEmpty() const{
    return (numValues == 0);
}


// push
// Pushes an item on top of the stack.
// pre:  Stack exists and item is passed.
// post: the item is placed on top of the stack, and size is incremented.
template <typename ItemType>
void Stack<ItemType>::push(const ItemType& item){
    Node * newItem;
    newItem = new Node;
    newItem->data = item;
    newItem->next= nullptr;
    if (numValues == 0) {
        head = newItem;
        numValues++;
    }
    else {
        NodePtr temp;
        temp = head;
        head = newItem;
        head->next = temp;
        numValues++;
    }
}


// pop
// Pops the top item off the stack.
// pre:  Stack exists.
// post: Removes item on top of stack.  If the stack
//       was already empty, throws a std::underflow_error exception.
template <typename ItemType>
void Stack<ItemType>::pop(){
    if (numValues == 0) {
        throw std::underflow_error("Stack has no values");
    }
    else {
        NodePtr temp = head;
        head = temp->next;
        delete temp;
    }
    numValues--;
}

// top
// Returns the top item of the stack without popping it.
// pre:  Stack exists.
// post: Returns item on top of stack.  If the stack
//       was already empty, throws a std::underflow_error exception.
template <typename ItemType>
ItemType Stack<ItemType>::top() const{
    if (numValues == 0) {
        throw std::underflow_error("Stack is empty");
    }
    else {
        return head->data;
    }
}

// size
// Returns the number of items on the stack.
// post: Returns size from the private section of class.
template <typename ItemType>
size_t Stack<ItemType>::size() const {
    return numValues;
}
template <typename ItemType>
void Stack<ItemType>::doubleEvens(Stack<int> &stack) {
    if(stack.isEmpty()) {
        return;
    }
    else {
        int val = stack.top();
        stack.pop();
        doubleEvens(stack);
        if (val % 2 == 0) {
            stack.push(val);
        }
        stack.push(val);
    }
/*
  if (stack.size() > 0) {
      int temp = stack.top();
      stack.pop();
      doubleEvens(stack);

      if (temp % 2 == 0) {
          stack.push(temp);
      }
      stack.push(temp);
  }
  */

}
