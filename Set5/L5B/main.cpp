/* CSCI 261: Assignment 5: Lab 5B - Sorting I: Sorting a List
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description: sorting list
 */

// Libraries
#include <iostream>  // For cin, cout, etc.

#include "DoublyLinkedList.hpp"

// Library namespace
using namespace std;

// Constants

int main() {
  // build list
  DoublyLinkedList<int> *list = new DoublyLinkedList<int>;
  list->insert(0, 4);
  list->insert(1, 3);
  list->insert(2, 8);
  list->insert(3, 1);
  list->insert(4, 5);
  list->insert(5, 9);
  list->insert(6, 7);
  list->insert(7, 2);
  list->insert(8, 6);

  // print list
  cout << "Print List Forward: ";
  list->print();
  cout << endl << "Sorting... " << endl << endl;

  // Sort the list
  for (unsigned int i = 0; i < list->size()-1; i++) {
    int minValue = list->get(i);
    int minValIdx = i;
    for (unsigned int j = i; j < list->size(); j++) {
      if (list->get(j) < minValue) {
        minValue = list->get(j);
        minValIdx = j;
      }
    }
    list->remove(minValIdx);
    list->insert(i,minValue);
  }

  // Print sorted list
  cout << "Print List Forward: ";
  list->print();
  delete list;
  return 0;
}