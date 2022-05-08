/* CSCI 261: Assignment 7: Lab 7B - Starcraft
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description:
 */

// Libraries
#include <iostream>  // For cin, cout, etc.

#include "BinarySearchTree.hpp"

// Library namespace
using namespace std;

// Constants

int main() {
  cout << "TREE 1" << endl;
  BinarySearchTree<int> *tree = new BinarySearchTree<int>;
  tree->insert(6);
  tree->insert(5);
  tree->insert(7);
  tree->insert(1);
  tree->insert(2);
  tree->insert(9);
  tree->insert(3);
  cout << "In Order:      ";
  tree->printInOrder();
  cout << endl << "Pre Order:     ";
  tree->printPreOrder();
  cout << endl << "Post Order:    ";
  tree->printPostOrder();
  cout << endl << "Breadth Order: ";
  tree->printBreadthOrder();
  cout << endl << "Depth Order:   ";
  tree->printDepthOrder();
  cout << endl <<"By Levels: ";
  tree->printByLevel();
  cout << endl << "Height: ";
  tree->height();

  cout << endl << endl << "TREE 2" << endl;
  BinarySearchTree<int> *tree2 = new BinarySearchTree<int>;
  tree2->insert(5);
  tree2->insert(1);
  tree2->insert(9);
  tree2->insert(7);
  tree2->insert(6);
  tree2->insert(3);
  tree2->insert(2);
  cout << "In Order:      ";
  tree2->printInOrder();
  cout << endl << "Pre Order:     ";
  tree2->printPreOrder();
  cout << endl << "Post Order:    ";
  tree2->printPostOrder();
  cout << endl << "Breadth Order: ";
  tree2->printBreadthOrder();
  cout << endl << "Depth Order:   ";
  tree2->printDepthOrder();
  cout << endl << "By Levels: ";
  tree2->printByLevel();
  cout << endl << "Height: ";
  tree2->height();

  cout << endl << endl << "TREE 3" << endl;
  BinarySearchTree<int> *tree3 = new BinarySearchTree<int>;
  tree3->insert(5);
  tree3->insert(2);
  tree3->insert(1);
  tree3->insert(7);
  tree3->insert(9);
  tree3->insert(6);
  tree3->insert(3);
  cout << "In Order:      ";
  tree3->printInOrder();
  cout << endl << "Pre Order:     ";
  tree3->printPreOrder();
  cout << endl << "Post Order:    ";
  tree3->printPostOrder();
  cout << endl << "Breadth Order: ";
  tree3->printBreadthOrder();
  cout << endl << "Depth Order:   ";
  tree3->printDepthOrder();
  cout << endl << "By Levels: ";
  tree3->printByLevel();
  cout << endl << "Height: ";
  tree3->height();

  return 0;
}