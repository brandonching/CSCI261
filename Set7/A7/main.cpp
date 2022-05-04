/* CSCI 261: Assignment 7: A7 - Triangle Land
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description: Create multiple classes with inheratance and use SFML to draw a
 * picture from an input file
 */

// Libraries
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>  // For cin, cout, etc.
#include <sstream>

#include "EquilateralTriangle.h"
#include "IsoscelesTriangle.h"
#include "LinkedList.hpp"
#include "ScaleneTriangle.h"
#include "Triangle.h"

// Library namespace
using namespace std;

// Constants
bool open_file(ifstream& inputFile, const string FILENAME) {
  // Open File
  inputFile.open(FILENAME);

  // Check for an error
  if (inputFile.fail()) {
    cerr << "Error opeing file." << endl;
    return 0;
  }
  // retrun 1 if open sucessful
  return 1;
}

int main(int argc, char* argv[]) {
  string filename;
  if (argc == 1) {
    cout << "Please Provide a File Name: ";
    cin >> filename;
  } else if (argc == 2) {
    filename = argv[1];
  } else {
    cerr << "Usage: " << argv[0] << " [filename]" << endl;
    cerr << "  filename   - optional file to open upon start" << endl;
    return -2;
  }

  // open file for parsing
  ifstream fileIn;
  if (!open_file(fileIn, filename)) {
    cerr << "Could not open file \"" << filename << "\"" << endl;
    cerr << "Shutting down" << endl;
    return -1;
  } else {
    cout << "Opening file " << filename << endl
         << "File successfully opened!" << endl;
  }

  // Process Triangles
  LinkedList<Triangle*>* triangleList = new LinkedList<Triangle*>;
  string line;
  // Read each line
  while (getline(fileIn, line)) {
    // Convert each line into triangle data
    istringstream rawTriangle(line);
    char triangleType;
    rawTriangle >> triangleType;
    double x1, y1, x2, y2, x3, y3, r, g, b;
    rawTriangle >> x1;
    rawTriangle >> y1;
    rawTriangle >> x2;
    rawTriangle >> y2;
    rawTriangle >> x3;
    rawTriangle >> y3;
    rawTriangle >> r;
    rawTriangle >> g;
    rawTriangle >> b;
    sf::Vector2f triangleVerticies[3] = {
        sf::Vector2f(x1, y1), sf::Vector2f(x2, y2), sf::Vector2f(x3, y3)};
    sf::Color tirangleColor = sf::Color(r, g, b);

    // make correct triangle type in list
    if (triangleType == 'S') {
      ScaleneTriangle* newTriangle = new ScaleneTriangle;
      if (newTriangle->setCoordinates(triangleVerticies)) {
        newTriangle->setColor(tirangleColor);
        triangleList->pushBack(newTriangle);
      } else {
        cout << "triangle is invalid - " << line << endl;
      }

    } else if (triangleType == 'I') {
      IsoscelesTriangle* newTriangle = new IsoscelesTriangle;
      if (newTriangle->setCoordinates(triangleVerticies)) {
        newTriangle->setColor(tirangleColor);
        triangleList->pushBack(newTriangle);
      } else {
        cout << "triangle is invalid - " << line << endl;
      }
    } else if (triangleType == 'E') {
      EquilateralTriangle* newTriangle = new EquilateralTriangle;
      if (newTriangle->setCoordinates(triangleVerticies)) {
        newTriangle->setColor(tirangleColor);
        triangleList->pushBack(newTriangle);
      } else {
        cout << "triangle is invalid - " << line <<endl;
      }
    }
  }

  // create a window
  sf::RenderWindow window(sf::VideoMode(640, 640), "Triangle Land");
  // while the window is open
  sf::Event event;
  while (window.isOpen()) {
    // clear any existing contents
    window.clear();

    for (unsigned int i = 0; i < triangleList->size();i++){
      triangleList->at(i)->draw(window);
    }
      // display the current contents of the window
      window.display();

    // check if any events happened since the last time checked
    while (window.pollEvent(event)) {
      // if event type corresponds to pressing window X
      if (event.type == sf::Event::Closed) {
        // tell the window to close
        window.close();
      }
      // check addition event types to handle additional events
    }
  }

  delete triangleList;
  return 0;
}