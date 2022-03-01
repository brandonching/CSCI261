/* CSCI 261: Assignment 3: Lab 3C - Pointers
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description: Practice useing Pointers
 */

// Libraries
#include <iostream>  // For cin, cout, etc.

// Library namespace
using namespace std;

// Constants

int main() {
  // 1. Declare an integer named iNum with initial value 9
  int iNum = 9;
  // 2. Declare a double named dNum with initial value 14.25.
  double dNum = 14.25;

  // 3. Declare two pointers to integers named pINum1 and pINum2.
  int *pINum1, *pINum2;
  // 4. Declare a pointer to a double named pDNum.
  double* pDNum;

  // 5. Assign the address of iNum to pINum1.
  pINum1 = &iNum;
  // 6. Output the address of iNum and be sure to identify to the user what you
  // are displaying. There are two ways you can do this; you should do both, to
  // convince yourself they are the same.
  cout << "Address of iNum via PBP: " << pINum1 << endl;
  cout << "Adderss of iNum via PBR: " << &iNum << endl;
  // 7. Use pINum1 to display the contents of iNum
  cout << "Use pINum1 to display the contents of iNum: " << *pINum1 << endl;

  // 8. Try to assign the address of dNum to pINum2. Compile your program. What
  // error message do you see? Comment out this bad line of code, but include
  // the error message as a comment with this line.
  // pINum2 = &dNum; error:
  // cannot convert 'double*' to 'int*' in assignment

  // 9. Assign the address of dNum to pDNum.
  pDNum = &dNum;
  // 10. Output the address and then the contents of dNum (using pDNum).
  cout << "Address of dNum: " << pDNum << endl;
  cout << "Contents of dNum: " << *pDNum << endl;

  // 11. Directly change the value of iNum to 7.
  iNum = 7;

  // 12. Use pINum1 to output the contents of iNum.
  cout << "Contents of iNum via pINum1: " << *pINum1 << endl;

  // 13. Assign pINum2 to have the same value as pINum1. Do not reference iNum;
  // instead use the address stored in pINum1.
  pINum2 = pINum1;

  // 14. Output the address in pINum2.  This should be the same as displayed in
  // step 6.
  cout << "Address of iNum via PBP: " << pINum1 << endl;
  cout << "Adderss of iNum via PBR: " << &iNum << endl;

  // 15. Output the value pointed to by pINum2.
  cout << "Value point to by pINum2: " << *pINum2 << endl;

  // 16. Using pINum2, change the contents of iNum to 12.
  *pINum2 = 12;

  // 17. Output the contents of iNum three times, first using pINum1, then using
  // pINum2, then iNum directly. In each case, identify what the user is seeing
  // appropriately.
  cout << "Contents of iNum via pINum1: " << *pINum1 << endl;
  cout << "Contents of iNum via pINum2: " << *pINum2 << endl;
  cout << "Contents of iNum via iNum: " << iNum << endl;
  return 0;
}