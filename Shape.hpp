#pragma once

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;

class Shape {

    protected:

    string color;

    public:

    Shape(const string&);
    virtual ~Shape() = default;

    virtual void print() = 0;
    virtual Shape* clone() const = 0;
    virtual void translate(const double&, const double&) = 0;

};

Shape::Shape(const string& color) : color(color) {}