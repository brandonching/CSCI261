#ifndef EQUILATERAL_TRIANGLE_H
#define EQUILATERAL_TRIANGLE_H

#include "Triangle.h"

class EquilateralTriangle : public Triangle {
 public:
  bool setCoordinates(sf::Vector2f coordinates[3]);
};

#endif