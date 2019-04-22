#ifndef _DS_AQUEUE_H
#define _DS_AQUEUE_H 1

// First, get the declaration for the base queu class
#include "queue.h"

// This is the declaration for AQueue.
// Array-based queue implementation
template <typename E> 
class AQueue: public Queue<E> {
private:
  int maxSize;               // Maximum size of queue
  int front;                 // Index of front element
  int rear;                  // Index of rear element
  E *listArray;           // Array holding queue elements

public:
  AQueue(int size =defaultSize) {  // Constructor 
    // Make list array one position larger for empty slot
    maxSize = size;
    rear = 0;  front = 0;
    listArray = new E[maxSize];
  }

  ~AQueue() { delete [] listArray; } // Destructor

  void clear() { rear = 0; front = 0; } // Reinitialize

  void enqueue(const E& it) {     // Put "it" in queue
    Assert(((rear+1) % maxSize) != front, "Queue is full");
    listArray[rear] = it;
	rear = (rear+1) % maxSize;       // Circular increment
  }

  E dequeue() {           // Take element out
    Assert(length() != 0, "Queue is empty");
    E it = listArray[front];
    front = (front+1) % maxSize;    // Circular increment
    return it;
  }

  const E& frontValue() const {  // Get front value
    Assert(length() != 0, "Queue is empty");
    return listArray[front];
  }

  virtual int length() const         // Return length
   { return ((rear+maxSize) - front + 1) % maxSize; }
};

#endif 
