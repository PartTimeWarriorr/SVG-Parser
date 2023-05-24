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
    virtual bool isWithinRectangle(const double&, const double&, const double&, const double&) override final;
    virtual bool isWithinCircle(const double&, const double&, const double&) override final;

};

