/* CSCI 261: Assignment 5: Lab 5D - Sorting II & Recursion II: Merge Sort via
 the Call Stack
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description: sorting list
 */

// Libraries
#include <iostream>  // For cin, cout, etc.

#include "LinkedList.hpp"

// Library namespace
using namespace std;

// Constants
template <typename T>
void mergeSort(LinkedList<T> *pList) {
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
  mergeSort<T>(pLeft);
  mergeSort<T>(pRight);

  // conqur & merge
  while (pLeft->size() != 0 && pRight->size() != 0) {
    if (pLeft->front() < pRight->front()) {
      pList->pushBack(pLeft->front());
      pLeft->popFront();
    } else {
      pList->pushBack(pRight->front());
      pRight->popFront();
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

int main() {
  // build list
  LinkedList<int> *list = new LinkedList<int>;
  list->pushBack(4);
  list->pushBack(3);
  list->pushBack(8);
  list->pushBack(1);
  list->pushBack(5);
  list->pushBack(9);
  list->pushBack(7);
  list->pushBack(2);
  list->pushBack(6);

  // print list
  cout << "Print List Forward: ";
  list->print();

  // Sort the list
  cout << endl << endl << "Sorting... " << endl << endl;
  mergeSort(list);

  // Print sorted list
  cout << "Print List Forward: ";
  list->print();
  delete list;
  return 0;
}