#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"

class LinkedList {
 public:
  LinkedList();
  ~LinkedList();

  void pushFront(const int VALUE);
  void pushBack(const int VALUE);
  int popFront();

  int front();
  int back();
  unsigned int size();

  LinkedList(LinkedList &other);
  LinkedList &operator=(LinkedList &other);
  int at(const int POS);

 private:
  Node *mpHead;
  Node *mpTail;
  unsigned int mSize;
  Node *mMakeNodeForValue(const int VALUE);
};

#endif