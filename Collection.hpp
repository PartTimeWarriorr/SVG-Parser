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

void Collection::clearShapes() {

    shapes.clear();
}


void Collection::printAllInFile(ofstream& ofile) {

    for(size_t i = 0; i < shapes.size(); ++i)
        shapes[i]->printInFile(ofile);

}