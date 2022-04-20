#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
  // create a window
  RenderWindow window(VideoMode(640, 640), "SFML Test");

  /////////////////////////////////////
  // BEGIN ANY FILE LOADING

  // perform any file processing once before draw loop begins

  //  END  ANY FILE LOADING
  /////////////////////////////////////

  // create an event object once to store future events
  Event event;

  // while the window is open
  while (window.isOpen()) {
    // clear any existing contents
    window.clear();

    /////////////////////////////////////
    // BEGIN DRAWING HERE

    // place any draw commands here to display in the window

    //  END  DRAWING HERE
    /////////////////////////////////////

    // display the current contents of the window
    window.display();

    /////////////////////////////////////
    // BEGIN EVENT HANDLING HERE
    // check if any events happened since the last time checked
    while (window.pollEvent(event)) {
      // if event type corresponds to pressing window X
      if (event.type == Event::Closed) {
        // tell the window to close
        window.close();
      }
      // check addition event types to handle additional events
    }
    //  END  EVENT HANDLING HERE
    /////////////////////////////////////
  }

  return 0;
}