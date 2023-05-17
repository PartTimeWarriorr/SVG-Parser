#pragma once

#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Line.hpp"


class Collection {

    public:

    vector<Shape*> shapes;

    public:

    Collection() = default;

    void addShape(const Shape*);
    void eraseShape(unsigned int);

    void printCollection();

    vector<Shape*> getVector() const;

    void translateShape(const int, const double&, const double&);
};


void Collection::printCollection() {

    for(size_t i = 0; i < shapes.size(); ++i) {
        cout << i + 1 << ". ";
        shapes[i]->print();
    }
}


void Collection::addShape(const Shape* shape) {

    shapes.push_back(shape->clone());
}

void Collection::eraseShape(unsigned int index) {

    shapes.erase(shapes.begin() + index);
}

vector<Shape*> Collection::getVector() const {

    return shapes;
}

void Collection::translateShape(const int index, const double& horizontal, const double& vertical) {

    shapes[index]->translate(horizontal, vertical);
}