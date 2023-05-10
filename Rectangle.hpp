#pragma once

#include "Shape.hpp"

class Rectangle : public Shape {

    protected:

    double x, y;
    double width, height;

    public:

    Rectangle() = delete;
    Rectangle(const double&, const double&, const double&, const double&);
    Rectangle(const Rectangle&);
    virtual ~Rectangle() = default;

    virtual void addShape() override final;
    virtual void eraseShape() override final;

    virtual void print() override final;
    virtual Rectangle* clone() override final;

};

Rectangle::Rectangle(const double& x, const double& y, const double& width, const double& height) : x(x), y(y), width(width), height(height) {}

Rectangle::Rectangle(const Rectangle& other) : x(other.x), y(other.y), width(other.width), height(other.height) {}

void Rectangle::print() {

    cout << "X: " << x << " Y: " << y << '\n';
    cout << "Width: " << width << " Height: " << height << '\n';

}

Rectangle* Rectangle::clone() {

    return new Rectangle(*this);
}