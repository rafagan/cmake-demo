#include "Circle.h"
#include <numbers>

Circle::Circle(const double r) : radius(r) {}

double Circle::getArea() const {
    return std::numbers::pi * radius * radius;
}

double Circle::getPerimeter() const {
    return 2 * std::numbers::pi * radius;
}
