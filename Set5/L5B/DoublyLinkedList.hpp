/* CSCI 261: Assignment 5: Lab 5A - Double The Fun
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description: working with doubly-linked lsit
 */

// Libraries
#include <iostream>  // For cin, cout, etc.

#include "DoublyNode.hpp"

// Library namespace
using namespace std;

template <typename T>
class DoublyLinkedList {
 public:
  DoublyLinkedList();
  ~DoublyLinkedList();

  int size() const;

  DoublyLinkedList(const DoublyLinkedList& OTHER);
  DoublyLinkedList& operator=(const DoublyLinkedList& OTHER);
  T get(const int POS) const;
  void set(const int POS, const T VAL);
  void insert(const int POS, const T VAL);
  void remove(const int POS);

  void print() const;
  void printReverse() const;

 private:
  DoublyNode<T>* mpHead;
  DoublyNode<T>* mpTail;
  unsigned int mSize;
};

// Constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
  mpHead = nullptr;
  mpTail = nullptr;
  mSize = 0;
}

// Copy Constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& OTHER) {
  mpHead = OTHER.mpHead;
  mpTail = OTHER.mpTail;
  mSize = OTHER.size();
  DoublyLinkedList newList;
  for (unsigned int i = 0; i < OTHER.size(); i++) {
    newList.insert(mSize, OTHER.get(i));
  }
}

// Copy Assignment Operator
template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(
    const DoublyLinkedList<T>& OTHER) {
  // Self-asignment
  if (this == &OTHER) {
    return *this;
  }
  // do deep copy
  DoublyLinkedList newList(OTHER);
  swap(newList.mpHead, mpHead);
  swap(newList.mpTail, mpTail);
  swap(newList.mSize, mSize);
  return *this;
}

// Destructor
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
  DoublyNode<T>* tempNode = mpHead;
  while (tempNode != nullptr) {
    DoublyNode<T>* tempNext = tempNode->pNext;
    delete tempNode;
    tempNode = tempNext;
  }
  mpHead = nullptr;
  mpTail = nullptr;
  mSize = 0;
}

// Insert
template <typename T>
void DoublyLinkedList<T>::insert(const int POS, const T VAL) {
  DoublyNode<T>* tempNode = new DoublyNode<T>;
  tempNode->value = VAL;
  if (mSize == 0) {
    mpTail = tempNode;
    mpHead = tempNode;
  } else if (POS <= 0) {
    tempNode->pNext = mpHead;
    mpHead->pLast = tempNode;
    mpHead = tempNode;
  } else if (POS < (signed)mSize) {
    DoublyNode<T>* currentNode = mpHead;
    for (int i = 0; i < POS; i++) {
      currentNode = currentNode->pNext;
    }
    tempNode->pNext = currentNode;
    tempNode->pLast = currentNode->pLast;
    currentNode->pLast = tempNode;
    tempNode->pLast->pNext = tempNode;
  } else {
    tempNode->pLast = mpTail;
    mpTail->pNext = tempNode;
    mpTail = tempNode;
  }
  mSize++;
}

// Print List Forward
template <typename T>
void DoublyLinkedList<T>::print() const {
  DoublyNode<T>* currentNode = mpHead;
  for (unsigned int i = 0; i < mSize; i++) {
    cout << currentNode->value << " ";
    currentNode = currentNode->pNext;
  }
  cout << endl;
}

// Print List Backwards
template <typename T>
void DoublyLinkedList<T>::printReverse() const {
  DoublyNode<T>* currentNode = mpTail;
  for (unsigned int i = 0; i < mSize; i++) {
    cout << currentNode->value << " ";
    currentNode = currentNode->pLast;
  }
  cout << endl;
}

// set()
template <typename T>
void DoublyLinkedList<T>::set(const int POS, const T VAL) {
  if ((POS >= 0) && (POS < (signed)mSize)) {
    DoublyNode<T>* currentNode = mpHead;
    for (int i = 0; i < POS; i++) {
      currentNode = currentNode->pNext;
    }
    currentNode->value = VAL;
  }
}

// remove()
template <typename T>
void DoublyLinkedList<T>::remove(const int POS) {
  if (POS <= 0) {
    mpHead = mpHead->pNext;
    mpHead->pLast = nullptr;
  } else if (POS >= (signed)mSize) {
    mpTail = mpTail->pLast;
    mpTail->pNext = nullptr;
  } else {
    DoublyNode<T>* currentNode = mpHead;
    for (int i = 0; i < POS; i++) {
      currentNode = currentNode->pNext;
    }
    currentNode->pLast->pNext = currentNode->pNext;
    currentNode->pNext->pLast = currentNode->pLast;
  }
  mSize--;
}

// size()
template <typename T>
int DoublyLinkedList<T>::size() const {
  return mSize;
}

// get()
template <typename T>
T DoublyLinkedList<T>::get(const int POS) const {
  if ((POS >= 0) && (POS < (signed)mSize)) {
    DoublyNode<T>* currentNode = mpHead;
    for (int i = 0; i < POS; i++) {
      currentNode = currentNode->pNext;
    }
    return currentNode->value;
  }
  return -1;
}