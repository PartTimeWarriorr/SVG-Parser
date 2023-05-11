#pragma once

#include "Shape.hpp"

class Line : public Shape {

    protected:

    double x1, y1;
    double x2, y2;

    public:

    Line() = delete;
    Line(const double&, const double&, const double&, const double&);
    Line(const Line&);
    virtual ~Line() = default;


    virtual void print() override final;
    virtual Line* clone() const override final;

};

Line::Line(const double& x1, const double& y1, const double& x2, const double& y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}

Line::Line(const Line& other) : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2) {}

void Line::print() {

    cout << "X1: " << x1 << " Y1: " << y1 << '\n';
    cout << "X2: " << x2 << " Y2: " << y2 << '\n';

}

Line* Line::clone() const {

    return new Line(*this);
}