/* CSCI 261: Assignment 7 - Lab7A - SFML Drawing
 *
 * Author: Brandon Ching
 * Resources: Some googleing to figure out animation and using dvd logo png so I
 * didnt have to make that
 *
 * Description: Use SFML to draw and animate a picture
 */

#include <SFML/Graphics.hpp>
#include <ctime>

#include "DVDBounce.hpp"
using namespace sf;

int main() {
  // create a window
  int windowWidth = 1000;
  int windowHeight = 1000;
  RenderWindow window(VideoMode(windowWidth, windowHeight),
                      "Bouncing DVD Logo");

  srand(time(0));
  rand();
  DVDBounce DVDLogo;
  Event event;

  // while the window is open
  while (window.isOpen()) {
    // clear any existing contents
    window.clear();

    // Set Background to White
    RectangleShape background;
    background.setSize(Vector2f(windowWidth, windowHeight));
    background.setPosition(0, 0);
    background.setFillColor(Color::White);
    window.draw(background);

    // Create TV
    RectangleShape CRT;
    CRT.setSize(Vector2f(840, 840));
    CRT.setPosition((windowWidth - 840) / 2, (windowWidth - 840) / 2);
    CRT.setFillColor(Color(113, 121, 126));
    window.draw(CRT);

    // Add scsreen to TV
    RectangleShape screen;
    screen.setSize(Vector2f(640, 480));
    screen.setPosition((windowWidth - 640) / 2, (windowHeight - 480) / 2 - 100);
    screen.setFillColor(Color::Black);
    window.draw(screen);

    // Speakers
    for (int i = ((windowHeight - 480) / 2 + 400); i < 900; i += 30) {
      RectangleShape speaker;
      speaker.setSize(Vector2f(300, 20));
      speaker.setPosition((windowWidth - 640) / 2, i);
      speaker.setFillColor(Color::Black);
      window.draw(speaker);
    }

    // Dial
    CircleShape dial;
    dial.setPosition((windowWidth - 640) / 2 + 400,
                     (windowHeight - 480) / 2 + 415);
    dial.setRadius(100);
    dial.setFillColor(Color::Black);
    window.draw(dial);

    // Move DVD Logo
    DVDLogo.moveLogo();
    DVDLogo.checkBoundry();
    DVDLogo.display();
    window.draw(DVDLogo.Draw());

    // display the current contents of the window
    window.display();

    // check if any events happened since the last time checked
    while (window.pollEvent(event)) {
      // if event type corresponds to pressing window X
      if (event.type == Event::Closed) {
        // tell the window to close
        window.close();
      }
      // check addition event types to handle additional events
    }
  }

  return 0;
}