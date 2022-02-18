/* CSCI 261: Assignment 2: Lab 2C - Coordinate Converter
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description: Use pass by refrence to convert between polar and cartesian
 * coordiantes
 */

// Libraries
#include <math.h>

#include <iostream>  // For cin, cout, etc.

// Library namespace
using namespace std;

// Constants

void polar_to_cartesian(const double radius, const double angle, double& xCoord,
                        double& yCoord) {
  xCoord = radius * cos(angle);
  yCoord = radius * sin(angle);
}

void cartesian_to_polar(const double xCoord, const double yCoord,
                        double& radius, double& angle) {
  radius = sqrt(pow(xCoord, 2) + pow(yCoord, 2));
  angle = atan(yCoord / xCoord);
}

int main() {
  bool mode;
  double radius, angle, xCoord, yCoord;
  cout << "Wlecome to the Polar-Cartesian Conversion Calculator" << endl
       << "[0] - Polar to Cartesian - (r, θ) -> (x, y)" << endl
       << "[1] - Cartesian to Polar - (x, y) -> (r, θ)" << endl
       << "Please Select a Conversion Mode [0/1] ";
  cin >> mode;
  cout << endl;

  // Based on user input convert coordinates correctly
  if (mode) {
    cout << "Conveting Cartesian to Polar - (x, y) -> (r, θ)" << endl
         << "X-Cord: ";
    cin >> xCoord;
    cout << "Y-Cord: ";
    cin >> yCoord;
    cartesian_to_polar(xCoord, yCoord, radius, angle);
    cout << "Radius: " << radius << endl << "Angle(radians): " << angle << endl;
  } else {
    cout << "Converting Polar to Cartesian - (r, θ) -> (x, y)" << endl
         << "Radius: ";
    cin >> radius;
    cout << "Angle(radians): ";
    cin >> angle;
    polar_to_cartesian(radius, angle, xCoord, yCoord);
    cout << "X-Cord: " << xCoord << endl << "Y-Cord: " << yCoord << endl;
  }
  return 0;
}