// Libraries
#include <iostream>  // For cin, cout, etc.

#include "Structs.hpp"

// Library namespace
using namespace std;

template <typename T>
class LinkedList {
 public:
  LinkedList();
  ~LinkedList();

  void pushBack(const T VALUE);
  unsigned int size() const;

  LinkedList(const LinkedList& OTHER);
  T at(const int POS) const;

 private:
  Node<T>* mpHead;
  Node<T>* mpTail;
  unsigned int mSize;
};

// Constructor
template <typename T>
LinkedList<T>::LinkedList() {
  mpHead = nullptr;
  mpTail = nullptr;
  mSize = 0;
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