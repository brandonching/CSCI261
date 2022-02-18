#include "calculator_functions.h"

#include <iostream>
using namespace std;

/**
 * @brief Formats values in the form "a op b = result"
 *
 * @param a left hand side value
 * @param b right hand saide value
 * @param result result of performing operation on a and b
 * @param op character representation of operation performed on a and b
 */
void print_result(int a, int b, int result, char op) {
  cout << a << " " << op << " " << b << " = " << result << endl;
}

/**
 * @brief prints list of options for user to choose from
 *
 */
void print_options() {
  cout << "(A)dd" << endl;
  cout << "(S)ubtract" << endl;
  cout << "(M)ultiply" << endl;
  cout << "(D)ivide" << endl;
  cout << "(Q)uit" << endl;
}

/**
 * @brief adds two values and prints result to terminal
 *
 * @param a left hand side value
 * @param b right hand side value
 */
void add(int a, int b) {
  int result = a + b;
  print_result(a, b, result, '+');
}

/**
 * @brief subtracts two values and prints result to terminal
 *
 * @param a left hand side value
 * @param b right hand side value
 */
void sub(int a, int b) {
  int result = a - b;
  print_result(a, b, result, '-');
}

/**
 * @brief multiplies two values and prints result to terminal
 *
 * @param a left hand side value
 * @param b right hand side value
 */
void mult(int a, int b) {
  int result = a * b;
  print_result(a, b, result, '*');
}

/**
 * @brief divides two values and prints result to terminal
 *
 * @param a left hand side value
 * @param b right hand side value
 */
void divide(int a, int b) {
  int result = a / b;
  print_result(a, b, result, '/');
}

/**
 * @brief prompts user for two integer values and performs four function
 * calculator operations to them
 *
 */
void turn_calculator_on() {
  cout << "Welcome to the calculator!" << endl;

  // prompt the user to enter our two operands
  cout << "Enter two integers: ";
  int num1, num2;
  cin >> num1 >> num2;

  // until the user decides to quit
  while (true) {
    cout << "What do you want to do?" << endl;
    print_options();

    // get users choice
    char choice;
    cin >> choice;

    switch (choice) {
      case 'A':
      case 'a':
        add(num1, num2);
        break;

      case 'S':
      case 's':
        sub(num1, num2);
        break;

      case 'M':
      case 'm':
        mult(num1, num2);
        break;

      case 'D':
      case 'd':
        divide(num1, num2);
        break;

      case 'Q':
      case 'q':
        return;

      default:
        cout << "Invalid choice" << endl;
    }
  }
}
