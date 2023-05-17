#pragma once

#include "Shape.hpp"


class Circle : public Shape {

    protected:

    double cx, cy;
    double radius;

    public:

    Circle() = delete;
    Circle(const double&, const double&, const double&, const string&);
    Circle(const Circle&);
    virtual ~Circle() = default;

    double getX();
    double getY();

    void setX(const double&);
    void setY(const double&);

    virtual void print() override final;
    virtual Circle* clone() const override final;
    virtual void translate(const double&, const double&) override final;

};

Circle::Circle(const double& cx, const double& cy, const double& radius, const string& color) : cx(cx), cy(cy), radius(radius), Shape(color) {}

Circle::Circle(const Circle& other) : cx(other.cx), cy(other.cy), radius(other.radius), Shape(other.color) {}

double Circle::getX() {

    return this->cx;
}

double Circle::getY() {

    return this->cy;
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