#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <queue>
#include <stack>

#include "TreeNode.hpp"

template <typename T>
class BinarySearchTree {
 public:
  BinarySearchTree();
  BinarySearchTree(const BinarySearchTree& OTHER);
  ~BinarySearchTree();
  BinarySearchTree& operator=(const BinarySearchTree& OTHER);
  void insert(const T VAL);
  int size() const;

  void printInOrder();
  void printPreOrder();
  void printPostOrder();
  void printBreadthOrder();
  void printDepthOrder();
  void printByLevel();

  void height();

 private:
  TreeNode<T>* mpRoot;
  unsigned int mSize;
};

/** @brief Default Constructor. Sets the root pointers to null and size to 0 **/
template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
  TreeNode<T>* newNode = new TreeNode<T>;
  newNode->Left = nullptr;
  newNode->Right = nullptr;
  mpRoot = nullptr;
  mSize = 0;
}

/** @brief Copy Constructor. Preforms a deep copy on provided BinarySearchTree
 *
 * @param OTHER Biarnary Seach Tree to be copied
 * **/
template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree& OTHER) {
  mpRoot = OTHER.mpRoot;
  mSize = OTHER.mSize;
}

/** @brief Destruct the tree
 * **/
template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {}

/** @brief Copy operator
 * **/
template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(
    const BinarySearchTree& OTHER) {
  // Self-Assignment
  if (this == &OTHER) {
    return *this;
  }
  // do deep copy
  BinarySearchTree<T> newTree(OTHER);
  swap(newTree.mpRoot, mpRoot);
  swap(newTree.mSize, mSize);
  return *this;
}

/** @brief Insert a new value into the BST
 *
 * @param VAL the value to be added to the tree
 * **/
template <typename T>
void BinarySearchTree<T>::insert(const T VAL) {
  // create the new node
  TreeNode<T>* newNode = new TreeNode<T>;
  newNode->value = VAL;
  newNode->Left = nullptr;
  newNode->Right = nullptr;
  BinarySearchTree<T>* nextTree = new BinarySearchTree<T>;
  if (mpRoot == nullptr && mSize == 0) {
    // Sets first node
    mpRoot = newNode;
    newNode->Parent = nullptr;
  } else if (VAL < mpRoot->value) {
    // recurrsivelly add to left if less than current nodes val
    if (mpRoot->Left == nullptr) {
      mpRoot->Left = newNode;
    } else {
      nextTree->mpRoot = mpRoot->Left;
      nextTree->insert(VAL);
    }
  } else {
    // recurrsivelly add to right if less than current nodes val
    if (mpRoot->Right == nullptr) {
      mpRoot->Right = newNode;
    } else {
      nextTree->mpRoot = mpRoot->Right;
      nextTree->insert(VAL);
    }
  }

  mSize++;
}

/** @brief Size of the Binary Search Tree
 *
 * @return Size of the tree **/
template <typename T>
int BinarySearchTree<T>::size() const {
  return mSize;
}

/** @brief Print out the BST in left, center, right order
 * **/
template <typename T>
void BinarySearchTree<T>::printInOrder() {
  // Recurrsivly Search Left
  if (mpRoot->Left != nullptr) {
    BinarySearchTree<T>* nextTree = new BinarySearchTree<T>;
    nextTree->mpRoot = mpRoot->Left;
    nextTree->printInOrder();
  }

  // Print out center
  std::cout << mpRoot->value << " ";

  // Recurrsivly Search Right
  if (mpRoot->Right != nullptr) {
    BinarySearchTree<T>* nextTree = new BinarySearchTree<T>;
    nextTree->mpRoot = mpRoot->Right;
    nextTree->printInOrder();
  }
}

/** @brief Print out the BST in center, left, right order
 * **/
template <typename T>
void BinarySearchTree<T>::printPreOrder() {
  // Print out center
  std::cout << mpRoot->value << " ";

  // Recurrsivly Search Left
  if (mpRoot->Left != nullptr) {
    BinarySearchTree<T>* nextTree = new BinarySearchTree<T>;
    nextTree->mpRoot = mpRoot->Left;
    nextTree->printPreOrder();
  }

  // Recurrsivly Search Right
  if (mpRoot->Right != nullptr) {
    BinarySearchTree<T>* nextTree = new BinarySearchTree<T>;
    nextTree->mpRoot = mpRoot->Right;
    nextTree->printPreOrder();
  }
}

