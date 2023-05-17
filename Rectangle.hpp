#pragma once

#include "Shape.hpp"


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

    void setX(const double&);
    void setY(const double&);

    virtual void print() override final;
    virtual Rectangle* clone() const override final;
    virtual void translate(const double&, const double&) override final;

};

Rectangle::Rectangle(const double& x, const double& y, const double& width, const double& height, const string& color) : x(x), y(y), width(width), height(height), Shape(color) {}

Rectangle::Rectangle(const Rectangle& other) : x(other.x), y(other.y), width(other.width), height(other.height), Shape(other.color) {}

double Rectangle::getX() {

    return this->x;
}

double Rectangle::getY() {

    return this->y;
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