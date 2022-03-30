/* CSCI 261: Assignment 4: Lab 4E - A Linked List Class Part III: Test, Copy,
 * Print
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description:
 */

// Libraries
#include <iostream>  // For cin, cout, etc.

#include "LinkedList.cpp"

// Library namespace
using namespace std;

// Constants

int main() {
  // Steps 1-5
  LinkedList *list = new LinkedList;
  cout << "List 1 Size: " << list->size() << endl;
  list->pushFront(1);
  list->pushBack(2);
  list->pushFront(3);
  list->pushBack(4);
  list->pushFront(5);
  list->pushBack(6);
  cout << "List 1 Size: " << list->size() << endl;
  cout << "The Contents of the list are: ";
  for (unsigned int i = 0; i < list->size(); i++) {
    cout << list->at(i) << " ";
  }
  cout << endl;

  // Steps 6-9
  LinkedList *list2 = new LinkedList;
  cout << endl << "List 2 Size: " << list2->size() << endl;
  list2 = list;
  cout << "Set list2 = list1" << endl;
  cout << "List 1 Size: " << list->size() << endl;
  cout << "List 2 Size: " << list2->size() << endl << endl;

  // Steps 10-11
  list->pushFront(7);
  list->pushBack(8);
  cout << "List 1 Size: " << list->size() << "   Elements:";
  for (unsigned int i = 0; i < list->size(); i++) {
    cout << " " << list->at(i);
  }
  cout << endl << "List 2 Size: " << list2->size() << "   Elements:";
  for (unsigned int i = 0; i < list2->size(); i++) {
    cout << " " << list2->at(i);
  }
  cout << endl << endl;

  // Steps 12-13
  LinkedList *list3(list);
  cout << "List 1 Size: " << list->size() << endl;
  cout << "List 2 Size: " << list2->size() << endl;
  cout << "List 3 Size: " << list3->size() << endl << endl;

  // Steps 14-16
  list->pushFront(9);
  list->pushBack(10);
  cout << "List 1 Size: " << list->size() << endl;
  cout << "List 2 Size: " << list2->size() << endl;
  cout << "List 3 Size: " << list3->size() << endl << endl;

  // Step 17
  cout << "Deallocating list";
  delete list;
  delete list2;
  delete list3;

  return 0;
}