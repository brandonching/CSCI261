/* CSCI 261: Assignment 7: Lab 7B - Starcraft
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description:
 */

// Libraries
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>  // For cin, cout, etc.
#include <sstream>

#include "LinkedList.hpp"
#include "Star.cpp"
#include "functions.cpp"

// Library namespace
using namespace std;

// Constants

int main(int argc, char* argv[]) {
  string filename;
  if (argc == 1) {
    filename = prompt_user_for_filename();
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

  // Create Star List
  LinkedList<Star>* starMap = new LinkedList<Star>;
  // Read in file
  string line;
  while (getline(fileIn, line)) {
    istringstream columns(line);
    float x, y, z, brightness;
    columns >> x;
    columns >> y;
    columns >> z;
    columns >> brightness;
    Star newStar(640, 640, 8);
    newStar.setPosition(x, y);
    newStar.setBrightness(brightness);
    starMap->pushBack(newStar);
  }

  // create a window
  sf::RenderWindow window(sf::VideoMode(640, 640), "Star Map");
  // while the window is open
  sf::Event event;
  while (window.isOpen()) {
    // clear any existing contents
    window.clear();
    for (unsigned int i = 0; i < starMap->size(); i++) {
      window.draw(starMap->at(i));
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

  return 0;
}