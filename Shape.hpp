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

    virtual ~Shape() = default;

    virtual void print() = 0;
    virtual Shape* clone() const = 0;

};