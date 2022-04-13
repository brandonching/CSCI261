/** @file CircularDoublyLinkedList.hpp
 * @brief Complete class for use of a doubly linked list
 *
 * @author Brandon Ching
 *
 * @bug No currently known bugs;
 */

#ifndef CIRCULARDOUBLYLINKEDLIST_H
#define CIRCULARDOUBLYLINKEDLIST_H

// Libraries
#include <iostream>  // For cin, cout, etc.

#include "DoublyNode.hpp"

// Library namespace
using namespace std;

/** @brief Doubly Linked List Class*/
template <typename T>
class CircularDoublyLinkedList {
 public:
  CircularDoublyLinkedList();
  ~CircularDoublyLinkedList();

  int size() const;

  CircularDoublyLinkedList(const CircularDoublyLinkedList& OTHER);
  CircularDoublyLinkedList& operator=(const CircularDoublyLinkedList& OTHER);
  T get(const int POS) const;
  void set(const int POS, const T VAL);
  void insert(const int POS, const T VAL);
  void remove(const int POS);

  void print() const;
  void printReverse() const;

  DoublyNode<T>* getHead() const;
  DoublyNode<T>* getTail() const;
  DoublyNode<T>* getNext(const DoublyNode<T>& CURRENT) const;
  DoublyNode<T>* getLast(const DoublyNode<T>& CURRENT) const;

 private:
  DoublyNode<T>* currentNode;
  DoublyNode<T>* mpHead;
  DoublyNode<T>* mpTail;
  unsigned int mSize;
};

/** @brief Create new Doubly Linked List */
template <typename T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList() {
  mpHead = nullptr;
  mpTail = nullptr;
  mSize = 0;
}

/** @brief Copy Constructor
 *
 * @param DoublyLinkedList to be copied
 */
template <typename T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList(
    const CircularDoublyLinkedList<T>& OTHER) {
  mpHead = OTHER.mpHead;
  mpTail = OTHER.mpTail;
  mSize = OTHER.size();
  CircularDoublyLinkedList newList;
  for (unsigned int i = 0; i < OTHER.size(); i++) {
    newList.insert(mSize, OTHER.get(i));
  }
}

/** @brief Create a deep copy of list
 *
 * @param CircularDoublyLinkedList to be copied
 *
 * @return Deep copy of list
 */
template <typename T>
CircularDoublyLinkedList<T>& CircularDoublyLinkedList<T>::operator=(
    const CircularDoublyLinkedList<T>& OTHER) {
  // Self-asignment
  if (this == &OTHER) {
    return *this;
  }
  // do deep copy
  CircularDoublyLinkedList newList(OTHER);
  swap(newList.mpHead, mpHead);
  swap(newList.mpTail, mpTail);
  swap(newList.mSize, mSize);
  return *this;
}

/** @brief Deletes CircularDoublyLinkedList */
template <typename T>
CircularDoublyLinkedList<T>::~CircularDoublyLinkedList() {
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

/** @brief Create a new node
 *
 * @param POS Position to insert value before
 * @param Value of the new node
 *
 */
template <typename T>
void CircularDoublyLinkedList<T>::insert(const int POS, const T VAL) {
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
    tempNode->pNext = mpHead;
    mpHead->pLast = tempNode;
    mpTail->pNext = tempNode;
    mpTail = tempNode;
  }
  mSize++;
}

/** @brief Prints out entire doublylinked list in order with a space between
 * each record*/
template <typename T>
void CircularDoublyLinkedList<T>::print() const {
  DoublyNode<T>* currentNode = mpHead;
  for (unsigned int i = 0; i < mSize; i++) {
    cout << currentNode->value << " ";
    currentNode = currentNode->pNext;
  }
  cout << endl;
}

/** @brief Prints out entire doubly linked list backward with a space between
 * each record*/
template <typename T>
void CircularDoublyLinkedList<T>::printReverse() const {
  DoublyNode<T>* currentNode = mpTail;
  for (unsigned int i = 0; i < mSize; i++) {
    cout << currentNode->value << " ";
    currentNode = currentNode->pLast;
  }
  cout << endl;
}

/** @brief Set the value to exisiting node to new value
 *
 * @param POS Position to node to be changed
 * @param Value New value of node
 *
 */
template <typename T>
void CircularDoublyLinkedList<T>::set(const int POS, const T VAL) {
  if ((POS >= 0) && (POS < (signed)mSize)) {
    DoublyNode<T>* currentNode = mpHead;
    for (int i = 0; i < POS; i++) {
      currentNode = currentNode->pNext;
    }
    currentNode->value = VAL;
  }
}

/** @brief Removes a node from doubly linked list
 *
 * @param POS Position of node to be removed. If POS is out of range, the
 * first/last nodes will be removed
 *
 */
template <typename T>
void CircularDoublyLinkedList<T>::remove(const int POS) {
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

/** @brief get the current size of doubly linked list
 *
 * @return Size of list
 */
template <typename T>
int CircularDoublyLinkedList<T>::size() const {
  return mSize;
}

/** @brief get the current value in a position
 *
 * @param POS Position of desired value
 *
 * @return Value of POS
 */
template <typename T>
T CircularDoublyLinkedList<T>::get(const int POS) const {
  if ((POS >= 0) && (POS < (signed)mSize)) {
    DoublyNode<T>* currentNode = mpHead;
    for (int i = 0; i < POS; i++) {
      currentNode = currentNode->pNext;
    }
    return currentNode->value;
  }
  return T();
}

/** @brief get the memory adress of the head
 *
 * @return Memory adress of head */
template <typename T>
DoublyNode<T>* CircularDoublyLinkedList<T>::getHead() const {

  return mpHead;
}

/** @brief get the memory adress of the tail
 *
 * @return Memory adress of tail */
template <typename T>
DoublyNode<T>* CircularDoublyLinkedList<T>::getTail() const {
  return *mpTail;
}
template <typename T>
DoublyNode<T>* CircularDoublyLinkedList<T>::getNext(
    const DoublyNode<T>& CURRENT) const {
  return *CURRENT.pNext->value;
}

template <typename T>
DoublyNode<T>* CircularDoublyLinkedList<T>::getLast(
    const DoublyNode<T>& CURRENT) const {
  return *CURRENT.pLast->value;
}

#endif