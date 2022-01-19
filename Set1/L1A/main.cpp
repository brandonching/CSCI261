/* CSCI 261 Set 1: Lab 1A - Math Equation Solver
 *
 * Author: Brandon Ching
 * Resources: w3school for pow() function
 * 
 * Program has two "caculators", one which calculates the current in Ohms law and the other calculates gravitational force  
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <math.h>   // For pow

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants below this comment.

// Must have a function named "main", which is the starting point of a C++ program.
int main()
{

    /******** INSERT YOUR CODE BELOW HERE ********/

    double voltage;
    double resistance;
    cout << "Calculating Ohm's Law --- I = V/R" << endl;
    cout << "Enter the Voltage: ";
    cin >> voltage;
    cout << "Enter the Resistance: ";
    cin >> resistance;
    double current = voltage / resistance;
    cout << "The Current is: " << current << "A" << endl;

    cout << "Calculating Newton's Law of Universal Gravitational --- F = Gm1m2/r^2" << endl;
    const double gravitationalConstant = 6.6726e-11;
    double mass1;
    double mass2;
    double radius;
    cout << "Enter the Mass of Mass1: ";
    cin >> mass1;
    cout << "Enter the Mass of Mass2: ";
    cin >> mass2;
    cout << "Enter the Radius: ";
    cin >> radius;
    double force = (gravitationalConstant * mass1 * mass2) / pow(radius, 2);
    cout << "The Force is: " << force << endl;

    /******** INSERT YOUR CODE ABOVE HERE ********/

    return 0; // signals the operating system that our program ended OK.
}