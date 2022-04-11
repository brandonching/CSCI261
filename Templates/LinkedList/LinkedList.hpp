/** @file LinkedList.hpp
 * @brief Complete class for use of linked list
 *
 * @author Brandon Ching
 *
 * @bug No currently known bugs;
 */

// Libraries
#include <iostream>  // For cin, cout, etc.

#include "Node.hpp"

// Library namespace
using namespace std;

/** @brief Linked List Class*/
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

/** @brief Create new Linked List */
template <typename T>
LinkedList<T>::LinkedList() {
  mpHead = nullptr;
  mpTail = nullptr;
  mSize = 0;
}

/** @brief Copy Constructor
 *
 * @param LinkedList to be copied
 */
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

/** @brief Create a deep copy of list
 *
 * @param LinkedList to be copied
 *
 * @return Deep copy of list
 */
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

/** @brief Deletes LinkedList */
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

/** @brief Create a new node
 *
 * @param Value of the new node
 *
 * @return The new node with Value
 */
template <typename T>
Node<T>* LinkedList<T>::mMakeNodeForValue(const T VALUE) {
  Node<T>* tempNode = new Node<T>;
  tempNode->pNext = nullptr;
  tempNode->value = VALUE;
  return tempNode;
}

/** @brief Add a new node to the front of the list
 *
 * @param Value to be added to the front of list
 */
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

/** @brief Add a new node to the end of the list
 *
 * @param Value to be added to the end of list
 */
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

/** @brief Remove the first value from the lsit
 *
 * @return New List
 */
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

/** @brief get the value of first record
 *
 * @return Value of the front of the list
 */
template <typename T>
T LinkedList<T>::front() {
  if (mSize != 0) {
    return mpHead->value;
  }

  return T();
}

/** @brief get the value of last record
 *
 * @return Value of the back of the list
 */
template <typename T>
T LinkedList<T>::back() {
  if (mpTail->pNext != nullptr) {
    return mpTail->value;
  }
  return T();
}

/** @brief get the current size of linked list
 *
 * @return Size of list
 */
template <typename T>
unsigned int LinkedList<T>::size() const {
  return mSize;
}

/** @brief get the current value in a position
 *
 * @param POS Position of desired value
 *
 * @return Value of POS
 */
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

/** @brief Prints out entire linked list in order with a space between each
 * record*/
template <typename T>
void LinkedList<T>::print() {
  Node<T>* currentNode = mpHead;
  while (currentNode->pNext != nullptr) {
    cout << currentNode->value << " ";
    currentNode = currentNode->pNext;
  }
  cout << currentNode->value;
}