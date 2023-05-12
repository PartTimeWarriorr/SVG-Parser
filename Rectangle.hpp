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


    virtual void print() override final;
    virtual Rectangle* clone() const override final;

};

Rectangle::Rectangle(const double& x, const double& y, const double& width, const double& height) : x(x), y(y), width(width), height(height) {}

Rectangle::Rectangle(const Rectangle& other) : x(other.x), y(other.y), width(other.width), height(other.height) {}


void Rectangle::print() {

    cout << "X: " << x << " Y: " << y << '\n';
    cout << "Width: " << width << " Height: " << height << '\n';

}

Rectangle* Rectangle::clone() const {

    return new Rectangle(*this);
}