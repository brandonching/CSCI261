#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H

/**
 * @brief Allocates an integer array of a target size on the free store.
 * Upon function return, pArray will point to starting address and the
 * contents of pArray will all be initalized to zero.
 *
 * @param pArray pointer to integer array
 * @param INIT_SIZE initial array size as an integer
 *
 * @note Runtime of function O(1)
 */
void array_allocate(int *&pArray, const int INIT_SIZE);

/**
 * @brief Returns the value of the element at a target position.  If the
 * position it not within the array size, returns zero.
 *
 * @param pARRAY pointer to integer array
 * @param SIZE size of the array as an integer
 * @param POS position to retrieve value from
 * @return int element value at given position (or zero if out of range)
 *
 * @note Runtime of function O(1)
 */
int array_get_element_at(const int *pArray, const int SIZE, const int POS);

/**
 * @brief Sets the value of the element at a target position.  If the
 * position is out of range, does nothing.
 *
 * @param pArray pointer to integer array
 * @param SIZE size of the array as an integer
 * @param POS position to set value at
 * @param VALUE value to place at target position
 *
 * @note Runtime of function O(1)
 */
void array_set_element_at(int *&pArray, const int SIZE, const int POS,
                          const int VALUE);

/**
 * @brief Deallocates an integer array, returning its memory back to
 * the free store.  Upon function return, pArray will be set to be a
 * null pointer and the array size will be set to zero.
 *
 * @param pArray pointer to integer array
 * @param size size of the array as an integer
 *
 * @note Runtime of function O(1)
 */
void array_deallocate(int *&pArray, int &size);

/**
 * @brief Inserts a value at a target position.  If the position is
 * out of range, inserts at the front/back as appropriate.  Upon
 * function return, the array will be increased in size by one.  The
 * array size will be updated to the new size.
 *
 * @param pArray pointer to integer array
 * @param size size of the array as an integer
 * @param POS position to insert value at
 * @param VALUE value to insert at target position
 *
 * @note Runtime of function O(n)
 */
void array_insert_at_position(int *&pArray, int &size,const int PAS,const int VALUE);

/**
 * @brief Returns the minimum value within the array.  If array size is
 * zero or the array is uninitialized, returns zero.
 *
 * @param pARRAY pointer to the integer array
 * @param SIZE size of the array as an integer
 * @return int minimum value within the array
 *
 * @note Runtime of function O(n)
 */
int array_min(int *pARRAY, const int SIZE);

/**
 * @brief Returns the maximum value within the array.  If array size is
 * zero or the array is uninitialized, returns zero.
 *
 * @param pARRAY pointer to the integer array
 * @param SIZE size of the array as an integer
 * @return int maximum value within the array
 *
 * @note Runtime of function O(n)
 */
int array_max(int *pARRAY, const int SIZE);

/**
 * @brief Returns the first position within an array a target value
 * is located at.  If the target value is not present within the
 * array, returns -1.
 *
 * @param pARRAY pointer to the integer array (the haystack)
 * @param SIZE size of the array as an integer
 * @param TARGET target integer value to search for in the array (the needle)
 * @return int position within the array target value is located (or -1 if not
 * present)
 *
 * @note Runtime of function O(n)
 */
int array_find(int *pARRAY, int SIZE, int TARGET);

/**
 * @brief Removes a value at a target position.  If the position is
 * out of range, removes from the front/back as appropriate.  Upon
 * function return, the array will be decreased in size by one.  The
 * array size will be updated to the new size.
 *
 * @param pArray pointer to integer array
 * @param size size of the array as an integer
 * @param POS position to remove value from
 *
 * @note Runtime of function O(n)
 */
void array_remove_from_position(int *&pArray, int &size, int POS);

#endif
