/* CSCI 261: Assignment 1: L1E - Errors
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 *    This program illustrates a variety of common errors.
 *    Fix the errors in each section.

Copyright 2022 Dr. Jeffrey Paone

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or
sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

 */

#include <iostream>
using namespace std;

int main() {
  cout << "Welcome to Loop World" << endl;

  // SECTION I: update comment below on how you fixed this section's code, and
  // tests run that show loop is working properly
  // FIX = typo in cin, initialize sum = 0, change for loop to i <= numIter
  // TESTS: Input 5 Output 15 --- Input 10 Output 55 --- Input 100 Output 5050

  cout << endl;
  cout << "******************" << endl;
  cout << "Section I" << endl;
  cout << "******************" << endl;

  int sum = 0;  // Accumulates the total
  int i;        // Used as loop control variable
  int numIter;  // The number of times to iterate
  cout << "Enter a number greater than 1 to sum up to: ";
  cin >> numIter;
  for (i = 1; i <= numIter; ++i) {
    sum += i;
  }
  cout << "The sum of the numbers from 1 to " << numIter
       << " (inclusive) is: " << sum << endl;

  // SECTION II: update comment below on how you fixed this section's code, and
  // tests run that show loop is working properly
  // FIX = typo in cout and << on cout was going wrong direction, remove total=0
  // from loop and initialize at declare
  // TESTS: 5 Items, Prices: 1.23, 2.45, 2.52, 6.34, 24.70, Total = 37.24

  cout << endl;
  cout << "******************" << endl;
  cout << "Section II" << endl;
  cout << "******************" << endl;

  double total = 0;  // Accumulates total
  double price;      // Gets next price from user
  int numItems;      // Number of items
  int counter = 1;   // Loop control counter

  cout << "How many items do you have? ";
  cin >> numItems;
  cout << endl;

  while (counter <= numItems) {
    cout << "Enter the price of item " << counter << ": ";
    cin >> price;
    cout << endl;
    total += price;
    counter++;
  }
  cout << "The total price of all items is: " << total << endl;

  // SECTION III: update comment below on how you fixed this section's code, and
  // tests run that show loop is working properly
  // FIX = Add ; on cin >> numIter2;, Initialize sum2=0 and counter2=1, add
  // itteration for counter2 in loop, change while conditer to use numIter2
  // TESTS: Input 5 Output 15 --- Input 10 Output 55 --- Input 100 Output 5050

  cout << endl;
  cout << "******************" << endl;
  cout << "Section III" << endl;
  cout << "******************" << endl;

  int sum2 = 0;
  int counter2 = 1;
  int numIter2;

  cout << "What number do you wish me to sum from 1 to?" << endl;
  cin >> numIter2;

  do {
    sum2 += counter2;
    counter2 += 1;
    cout << "Sum so far: " << sum2 << endl;
  } while (counter2 <= numIter2);

  cout << endl << "Section III Recap" << endl;

  cout << "I calculated the sum of numbers from 1 to " << numIter2
       << " (inclusive) as " << sum2 << endl;

  // SECTION IV: update comment below on how you fixed this section's code, and
  // tests run that show loop is working properly
  // FIX = fix for loop conditions
  // TESTS: Input 7 Output 140 -- Input 10 Output 385 -- Input 100 Output 338350

  cout << endl;
  cout << "******************" << endl;
  cout << "Section IV" << endl;
  cout << "******************" << endl;

  cout << "I will now calculate ";
  cout << "the sum of 1 squared to ? squared (inclusive)" << endl;

  int numIter3;
  cin >> numIter3;

  int sum3 = 0;
  for (int i3 = 1; i3 <= numIter3; i3++) {
    sum3 += i3 * i3;
  }

  cout << "The sum of squares from 1 to " << numIter3 << " is: " << sum3
       << endl;

  // SECTION V: update comment below on how you fixed this section's code, and
  // tests run that show loop is working properly
  // FIX = add counter4 and sum4 varibles and initialize, change while loop end
  // condition, iterate counter4 in loop
  // TESTS: Input 5 Output 225 -- Input 101 Output 26,532,801

  cout << endl;
  cout << "******************" << endl;
  cout << "Section V" << endl;
  cout << "******************" << endl;

  cout << "I will now calculate ";
  cout << "the sum from 1 cubed to ? cubed (inclusive)" << endl;

  int numIter4;
  int counter4 = 1;
  int sum4 = 0;
  cin >> numIter4;

  while (counter4 <= numIter4) {
    sum4 += (counter4 * counter4 * counter4);
    counter4 += 1;
  }

  cout << "The sum of cubes from 1 to " << numIter4 << " is: " << sum4 << endl;

  cout << endl;
  cout << "******************" << endl;
  cout << "Section Done" << endl;
  cout << "******************" << endl;

  cout << endl
       << "Congrats!  You fixed them all (hopefully correctly!)" << endl
       << endl
       << "Goodbye" << endl
       << endl;

  return 0;
}
