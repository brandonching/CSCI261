/**
 * @brief A single element of a linked list
 *
 */
template <typename T>
struct Node {
  /**
   * @brief the value of this Node
   *
   */
  T value;
  /**
   * @brief pointer to the next element of the linked list
   *
   */
  Node *pNext;
};

/**
 * @brief A (x, y, z) Vertex Object
 *
 */
template <typename T>
struct Vertex {
  T x, y, z;
};

/**
 * @brief A (p, q, r) Face Object, where p,q, & r represent vertices
 *
 */
template <typename T>
struct Face {
  T p, q, r;
};