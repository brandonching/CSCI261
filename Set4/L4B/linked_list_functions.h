#ifndef LINKED_LIST_FUNCTIONS_H
#define LINKED_LIST_FUNCTIONS_H

#include "Node.h"

/**
 * @brief Creates a pointer to a Node whose value is provided
 * and next pointer is set to a null pointer
 * 
 * @param VALUE value to set the newly created Node to
 * @return Node* pointer to the newly created Node
 */
Node* linked_list_make_node(const int VALUE);

/**
 * @brief Returns the number of nodes in the linked list
 * from the current Node forward
 * 
 * @param pHead pointer to the linked list head
 * @return int number of nodes in the linked list
 */
int linked_list_get_size(Node* pHead);

/**
 * @brief Adds a new node to the front of the provided linked
 * list.  The new node's value is provided and the new node's
 * next pointer points to the provided linked list.
 * 
 * @param pHead pointer to the linked list head
 * @param VALUE value to add to the front of the linked list
 * @return Node* pointer to the new linked list head
 */
Node* linked_list_add_value_to_front(Node* pHead, const int VALUE);

/**
 * @brief Returns the value of an element in the linked list.  If the
 * position is out of range, returns -1 by default.
 * 
 * @param pHead pointer to the linked list head
 * @param POS element position to retrieve the value at
 * @return int if POS is within range, the corresponding element's position.  if POS is out of range, -1
 */
int linked_list_get_value_at_position(Node* pHead, const int POS);

/**
 * @brief Returns the minimum value present in the linked list.  If the
 * linked list is empty, returns -1 by default.
 * 
 * @param pHead pointer to the linked list head
 * @return int minimum value in the linked list.  If linked list is empty, -1
 */
int linked_list_min(Node* pHead);

/**
 * @brief Returns the maximum value present in the linked list.  If the
 * linked list is empty, returns -1 by default.
 * 
 * @param pHead pointer to the linked list head
 * @return int maximum value in the linked list.  If linked list is empty, -1
 */
int linked_list_max(Node* pHead);

/**
 * @brief Returns the index of the first occurrence of target within
 * the linked list.  If the linked list is empty or target is not found,
 * returns -1.
 * 
 * @param pHead pointer to the linked list head (haystack)
 * @param TARGET value to search for (needle)
 * @return int position of first occurrence.  If not found, -1
 */
int linked_list_find(Node* pHead, const int TARGET);

/**
 * @brief Removes the current head node at the front of the provided linked
 * list.  
 * 
 * @param pHead pointer to the linked list head
 * @return Node* pointer to the new linked list head
 */
Node* linked_list_remove_node_from_front(Node* pHead);

/**
 * @brief Sets the value at a given position within a linked list.  If 
 * position is out of range, does not modify the list.
 * 
 * @param pHead pointer to the linked list head
 * @param POS element position to retrieve the value at
 * @param VALUE value to set to the node to
 * @return Node* pointer to the new linked list head
 */
Node* linked_list_set_value_at_position(Node* pHead, const int POS, const int VALUE);

#endif