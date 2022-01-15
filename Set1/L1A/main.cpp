/* CSCI 261 Lab 1A: XXXX (_GIVE_BRIEF_DESCRIPTION_HERE_)
 *
 * Author: Brandon Ching
 *
 * More complete description here...
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants below this comment.

// Must have a function named "main", which is the starting point of a C++ program.
int main()
{

    /******** INSERT YOUR CODE BELOW HERE ********/

    cout << "Hello world!" << endl; // print Hello world! to the screen

    double voltage;
    double resistance;
    cout << "Calculating Ohm's Law --- I = V/R" << endl;
    cout << "Enter the Voltage: ";
    cin >> voltage;
    cout << "Enter the Resistance: ";
    cin >> resistance;
    double current = voltage / resistance;
    cout << "The Current is: " << current << "A" << endl;

    const double gravitationalConstant = 6.6743e-11;
    int mass1;
    int mass2;
    int radius;
    cout << "Enter the Mass of Mass1: ";
    cin >> mass1;
    cout << "Enter the Mass of Mass2: ";
    cin >> mass2;
    cout << "Enter the Radius: ";
    cin >> radius;
    double force = gravitationalConstant * mass1 * mass2 / (radius ^ 2);
    cout << "The Force is: " << force << endl;

    /******** INSERT YOUR CODE ABOVE HERE ********/

    return 0; // signals the operating system that our program ended OK.
}