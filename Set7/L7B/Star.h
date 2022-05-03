#ifndef STAR_H
#define STAR_H

#include <SFML/Graphics.hpp>

class Star : public sf::CircleShape {
 public:
  Star();
  Star(const int WIDTH, const int HEIGHT, const float MAX_BRIGHTNESS);
  void setPosition(float xStar, float yStar);
  void setBrightness(float brightness);

 private:
  int windowHeight, windowWidth;
  float maxBrightness;
};
#endif