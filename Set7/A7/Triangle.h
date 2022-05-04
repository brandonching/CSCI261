#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <SFML/Graphics.hpp>
#include <iostream>
class Triangle {
 public:
  Triangle();
  ~Triangle();
  void setColor(const sf::Color COLOR);
  void draw(sf::RenderTarget& window);
  virtual bool setCoordinates(sf::Vector2f coordinates[3]) = 0;

 protected:
  int vertices;
  sf::Vector2f vertexCoordinates[3] = {};

 private:
  sf::Color triangleColor;
};

#endif
