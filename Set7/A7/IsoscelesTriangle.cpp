#include "IsoscelesTriangle.h"

#include <cmath>

bool IsoscelesTriangle::setCoordinates(sf::Vector2f coordinates[3]) {
  // Compute Triangle Side Lengths
  float sideLength[3] = {};
  sideLength[0] = std::abs(sqrt(pow((coordinates[0].x - coordinates[1].x), 2) +
                                pow((coordinates[0].y - coordinates[1].y), 2)));
  sideLength[1] = std::abs(sqrt(pow((coordinates[1].x - coordinates[2].x), 2) +
                                pow((coordinates[1].y - coordinates[2].y), 2)));
  sideLength[2] = std::abs(sqrt(pow((coordinates[2].x - coordinates[0].x), 2) +
                                pow((coordinates[2].y - coordinates[0].y), 2)));

  // Check if Triangle has positive length sides
  bool triangleIsValid = true;
  for (int side = 0; side < 3; side++) {
    if (sideLength[side] <= 0) {
      triangleIsValid = false;
    }
  }
  if (triangleIsValid) {  // Keep checking if currently valid
    // Check is sides can acutally make a triangle
    float longLeg = sideLength[0];
    float otherLegs = 0;
    for (int i = 1; i < 3; i++) {
      // if this leg is longer, than this is not longest and the old long moves
      // to other leg
      if (sideLength[i] > longLeg) {
        otherLegs += longLeg;
        longLeg = sideLength[i];
      } else {  // this leg is not longest so just add to other leg
        otherLegs += sideLength[i];
      }
    }

    // Acutally check is the legs can make a triangle
    if (otherLegs > longLeg) {
      // Triangle is Still Valid
      if (!((sideLength[0] == sideLength[1]) ||
            (sideLength[0] == sideLength[2]) ||
            (sideLength[1] == sideLength[2]))) {
        triangleIsValid = false;
      }
    } else {
      triangleIsValid = false;
    }
  }
  // If valid triangle do somethings and return true
  if (triangleIsValid) {
    // set cordinates
    for (int i = 0; i < 3; i++) {
      vertexCoordinates[i] = coordinates[i];
    }
    return true;
  }

  // Return false is default state for non valid triangles
  return false;
}
