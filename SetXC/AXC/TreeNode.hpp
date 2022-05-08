#ifndef TREENODE_H
#define TREENODE_H

template <typename T>
struct TreeNode {
  T value;
  TreeNode *Parent;
  TreeNode *Left;
  TreeNode *Right;
};

#endif