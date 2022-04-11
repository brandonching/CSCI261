/* CSCI 261: Assignment 5: Lab 5D - Sorting II & Recursion II: Merge Sort via
 * the Call Stack
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description: Sorting a list via merge sort
 */

// Libraries
#include <iostream>  // For cin, cout, etc.

#include "Node.hpp"

// Library namespace
using namespace std;

template <typename T>
class LinkedList {
 public:
  LinkedList();
  ~LinkedList();

  void pushFront(const T VALUE);
  void pushBack(const T VALUE);
  T popFront();

  T front();
  T back();
  unsigned int size() const;

  LinkedList(const LinkedList& OTHER);
  LinkedList& operator=(const LinkedList& OTHER);
  T at(const int POS) const;

  void print();

 private:
  Node<T>* mpHead;
  Node<T>* mpTail;
  unsigned int mSize;
  Node<T>* mMakeNodeForValue(const T VALUE);
};

// Constructor
template <typename T>
LinkedList<T>::LinkedList() {
  mpHead = nullptr;
  mpTail = nullptr;
  mSize = 0;
}
// Copy Constructor
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& OTHER) {
  mpHead = OTHER.mpHead;
  mpTail = OTHER.mpTail;
  mSize = OTHER.size();
  LinkedList newList;
  for (unsigned int i = 0; i < OTHER.size(); i++) {
    newList.pushBack(OTHER.at(i));
  }
}

// Copy Assignment Operator
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& OTHER) {
  // Self-asignment
  if (this == &OTHER) {
    return *this;
  }
  // do deep copy
  LinkedList newList(OTHER);
  swap(newList.mpHead, mpHead);
  swap(newList.mpTail, mpTail);
  swap(newList.mSize, mSize);
  return *this;
}

// Destructor
template <typename T>
LinkedList<T>::~LinkedList() {
  Node<T>* tempNode = mpHead;
  while (tempNode != nullptr) {
    Node<T>* tempNext = tempNode->pNext;
    delete tempNode;
    tempNode = tempNext;
  }
  mpHead = nullptr;
  mpTail = nullptr;
  mSize = 0;
}

// mMakeNodeForValue()
template <typename T>
Node<T>* LinkedList<T>::mMakeNodeForValue(const T VALUE) {
  Node<T>* tempNode = new Node<T>;
  tempNode->pNext = nullptr;
  tempNode->value = VALUE;
  return tempNode;
}

// pushFront()
template <typename T>
void LinkedList<T>::pushFront(const T VALUE) {
  Node<T>* tempNode = new Node<T>;
  tempNode->pNext = mpHead;
  tempNode->value = VALUE;
  mpHead = tempNode;
  mSize++;
  if (mSize == 1) {
    mpTail = mpHead;
  }
}

// pushBack()
template <typename T>
void LinkedList<T>::pushBack(const T VALUE) {
  Node<T>* tempNode = new Node<T>;
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
template <typename T>
T LinkedList<T>::popFront() {
  if (mSize != 0) {
    Node<T>* tempNode = mpHead;
    mpHead = mpHead->pNext;
    delete tempNode;
    mSize--;
  }
  return T();
}

// front()
template <typename T>
T LinkedList<T>::front() {
  if (mSize != 0) {
    return mpHead->value;
  }

  return T();
}

// back()
template <typename T>
T LinkedList<T>::back() {
  if (mpTail->pNext != nullptr) {
    return mpTail->value;
  }
  return T();
}

// size()
template <typename T>
unsigned int LinkedList<T>::size() const {
  return mSize;
}

// at()
template <typename T>
T LinkedList<T>::at(const int POS) const {
  if (POS < 0) {
    return T();
  }
  Node<T>* currentNode = mpHead;
  for (int i = 0; i < POS; i++) {
    currentNode = currentNode->pNext;
    if (currentNode == nullptr) {
      return T();
    }
  }
  return currentNode->value;
}

// print()
template <typename T>
void LinkedList<T>::print() {
  Node<T>* currentNode = mpHead;
  while (currentNode->pNext != nullptr) {
    cout << currentNode->value << " ";
    currentNode = currentNode->pNext;
  }
  cout << currentNode->value;
}