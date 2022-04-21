#ifndef QUEUE_H
#define QUEUE_H

/** @file queue.hpp
 * @brief Complete class for use of a doubly linked list Queues
 *
 * @author Brandon Ching
 *
 * @bug No currently known bugs;
 */

// Libraries
#include <iostream>  // For cin, cout, etc.

#include "DoublyNode.hpp"

// Library namespace
using namespace std;

/** @brief Doubly Linked List Class*/
template <typename T>
class Queue {
 public:
  Queue();
  ~Queue();

  int size() const;

  Queue(const Queue& OTHER);
  Queue& operator=(const Queue& OTHER);

  T get(const int POS) const;
  void push(const T VAL);
  T pop();
  T peak();
  bool isEmpty();

  void print() const;
  void printReverse() const;

 private:
  DoublyNode<T>* mpHead;
  DoublyNode<T>* mpTail;
  unsigned int mSize;
};

/** @brief Create new Doubly Linked List */
template <typename T>
Queue<T>::Queue() {
  mpHead = nullptr;
  mpTail = nullptr;
  mSize = 0;
}

/** @brief Copy Constructor
 *
 * @param Queue to be copied
 */
template <typename T>
Queue<T>::Queue(const Queue<T>& OTHER) {
  mpHead = OTHER.mpHead;
  mpTail = OTHER.mpTail;
  mSize = OTHER.size();
  Queue newList;
  for (unsigned int i = 0; i < OTHER.size(); i++) {
    newList.insert(mSize, OTHER.get(i));
  }
}

/** @brief Create a deep copy of list
 *
 * @param Queue to be copied
 *
 * @return Deep copy of list
 */
template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& OTHER) {
  // Self-asignment
  if (this == &OTHER) {
    return *this;
  }
  // do deep copy
  Queue newList(OTHER);
  swap(newList.mpHead, mpHead);
  swap(newList.mpTail, mpTail);
  swap(newList.mSize, mSize);
  return *this;
}

/** @brief Deletes Queue */
template <typename T>
Queue<T>::~Queue() {
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

/** @brief Create a new node at end of list
 *
 * @param Value of the new node
 *
 */
template <typename T>
void Queue<T>::push(const T VAL) {
  DoublyNode<T>* tempNode = new DoublyNode<T>;
  tempNode->value = VAL;
  if (mSize == 0) {
    mpTail = tempNode;
    mpHead = tempNode;
  } else {
    tempNode->pLast = mpTail;
    mpTail->pNext = tempNode;
    mpTail = tempNode;
  }
  mSize++;
}

/** @brief Prints out entire doublylinked list in order with a space between
 * each record*/
template <typename T>
void Queue<T>::print() const {
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
void Queue<T>::printReverse() const {
  DoublyNode<T>* currentNode = mpTail;
  for (unsigned int i = 0; i < mSize; i++) {
    cout << currentNode->value << " ";
    currentNode = currentNode->pLast;
  }
  cout << endl;
}

/** @brief Removes the tail of the Queue
 */
template <typename T>
T Queue<T>::pop() {
  T popValue = mpHead->value;
  if (mSize <= 1) {
    mpHead = nullptr;
    mpTail = nullptr;
  } else {
    mpHead = mpHead->pNext;
    mpHead->pLast = nullptr;
  }
  mSize--;
  return popValue;
}

/** @brief Get the value of the tail */
template <typename T>
T Queue<T>::peak() {
  return mpHead->value;
}

/** @brief Check if Queue is empty
 */
template <typename T>
bool Queue<T>::isEmpty() {
  if (mSize == 0) {
    return true;
  }
  return false;
}

/** @brief get the current size of doubly linked list
 *
 * @return Size of list
 */
template <typename T>
int Queue<T>::size() const {
  return mSize;
}

/** @brief get the current value in a position
 *
 * @param POS Position of desired value
 *
 * @return Value of POS
 */
template <typename T>
T Queue<T>::get(const int POS) const {
  if ((POS >= 0) && (POS < (signed)mSize)) {
    DoublyNode<T>* currentNode = mpHead;
    for (int i = 0; i < POS; i++) {
      currentNode = currentNode->pNext;
    }
    return currentNode->value;
  }
  return T();
}

#endif