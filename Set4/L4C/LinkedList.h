#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"

class LinkedList {
 public:
  void pushFront(int value);
  void pushBack(int value);
  int popFront();

 private:
  Node *pHead;
  Node *pTail;
  unsigned int size;

  Node *makeNodeForValue(int value);
};

#endif