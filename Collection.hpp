#pragma once

#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Line.hpp"


class Collection {

    private:

    vector<Shape*> shapes;

    public:

    Collection() = default;

    void addShape(const Shape*);
    void eraseShape(unsigned int);

    void printCollection();
};


void Collection::printCollection() {

    for(size_t i = 0; i < shapes.size(); ++i)
        shapes[i]->print();
    
}


void Collection::addShape(const Shape* shape) {

    shapes.push_back(shape->clone());
}

void Collection::eraseShape(unsigned int index) {

    shapes.erase(shapes.begin() + index);
}