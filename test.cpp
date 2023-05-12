// #include "NewCommandLine.hpp"
// #include "Collection.hpp"
#include "CommandLine.hpp"


int main() {

    Rectangle r1(2, 3, 10, 100);
    Circle c1(1, 4, 200);

    // Collection collection;

    // collection.addShape(&r1);
    // collection.addShape(&c1);

    CommandLine::collection.addShape(&r1);
    CommandLine::collection.addShape(&c1);

    // collection.eraseShape(0);
    // collection.eraseShape(0);

    CommandLine::collection.printCollection();

}