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

template <typename T>
void BinarySearchTree<T>::insert(const T VAL) {
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
    if (mpRoot->Left == nullptr) {
      mpRoot->Left = newNode;
    } else {
      nextTree->mpRoot = mpRoot->Left;
      nextTree->insert(VAL);
    }
  } else {
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

template <typename T>
void BinarySearchTree<T>::printInOrder() {
  if (mpRoot->Left != nullptr) {
    BinarySearchTree<T>* nextTree = new BinarySearchTree<T>;
    nextTree->mpRoot = mpRoot->Left;
    nextTree->printInOrder();
  }

  std::cout << mpRoot->value << " ";

  if (mpRoot->Right != nullptr) {
    BinarySearchTree<T>* nextTree = new BinarySearchTree<T>;
    nextTree->mpRoot = mpRoot->Right;
    nextTree->printInOrder();
  }
}

template <typename T>
void BinarySearchTree<T>::printPreOrder() {
  std::cout << mpRoot->value << " ";

  if (mpRoot->Left != nullptr) {
    BinarySearchTree<T>* nextTree = new BinarySearchTree<T>;
    nextTree->mpRoot = mpRoot->Left;
    nextTree->printPreOrder();
  }

  if (mpRoot->Right != nullptr) {
    BinarySearchTree<T>* nextTree = new BinarySearchTree<T>;
    nextTree->mpRoot = mpRoot->Right;
    nextTree->printPreOrder();
  }
}

template <typename T>
void BinarySearchTree<T>::printPostOrder() {
  if (mpRoot->Left != nullptr) {
    BinarySearchTree<T>* nextTree = new BinarySearchTree<T>;
    nextTree->mpRoot = mpRoot->Left;
    nextTree->printPostOrder();
  }

  if (mpRoot->Right != nullptr) {
    BinarySearchTree<T>* nextTree = new BinarySearchTree<T>;
    nextTree->mpRoot = mpRoot->Right;
    nextTree->printPostOrder();
  }

  std::cout << mpRoot->value << " ";
}

template <typename T>
void BinarySearchTree<T>::printBreadthOrder() {
  std::queue<TreeNode<T>*> printQueue;
  printQueue.push(mpRoot);
  TreeNode<T>* currentNode;
  while (!printQueue.empty()) {
    currentNode = printQueue.front();
    std::cout << currentNode->value << " ";
    printQueue.pop();

    if (currentNode->Left != nullptr) {
      printQueue.push(currentNode->Left);
    }

    if (currentNode->Right != nullptr) {
      printQueue.push(currentNode->Right);
    }
  }
}

template <typename T>
void BinarySearchTree<T>::printDepthOrder() {
  std::stack<TreeNode<T>*> printQueue;
  printQueue.push(mpRoot);
  TreeNode<T>* currentNode;
  while (!printQueue.empty()) {
    currentNode = printQueue.top();
    std::cout << currentNode->value << " ";
    printQueue.pop();

    if (currentNode->Right != nullptr) {
      printQueue.push(currentNode->Right);
    }

    if (currentNode->Left != nullptr) {
      printQueue.push(currentNode->Left);
    }
  }
}

template <typename T>
void BinarySearchTree<T>::printByLevel() {
  if (mpRoot == nullptr) {
    return;  // base case
  }

  std::queue<TreeNode<T>*> printQueue;
  printQueue.push(mpRoot);
  TreeNode<T>* currentNode;

  int level = 1;
  while (!printQueue.empty()){
    std::cout << std::endl<< "Level " << level << ": ";
    int levelSize = printQueue.size();
    while (levelSize > 0) {
      currentNode = printQueue.front();
      std::cout << currentNode->value << " ";
      printQueue.pop();
      if (currentNode->Left != nullptr) {
        printQueue.push(currentNode->Left);
      }

      if (currentNode->Right != nullptr) {
        printQueue.push(currentNode->Right);
      }
      levelSize--;
    }
    level++;
  }
}

template <typename T>
void BinarySearchTree<T>::height() {
  if (mpRoot == nullptr) {
  }

  std::queue<TreeNode<T>*> printQueue;
  printQueue.push(mpRoot);
  TreeNode<T>* currentNode;

  int level = 1;
  while (!printQueue.empty()) {
    int levelSize = printQueue.size();
    while (levelSize > 0) {
      currentNode = printQueue.front();
      printQueue.pop();
      if (currentNode->Left != nullptr) {
        printQueue.push(currentNode->Left);
      }

      if (currentNode->Right != nullptr) {
        printQueue.push(currentNode->Right);
      }
      levelSize--;
    }
    level++;
  }
  std::cout << level-1;
}
#endif