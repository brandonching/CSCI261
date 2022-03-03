#include "array_functions.h"

void array_allocate(int *&pArray, const int INIT_SIZE) {
  pArray = new int[INIT_SIZE];
}

int array_get_element_at(const int *pArray, const int SIZE, const int POS) {
  if (POS < SIZE && POS >= 0) {
    return pArray[POS];
  }
  return 0;
}

void array_set_element_at(int *&pArray, const int SIZE, const int POS,
                          const int VALUE) {
  if (POS <= SIZE && POS >= 0) {
    pArray[POS] = VALUE;
  }
}

void array_deallocate(int *&pArray, int &size) {
  pArray = nullptr;
  delete[] pArray;
  size = 0;
}

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