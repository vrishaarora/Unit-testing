
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <stdint.h>


namespace shapes {

  class Triangle {
  public:
    enum class Kind : uint8_t {
      ISOSCELES,    // A triangle with two equal sides
      EQUILATERAL,  // A triangle with three equal sides
      SCALENE       // A triangle with no equal sides
    };

  private:
    const int side1;
    const int side2;
    const int side3;

  public:
    // Constructs a new triangle from the three side lengths passed in.
    // The sides must be in descending order.
    Triangle(int side1, int side2, int side3);

    // Return the sum of all sides of the triangle
    int    getPerimeter() const;

    // Return the area of the triangle
    double getArea() const;

    // Return the kind or classification of the triangle as determined
    // by its sides.
    Kind   getKind() const;

    // Return true if this triangle is isosceles.
    bool isIsosceles() const;

    // Return true if this triangle is equilateral.
    bool isEquilateral() const;
  };

}


#endif

