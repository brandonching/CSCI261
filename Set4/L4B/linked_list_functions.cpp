#include "linked_list_functions.h"

Node* linked_list_make_node(const int VALUE) {
  Node* tempNode = new Node;
  tempNode->pNext = nullptr;
  tempNode->value = VALUE;
  return tempNode;
}

int linked_list_get_size(Node* pHead) {
  int size = 0;
  Node* currentNode = pHead;
  while (currentNode != nullptr) {
    size++;
    currentNode = currentNode->pNext;
  }
  return size;
}

Node* linked_list_add_value_to_front(Node* pHead, const int VALUE) {
  Node* tempNode = new Node;
  tempNode->pNext = pHead;
  tempNode->value = VALUE;
  return tempNode;
}

int linked_list_get_value_at_position(Node* pHead, const int POS) {
  if (pHead == nullptr) {
    return -1;
  }
  Node* currentNode = pHead;
  if (POS < 0) {
    return -1;
  }
  for (int i = 1; i <= POS; i++) {
    currentNode = currentNode->pNext;
    if (currentNode == nullptr) {
      return -1;
    }
  }
  return currentNode->value;
}

int linked_list_min(Node* pHead) {
  if (pHead == nullptr) {
    return -1;
  }
  int minValue = pHead->value;
  Node* currentNode = pHead;
  while (currentNode != nullptr) {
    if (currentNode->value < minValue) {
      minValue = currentNode->value;
    }
    currentNode = currentNode->pNext;
  }
  return minValue;
}

int linked_list_max(Node* pHead) {
  if (pHead == nullptr) {
    return -1;
  }
  int maxValue = pHead->value;
  Node* currentNode = pHead;
  while (currentNode != nullptr) {
    if (currentNode->value > maxValue) {
      maxValue = currentNode->value;
    }
    currentNode = currentNode->pNext;
  }
  return maxValue;
}

int linked_list_find(Node* pHead, const int TARGET) {
  int index = 0;
  Node* currentNode = pHead;
  while (currentNode != nullptr) {
    if (currentNode->value == TARGET) {
      return index;
    }
    currentNode = currentNode->pNext;
    index++;
  }
  return -1;
}

Node* linked_list_remove_node_from_front(Node* pHead) {
  if (pHead == nullptr) {
    return nullptr;
  }
  Node* temp = pHead;
  pHead = temp->pNext;
  delete temp;
  return pHead;
}

Node* linked_list_set_value_at_position(Node* pHead, const int POS,
                                        const int VALUE) {
  if (POS < 0) {
    return pHead;
  }
  Node* currentNode = pHead;
  for (int i = 0; i < POS; i++) {
    currentNode = currentNode->pNext;
    if (currentNode == nullptr) {
      return pHead;
    }
  }
  currentNode->value = VALUE;
  return pHead;
}