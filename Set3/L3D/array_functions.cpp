#include "array_functions.h"

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
void array_allocate(int *&pArray, const int INIT_SIZE) {
  pArray = new int[INIT_SIZE];
}

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
int array_get_element_at(const int *pArray, const int SIZE, const int POS) {
  if (POS < SIZE && POS >= 0) {
    return pArray[POS];
  }
  return 0;
}

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
                          const int VALUE) {
  if (POS <= SIZE && POS >= 0) {
    pArray[POS] = VALUE;
  }
}

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
void array_deallocate(int *&pArray, int &size) {
  pArray = nullptr;
  delete[] pArray;
  size = 0;
}

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
void array_insert_at_position(int *&pArray, int &size, const int POS,
                              const int VALUE) {
  // Build temp array equal to given array
  int *tempArray = nullptr;
  array_allocate(tempArray, size + 1);

  // Add to end of Array
  if (POS >= size) {
    for (int i = 0; i < size; i++) {
      tempArray[i] = pArray[i];
    }
    tempArray[size] = VALUE;
    pArray = tempArray;
  } else if (POS <= 0) {
    // Add to the beginging or array
    tempArray[0] = VALUE;
    for (int i = 1; i <= size; i++) {
      tempArray[i] = pArray[i - 1];
    }
    pArray = tempArray;
  } else {
    // just change existing array
    for (int i = 0; i < POS;i++){
      tempArray[i] = pArray[i];
    }
    tempArray[POS] = VALUE;
    for (int i = POS+1; i <= size; i++) {
      tempArray[i] = pArray[i-1];
    }
    pArray = tempArray;
  }

  size++;
  // Deallocate temp array
  tempArray = nullptr;
  delete[] tempArray;
}

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
int array_min(int *pARRAY, const int SIZE) {
  if (SIZE != 0) {
    int minValue = pARRAY[0];
    for (int i = 1; i < SIZE - 1; i++) {
      if (pARRAY[i] < minValue) {
        minValue = pARRAY[i];
      }
    }
    return minValue;
  }
  return 0;
}

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
int array_max(int *pARRAY, const int SIZE) {
  if (SIZE != 0) {
    int maxValue = pARRAY[0];
    for (int i = 1; i < SIZE; i++) {
      if (pARRAY[i] > maxValue) {
        maxValue = pARRAY[i];
      }
    }
    return maxValue;
  }
  return 0;
}

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
int array_find(int *pARRAY, int SIZE, int TARGET) {
  if (SIZE > 0) {
    for (int i = 0; i < SIZE; i++) {
      if (pARRAY[i] == TARGET) {
        return i;
      }
    }
  }
  return -1;
}

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
void array_remove_from_position(int *&pArray, int &size, int POS) {

  if (size > 0) {
    // Build temp array
    int *tempArray = nullptr;
    array_allocate(tempArray, size - 1);

    if (POS <= 0) {
      for (int i = 1; i < size; i++) {
        tempArray[i-1] = pArray[i];
      }
    } else if (POS >= size) {
      for (int i = 0; i < size - 1; i++) {
        tempArray[i] = pArray[i];
      }
    } else {
      for (int i = 0; i < POS;i++){
        tempArray[i] = pArray[i];
      }
      for (int i = POS + 1; i < size;i++){
        tempArray[i - 1] = pArray[i];
      }
    }

    pArray = tempArray;

    size--;
    // Deallocate temp array
    tempArray = nullptr;
    delete[] tempArray;
  }
}