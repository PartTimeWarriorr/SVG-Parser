#pragma once

#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Line.hpp"


class Collection {

    private:

    vector<Shape*> shapes;

    public:

    Collection() = default;
    Collection(vector<Shape*>) = delete;
    Collection(const Collection&) = delete;

    void addShape(const Shape*);
    void eraseShape(unsigned int);

    void printCollection();

    vector<Shape*> getVector() const;

    void translateShape(const int, const double&, const double&);

    void clearShapes();
    void printAllInFile(ofstream&);
};

