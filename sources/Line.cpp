#include "../headers/Line.hpp"

Line::Line(const double& x1, const double& y1, const double& x2, const double& y2, const string& color) : x1(x1), y1(y1), x2(x2), y2(y2), Shape(color) {}

Line::Line(const Line& other) : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2), Shape(other.color) {}

double Line::getX1() {

    return this->x1;
}

double Line::getY1() {

    return this->y1;
}

double Line::getX2() {

    return this->x2;
}

double Line::getY2() {

    return this->y2;
}

void Line::setX(const double& x1, const double& x2) {

    this->x1 = x1;
    this->x2 = x2;
}

void Line::setY(const double& y1, const double& y2) {

    this->y1 = y1;
    this->y2 = y2;
}

void Line::print() {

    cout << "line " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << color << '\n';

}

Line* Line::clone() const {

    return new Line(*this);
}

void Line::translate(const double& horizontal, const double& vertical) {

    setX(getX1() + horizontal, getX2() + horizontal);
    setY(getY1() + vertical, getY2() + vertical);
}

void Line::printInFile(ofstream& ofile) {

    ofile << "  <line x1=\""
          << x1
          << "\" y1=\""
          << y1
          << "\" x2=\""
          << x2
          << "\" y2=\""
          << y2 
          << "\" stroke=\""
          << color
          << "\" /> \n";

}

bool Line::isWithinRectangle(const double& rX, const double& rY, const double& rWidth, const double& rHeight) {

    return (x1 >= rX && x1 <= rX + rWidth && x2 >= rX && x2 <= rX + rWidth && y1 >= rY && y1 <= rY + rHeight && y2 >= rY && y2 <= rY + rHeight);
}


bool Line::isWithinCircle(const double& cX, const double& cY, const double& cRadius) {

    Point lA, lB, center;
    lA.x = x1;
    lA.y = y1;
    lB.x = x2;
    lB.y = y2;

    center.x = cX;
    center.y = cY;

    return (getDistance(lA, center) <= cRadius && getDistance(lB, center) <= cRadius);

}