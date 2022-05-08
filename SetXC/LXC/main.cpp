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
  BinarySearchTree<int> *tree = new BinarySearchTree<int>;
  tree->insert(6);
  tree->insert(5);
  tree->insert(7);
  tree->insert(1);
  tree->insert(2);
  tree->insert(9);
  tree->insert(3);


  return 0;
}