/** @brief Print out the BST in left, right, center order
 * **/
template <typename T>
void BinarySearchTree<T>::printPostOrder() {
  // Recurrsivly Search Left
  if (mpRoot->Left != nullptr) {
    BinarySearchTree<T>* nextTree = new BinarySearchTree<T>;
    nextTree->mpRoot = mpRoot->Left;
    nextTree->printPostOrder();
  }

  // Recurrsivly Search Right
  if (mpRoot->Right != nullptr) {
    BinarySearchTree<T>* nextTree = new BinarySearchTree<T>;
    nextTree->mpRoot = mpRoot->Right;
    nextTree->printPostOrder();
  }

  // Print out center
  std::cout << mpRoot->value << " ";
}

/** @brief Print out the BST using BFS
 **/
template <typename T>
void BinarySearchTree<T>::printBreadthOrder() {
  // build queue and add first node to it
  std::queue<TreeNode<T>*> printQueue;
  printQueue.push(mpRoot);
  TreeNode<T>* currentNode;

  // search through list until nothing left
  while (!printQueue.empty()) {
    // update current node, print, and remove from queue
    currentNode = printQueue.front();
    std::cout << currentNode->value << " ";
    printQueue.pop();

    // add left to queue
    if (currentNode->Left != nullptr) {
      printQueue.push(currentNode->Left);
    }

    // add right to queue
    if (currentNode->Right != nullptr) {
      printQueue.push(currentNode->Right);
    }
  }
}

/** @brief Print out the BST using DFS
 **/
template <typename T>
void BinarySearchTree<T>::printDepthOrder() {
  // build stack and add first node to it
  std::stack<TreeNode<T>*> printQueue;
  printQueue.push(mpRoot);
  TreeNode<T>* currentNode;

  // search through list until nothing left
  while (!printQueue.empty()) {
    // update current node, print, and remove from stack
    currentNode = printQueue.top();
    std::cout << currentNode->value << " ";
    printQueue.pop();

    // add left to stack
    if (currentNode->Right != nullptr) {
      printQueue.push(currentNode->Right);
    }

    // add right to stack
    if (currentNode->Left != nullptr) {
      printQueue.push(currentNode->Left);
    }
  }
}

/** @brief Print out the BST one level of the tree at a time
 **/
template <typename T>
void BinarySearchTree<T>::printByLevel() {
  if (mpRoot == nullptr) {
    return;  // base case
  }

  // queue and current node for tracking levels
  std::queue<TreeNode<T>*> printQueue;
  printQueue.push(mpRoot);
  TreeNode<T>* currentNode;

  // start with level 1
  int level = 1;
  while (!printQueue.empty()) {
    // print level label
    std::cout << std::endl << "Level " << level << ": ";
    // size of queue is the number of items on level
    int levelSize = printQueue.size();
    // print out each item on level and add right/left
    while (levelSize > 0) {
      // print out value
      currentNode = printQueue.front();
      std::cout << currentNode->value << " ";
      printQueue.pop();

      // add left node
      if (currentNode->Left != nullptr) {
        printQueue.push(currentNode->Left);
      }

      // add right node
      if (currentNode->Right != nullptr) {
        printQueue.push(currentNode->Right);
      }
      levelSize--;
    }
    level++;
  }
}

/** @brief Print out the height of the BST
 **/
template <typename T>
void BinarySearchTree<T>::height() {
  if (mpRoot == nullptr) {
  }

  // queue and current node for tracking levels
  std::queue<TreeNode<T>*> printQueue;
  printQueue.push(mpRoot);
  TreeNode<T>* currentNode;

  // start with level 1
  int level = 1;
  while (!printQueue.empty()) {
    int levelSize = printQueue.size();
    while (levelSize > 0) {
      // remove last level nodes
      currentNode = printQueue.front();
      printQueue.pop();

      // add left node
      if (currentNode->Left != nullptr) {
        printQueue.push(currentNode->Left);
      }

      // add right node
      if (currentNode->Right != nullptr) {
        printQueue.push(currentNode->Right);
      }
      levelSize--;
    }
    level++;
  }
  std::cout << level - 1;
}
#endif