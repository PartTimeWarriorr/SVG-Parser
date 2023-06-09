#include "../headers/Circle.hpp"

Circle::Circle(const double& cx, const double& cy, const double& radius, const string& color) : cx(cx), cy(cy), radius(radius), Shape(color) {}

Circle::Circle(const Circle& other) : cx(other.cx), cy(other.cy), radius(other.radius), Shape(other.color) {}

double Circle::getX() {

    return this->cx;
}

double Circle::getY() {

    return this->cy;
}

double Circle::getRadius() {

    return this->radius;
}

void Circle::setX(const double& cx) {

    this->cx = cx;
}

void Circle::setY(const double& cy) {

    this->cy = cy;
}

void Circle::print() {

    cout << "circle " << cx << ' ' << cy << ' ' << radius << ' ' << color << '\n';
}

Circle* Circle::clone() const {

    return new Circle(*this);
}

void Circle::translate(const double& horizontal, const double& vertical) {

    setX(getX() + horizontal);
    setY(getY() + vertical);
}

void Circle::printInFile(ofstream& ofile) {

    ofile << "  <circle cx=\""
          << cx
          << "\" cy=\""
          << cy
          << "\" r=\""
          << radius
          << "\" fill=\""
          << color
          << "\" /> \n";
          
} 

bool Circle::isWithinRectangle(const double& rX, const double& rY, const double& rWidth, const double& rHeight) {

    return (cx - radius >= rX && cx - radius <= rX + rWidth && cx + radius >= rX && cx + radius <= rX + rWidth &&
            cy - radius >= rY && cy - radius <= rY + rHeight && cy + radius >= rY && cy + radius <= rY + rHeight);
}

bool Circle::isWithinCircle(const double& cX, const double& cY, const double& cRadius) {

    Point center, otherCenter;
    center.x = cx;
    center.y = cy;
    otherCenter.x = cX;
    otherCenter.y = cY;

    return (getDistance(center, otherCenter) + radius <= cRadius);
}