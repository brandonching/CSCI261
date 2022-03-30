/* CSCI 261: Assignment 4: Lab 4D - A Linked List Class Part II:
 * Construct/Destruct a List
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description:
 */

// Libraries
#include "LinkedList.h"

#include <iostream>  // For cin, cout, etc.

// Library namespace
using namespace std;

// Constructor
LinkedList::LinkedList() {
  mpHead = nullptr;
  mpTail = nullptr;
  mSize = 0;
}

// Destructor
LinkedList::~LinkedList() {
  Node* tempNode = mpHead;
  while (tempNode != nullptr) {
    Node* tempNext = tempNode->pNext;
    delete tempNode;
    tempNode = tempNext;
  }
  mpHead = nullptr;
  mpTail = nullptr;
  mSize = 0;
}

// mMakeNodeForValue()
Node* LinkedList::mMakeNodeForValue(const int VALUE) {
  Node* tempNode = new Node;
  tempNode->pNext = nullptr;
  tempNode->value = VALUE;
  return tempNode;
}

// pushFront()
void LinkedList::pushFront(const int VALUE) {
  Node* tempNode = new Node;
  tempNode->pNext = mpHead;
  tempNode->value = VALUE;
  mpHead = tempNode;
  mSize++;
  if (mSize == 1) {
    mpTail = mpHead;
  }
}

// pushBack()
void LinkedList::pushBack(const int VALUE) {
  Node* tempNode = new Node;
  tempNode->pNext = nullptr;
  tempNode->value = VALUE;
  if (mpTail != nullptr) {
    mpTail->pNext = tempNode;
  }
  mpTail = tempNode;
  mSize++;
  if (mSize == 1) {
    mpHead = mpTail;
  }
}

// popFront()
int LinkedList::popFront() {
  if (mpHead->pNext != nullptr) {
    Node* tempNode = mpHead;
    mpHead = mpHead->pNext;
    delete tempNode;
    mSize--;
  }
  return -1;
}

// front()
int LinkedList::front() {
  if (mpHead->pNext != nullptr) {
    return mpHead->value;
  }

  return -1;
}

// back()
int LinkedList::back() {
  if (mpTail->pNext != nullptr) {
    return mpTail->value;
  }
  return -1;
}

// size()
unsigned int LinkedList::size() { return mSize; }

// Copy Constructor
LinkedList::LinkedList(LinkedList& other) {
  mSize = other.size();
  LinkedList newList;
  for (unsigned int i = 0; i < other.size(); i++) {
    newList.pushBack(other.at(i));
  }
}

// Copy Assignment Operator
LinkedList& LinkedList::operator=(LinkedList& other) {
  // Self-asignment
  if (this == &other) {
    return *this;
  }
  // do deep copy
  LinkedList newList(other);
  swap(newList.mpHead, mpHead);
  swap(newList.mpTail, mpTail);
  swap(newList.mSize, mSize);
  return *this;
}

// at()
int LinkedList::at(const int POS) {
  if (POS < 0) {
    return -1;
  }
  Node* currentNode = mpHead;
  for (int i = 0; i < POS; i++) {
    currentNode = currentNode->pNext;
    if (currentNode == nullptr) {
      return -1;
    }
  }
  return currentNode->value;
}