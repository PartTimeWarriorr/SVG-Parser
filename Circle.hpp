#pragma once

#include "Shape.hpp"


class Circle : public Shape {

    protected:

    double cx, cy;
    double radius;

    public:

    Circle() = delete;
    Circle(const double&, const double&, const double&);
    Circle(const Circle&);
    virtual ~Circle() = default;


    virtual void print() override final;
    virtual Circle* clone() const override final;

};

Circle::Circle(const double& cx, const double& cy, const double& radius) : cx(cx), cy(cy), radius(radius) {}

Circle::Circle(const Circle& other) : cx(other.cx), cy(other.cy), radius(other.radius) {}


void Circle::print() {

    cout << "CX: " << cx << " CY: " << cy << '\n';
    cout << "Radius: " << radius << '\n';

}

Circle* Circle::clone() const {

    return new Circle(*this);
}