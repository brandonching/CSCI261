#include "LinkedList.hpp"

template <typename T>
void mergeSort(LinkedList<T> *pList, const bool ASC) {
  int startSize = pList->size();
  // base case
  if (startSize <= 1) {
    return;
  }

  // divide and split
  LinkedList<T> *pLeft = new LinkedList<T>;
  LinkedList<T> *pRight = new LinkedList<T>;

  for (int i = 0; i < startSize / 2; i++) {
    pLeft->pushBack(pList->at(0));
    pList->popFront();
  }

  for (unsigned int i = 0; i < startSize - pLeft->size(); i++) {
    pRight->pushBack(pList->at(0));
    pList->popFront();
  }

  // recurse
  mergeSort<T>(pLeft, ASC);
  mergeSort<T>(pRight, ASC);

  // conqur & merge
  while (pLeft->size() != 0 && pRight->size() != 0) {
    if (ASC) {
      if (pLeft->front() < pRight->front()) {
        pList->pushBack(pLeft->front());
        pLeft->popFront();
      } else {
        pList->pushBack(pRight->front());
        pRight->popFront();
      }
    } else {
      if (pLeft->front() > pRight->front()) {
        pList->pushBack(pLeft->front());
        pLeft->popFront();
      } else {
        pList->pushBack(pRight->front());
        pRight->popFront();
      }
    }
  }
  while (pLeft->size() != 0) {
    pList->pushBack(pLeft->front());
    pLeft->popFront();
  }
  while (pRight->size() != 0) {
    pList->pushBack(pRight->front());
    pRight->popFront();
  }
}
