/* CSCI 261 Set 1: Lab 1A - Math Equation Solver
 *
 * Author: Brandon Ching
 * Resources: w3school for pow() function
 *
 * Program has two "caculators", one which calculates the current in Ohms law
 * and the other calculates gravitational force
 */
// Libraries
#include <math.h>  // For pow

#include <iostream>  // For cin, cout, etc.

// Library namespace
using namespace std;

// Constants

int main() {
  // Ohms Law Calcualtion
  double voltage;
  double resistance;
  cout << "Calculating Ohm's Law --- I = V/R" << endl;
  // User inputs
  cout << "Enter the Voltage: ";
  cin >> voltage;
  cout << "Enter the Resistance: ";
  cin >> resistance;
  // calcuate answer
  double current = voltage / resistance;
  cout << "The Current is: " << current << "A" << endl;

  // Newtons Law of Universal Gravitational Force
  cout << "Calculating Newton's Law of Universal Gravitational Force --- F = "
          "Gm1m2/r^2"
       << endl;
  const double gravitationalConstant = 6.6726e-11;
  double mass1;
  double mass2;
  double radius;
  // User Inputs
  cout << "Enter the Mass of Mass1: ";
  cin >> mass1;
  cout << "Enter the Mass of Mass2: ";
  cin >> mass2;
  cout << "Enter the Radius: ";
  cin >> radius;
  // Calculate Answer
  double force = (gravitationalConstant * mass1 * mass2) / pow(radius, 2);
  cout << "The Force is: " << force << endl;

  return 0;
}