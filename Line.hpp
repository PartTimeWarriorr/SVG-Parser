#pragma once

#include "Shape.hpp"

class Line : public Shape {

    protected:

    double x1, y1;
    double x2, y2;

    public:

    Line() = delete;
    Line(const double&, const double&, const double&, const double&, const string&);
    Line(const Line&);
    virtual ~Line() = default;

    double getX1();
    double getY1();
    double getX2();
    double getY2();

    void setX(const double&, const double&);
    void setY(const double&, const double&);


    virtual void print() override final;
    virtual Line* clone() const override final;
    virtual void translate(const double&, const double&) override final;
    virtual void printInFile(ofstream&) override final;

};

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