#ifndef ISOSCELES_TRIANGLE_H
#define ISOSCELES_TRIANGLE_H

#include "Triangle.h"

class IsoscelesTriangle : public Triangle {
 public:
  bool setCoordinates(sf::Vector2f coordinates[3]);
};

#endif