#ifndef DOUBLYNODE_H
#define DOUBLYNODE_H
/**
 * @brief A single element of a doubly linked list
 *
 */
template <typename T>
struct DoublyNode {
  /**
   * @brief the value of this Node
   *
   */
  T value;
  /**
   * @brief pointer to the next element of the linked list
   *
   */
  DoublyNode *pNext;
  /**
   * @brief pointer to the previous element of the linked list
   *
   */
  DoublyNode *pLast;
};

#endif