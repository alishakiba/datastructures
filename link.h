#ifndef _DS_LINK_H
#define _DS_LINK_H 1

#include "definitions.h"

// Singly linked list node
template <typename E> 
class Link {
public:
  E element;      // Value for this node
  Link *next;        // Pointer to next node in list
  // Constructors
  Link(const E& elemval, Link* nextval =NULL)
    { element = elemval;  next = nextval; }
  Link(Link* nextval =NULL) { next = nextval; }
};

#endif 
