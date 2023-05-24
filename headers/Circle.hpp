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
    double getRadius();

    void setX(const double&);
    void setY(const double&);

    virtual void print() override final;
    virtual Circle* clone() const override final;
    virtual void translate(const double&, const double&) override final;
    virtual void printInFile(ofstream&) override final;
    virtual bool isWithinRectangle(const double&, const double&, const double&, const double&) override final;
    virtual bool isWithinCircle(const double&, const double&, const double&) override final;

};

