/* CSCI 261: Assignment 5: Lab 5A - Double The Fun
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description: working with doubly-linked lsit
 */

// Libraries
#include <iostream>  // For cin, cout, etc.

#include "DoublyLinkedList.hpp"

// Library namespace
using namespace std;

// Constants

int main() {
  // Steps 1-8
  DoublyLinkedList<int> *list = new DoublyLinkedList<int>;
  list->insert(0, 6);
  list->insert(0, 5);
  list->insert(5, 7);
  list->insert(-3, 1);
  list->insert(1, 2);
  list->insert(2, 9);
  list->insert(2, 3);

  // Steps 9-10
  cout << "Print List Forward:  ";
  list->print();
  cout << "Print List Backward: ";
  list->printReverse();

  // Steps 11-12
  list->set(3, 4);
  cout << "Print List Forward:  ";
  list->print();

  // Steps 13-16
  list->remove(-2);
  list->remove(9);
  list->remove(2);
  cout << "POS 2: " << list->get(2) << endl;

  // Step 17-19
  cout << "Size: " << list->size() << endl;
  cout << "Print List Forward:  ";
  list->print();
  delete list;

  return 0;
}