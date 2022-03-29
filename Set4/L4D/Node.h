#ifndef NODE_H
#define NODE_H

/**
 * @brief A single element of a linked list
 * 
 */
struct Node {
    /**
     * @brief the value of this Node
     * 
     */
    int value;
    /**
     * @brief pointer to the next element of the linked list
     * 
     */
    Node *pNext;
};

#endif