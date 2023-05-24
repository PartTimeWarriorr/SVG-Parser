#pragma once

#include "Shape.hpp"

namespace rns {


class Rectangle : public Shape {

    protected:

    double x, y;
    double width, height;

    public:

    Rectangle() = delete;
    Rectangle(const double&, const double&, const double&, const double&, const string&);
    Rectangle(const Rectangle&);
    virtual ~Rectangle() = default;

    double getX();
    double getY();
    double getWidth();
    double getHeight();

    void setX(const double&);
    void setY(const double&);

    virtual void print() override final;
    virtual Rectangle* clone() const override final;
    virtual void translate(const double&, const double&) override final;
    virtual void printInFile(ofstream&) override final;
    virtual bool isWithinRectangle(const double&, const double&, const double&, const double&) override final;
    virtual bool isWithinCircle(const double&, const double&, const double&) override final;

};

Rectangle::Rectangle(const double& x, const double& y, const double& width, const double& height, const string& color) : x(x), y(y), width(width), height(height), Shape(color) {}

Rectangle::Rectangle(const Rectangle& other) : x(other.x), y(other.y), width(other.width), height(other.height), Shape(other.color) {}

double Rectangle::getX() {

    return this->x;
}

double Rectangle::getY() {

    return this->y;
}

double Rectangle::getWidth() {

    return this->width;
}

double Rectangle::getHeight() {

    return this->height;
}

void Rectangle::setX(const double& x) {

    this->x = x;
}

void Rectangle::setY(const double& y) {

    this->y = y;
}

void Rectangle::print() {

    cout << "rectangle " << x << ' ' << y << ' ' << width << ' ' << height << ' ' << color << '\n';
}

Rectangle* Rectangle::clone() const {

    return new Rectangle(*this);
}

void Rectangle::translate(const double& horizontal, const double& vertical) {

    setX(getX() + horizontal);
    setY(getY() + vertical);
}

void Rectangle::printInFile(ofstream& ofile) {

    ofile << "  <rect x=\"" 
              << x 
              << "\" y=\"" 
              << y 
              << "\" width=\"" 
              << width 
              << "\" height=\"" 
              << height 
              << "\" fill=\"" 
              << color 
              << "\" /> \n";
              
} 

bool Rectangle::isWithinRectangle(const double& rX, const double& rY, const double& rWidth, const double& rHeight) {

    return (x >= rX && x <= rX + rWidth && x + width >= rX && x + width <= rX + rWidth && 
            y >= rY && y <= rY + rHeight && y + height >= rY && y + height <= rY + rHeight);
}

bool Rectangle::isWithinCircle(const double& cX, const double& cY, const double& cRadius) {

    Point A, B, C, D, center;
    A.x = x;
    A.y = y;
    B.x = x + width;
    B.y = y;
    C.x = x + width;
    C.y = y + height;
    D.x = x;
    D.y = y + height;

    center.x = cX;
    center.y = cY;

    return (getDistance(A, center) <= cRadius && getDistance(B, center) <= cRadius && getDistance(C, center) <= cRadius && getDistance(D, center) <= cRadius);
}

}