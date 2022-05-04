#include "Triangle.h"

Triangle::Triangle() {
  setColor(sf::Color::White);
  vertices = 3;
}

Triangle::~Triangle() { std::cout << "Triangle Deleted" << std::endl; }

void Triangle::setColor(const sf::Color COLOR) { triangleColor = COLOR; }

void Triangle::draw(sf::RenderTarget& window) {
  sf::ConvexShape newTriangle;
  newTriangle.setPointCount(3);
  for (int i = 0; i < 3; i++) {
    newTriangle.setPoint(i, vertexCoordinates[i]);
  }
  newTriangle.setFillColor(triangleColor);
  window.draw(newTriangle);
}
