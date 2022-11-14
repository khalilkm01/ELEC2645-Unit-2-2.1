#include "circle.h"


// constructor using uniform list initialisation
Circle::Circle(float radius) : _radius(radius) {}
// accessor method to get area
float Circle::get_area() {
  _area = PI * _radius * _radius;
  return _area;
}
//accessor method to get circumference
float Circle::get_circumference() {
  return PI * 2 * _radius;
}