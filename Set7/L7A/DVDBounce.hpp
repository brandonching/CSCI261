#ifndef DVDBOUNCE_H
#define DVDBOUNCE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class DVDBounce {
 public:
  DVDBounce();
  void moveLogo();
  void checkBoundry();
  void display();
  void setColor();
  sf::Sprite& Draw();

 private:
  float x, y;
  float xspeed, yspeed;
  sf::Texture texture;
  sf::Sprite logoSprite;
};

DVDBounce::DVDBounce() {
  x = 300;
  y = 200;
  xspeed = 0.125;
  yspeed = 0.125;
  if (!texture.loadFromFile("dvd_logo.png")) {
    std::cout << "Error Loading DVD Logo";
  }
  setColor();
  logoSprite.setTexture(texture);
  logoSprite.setPosition(x, y);
}

void DVDBounce::moveLogo() {
  x += xspeed;
  y += yspeed;
}

void DVDBounce::setColor() {
  int r = rand() % 256;
  int g = rand() % 256;
  int b = rand() % 256;
  logoSprite.setColor(sf::Color(r, g, b));
}

void DVDBounce::checkBoundry() {
  if ((x <= 180) || (x >= 720)) {
    xspeed = -xspeed;
    setColor();
  }
  if ((y <= 160) || (y >= 580)) {
    yspeed = -yspeed;
    setColor();
  }
}

void DVDBounce::display() { logoSprite.setPosition(x, y); }

sf::Sprite& DVDBounce::Draw() { return logoSprite; }

#endif