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


}