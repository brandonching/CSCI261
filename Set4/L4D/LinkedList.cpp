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
  for (int n = 0; n <= mSize; n++) {
    Node* currentNode = mpHead;
    for (int i = mSize; i >= 0; i--) {
      currentNode = currentNode->pNext;
    }
    delete currentNode;
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
}

// pushBack()
void LinkedList::pushBack(const int VALUE) {
  Node* tempNode = new Node;
  tempNode->pNext = nullptr;
  tempNode->value = VALUE;
  mpTail->pNext = tempNode;
  mpTail = tempNode;
  mSize++;
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