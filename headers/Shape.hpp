#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Point.hpp"
#include <cmath>

using std::string;
using std::vector;
using std::cout;
using std::ifstream;
using std::ofstream;

class Shape {

    protected:

    string color;

    public:

    Shape(const string&);
    virtual ~Shape() = default;

    virtual void print() = 0;
    virtual Shape* clone() const = 0;
    virtual void translate(const double&, const double&) = 0;
    virtual void printInFile(ofstream&) = 0;
    virtual bool isWithinRectangle(const double&, const double&, const double&, const double&) = 0;
    virtual bool isWithinCircle(const double&, const double&, const double&) = 0;

    double getDistance(const Point&, const Point&);
    
};
