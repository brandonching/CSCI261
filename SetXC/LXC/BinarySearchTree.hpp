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
#endif