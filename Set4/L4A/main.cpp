/* CSCI 261: Assignment 4: Lab 4A - Array vs Linked List
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description: Use an array and linked list to complete the same task
 */

// Libraries
#include <iostream>  // For cin, cout, etc.
#include <fstream>
// Library namespace
using namespace std;

// Constants

struct Node {
  int Value;
  Node *pNext;
};

int main() {
  // Array method
  int array[3];
  int *pArray;
  pArray = array;

  // Get array element values
  cout << "Please input 3 elements of array" << endl;
  for (int i = 0; i <= 2; i++) {
    cout << "Element " << i + 1 << ": ";
    cin >> pArray[i];
  }

  // print array in order
  cout << "Contents of Array are..." << endl;
  for (int i = 0; i <= 2; i++) {
    cout << "Element " << i + 1 << ": " << pArray[i] << endl;
  }

  // print array in reverser order
  cout << "Contents of Array in reverse order are..." << endl;
  for (int i = 2; i >= 0; i--) {
    cout << "Element " << i + 1 << ": " << pArray[i] << endl;
  }

  // Linked List method
  // initiaze list
  Node *pHead = new Node;
  pHead->pNext = nullptr;
  Node *pTail = pHead;

  // Get node values
  cout << endl << "Please input 3 node values of linked list" << endl;
  for (int i = 1; i <= 3; i++) {
    cout << "Node " << i << " Value: ";
    if (i == 1) {
      cin >> pHead->Value;
    } else {
      Node *temp = new Node;
      cin >> temp->Value;
      temp->pNext = nullptr;
      pTail->pNext = temp;
      pTail = temp;
    }
  }

  // Print node values in order
  Node *currentNode = pHead;
  int idx = 1;
  cout << "Linked List Values in order are..." << endl;
  while (currentNode != nullptr) {
    cout << "Node " << idx++ << " Value: " << currentNode->Value << endl;
    currentNode = currentNode->pNext;
  }
  delete currentNode;

  // Print node values in reverse order
  cout << "Lined List Values in reverse order are..." << endl;
  for (int i = 3; i >= 1; i--) {
    Node *currentNode = pHead;
    for (int n = i; n > 1; n--) {
      currentNode = currentNode->pNext;
    }
    cout << "Node " << i << " Value: " << currentNode->Value << endl;
    // Delete nodes as we go
    delete currentNode;
  }

  // Delete linked list(what remains)
  delete pTail;
  delete pHead;
  return 0;
}