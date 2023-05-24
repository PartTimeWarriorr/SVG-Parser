#include "../headers/Shape.hpp"

Shape::Shape(const string& color) : color(color) {}

double Shape::getDistance(const Point& a, const Point& b) {

    return sqrt(pow(b.x - a.x, 2.0) + pow(b.y - a.y, 2.0));
}