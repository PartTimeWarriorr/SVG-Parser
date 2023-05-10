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

    virtual void addShape() = 0;
    virtual void eraseShape() = 0;

    virtual ~Shape() = default;

    virtual void print() = 0;
    virtual Shape* clone() = 0;

};