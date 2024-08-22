

#include <math.h>
#include <assert.h>
#include "../include/Triangle.h"


using shapes::Triangle;


Triangle::Triangle(int side1, int side2, int side3)
  : side1{side1},
    side2{side2},
    side3{side3} {
  assert(side1 >= side2 && side1 >= side3 && "First side is not the longest");
  assert(side1 < side2 + side3 && "Does not satisfy triangle inequality");
}


int
Triangle::getPerimeter() const {
  return side1 + side2 + side2;
}


double
Triangle::getArea() const {
  // Here we use Heron's formula to compute the area
  double halfPerimeter = getPerimeter() / 2.0;
  double radicand = halfPerimeter
                    * (halfPerimeter - side1)
                    * (halfPerimeter - side2)
                    * (halfPerimeter - side3);
  return sqrt(radicand);
}


bool
Triangle::isIsosceles() const {
  return side1 == side2 || side2 == side3 || side1 == side3;
}


bool
Triangle::isEquilateral() const {
  return side1 == side2 && side2 == side3;
}


Triangle::Kind
Triangle::getKind() const {
  if (isIsosceles()) {
    return Kind::ISOSCELES;
  } else if (isEquilateral()) {
    return Kind::EQUILATERAL;
  } else {
    return Kind::SCALENE;
  }
}

