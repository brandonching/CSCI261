#ifndef SCALENE_TRIANGLE_H
#define SCALENE_TRIANGLE_H

#include "Triangle.h"

class ScaleneTriangle : public Triangle {
 public:
  bool setCoordinates(sf::Vector2f coordinates[3]);
};

#endif