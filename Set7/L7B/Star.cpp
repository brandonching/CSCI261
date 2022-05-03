#include "Star.h"

Star::Star() {
  windowHeight = 640;
  windowWidth = 640;
  maxBrightness = -1;
}

Star::Star(const int WIDTH, const int HEIGHT, const float MAX_BRIGHTNESS) {
  windowWidth = WIDTH;
  windowHeight = HEIGHT;
  maxBrightness = MAX_BRIGHTNESS;
  CircleShape::setPosition(0.0f,0.0f);
  setRadius(2);
}

void Star::setPosition(float xStar, float yStar) {
  float xPixel = (xStar + 1.0) * windowWidth / 2.0;
  float yPixel = (-yStar + 1.0) * windowHeight / 2.0;
  CircleShape::setPosition(xPixel, yPixel);
}

void Star::setBrightness(float brightness) {
  int invertedBrightness = maxBrightness - brightness;
  int shadeOfGray = (int)((255.0 * invertedBrightness) / maxBrightness);
  setFillColor(sf::Color(shadeOfGray, shadeOfGray, shadeOfGray));
}