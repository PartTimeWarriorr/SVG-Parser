#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../headers/Collection.hpp"

TEST_CASE("Adding and erasing shape") {

    Collection c;
    Line l1(2, 3, 4, 5, "black");

    c.addShape(&l1);

    REQUIRE(!c.getVector().empty());
    
    c.eraseShape(0);

    REQUIRE(c.getVector().empty());
}

TEST_CASE("Clear shapes") {

    Collection c;
    Line l1(2, 3, 4, 5, "black");
    Circle c1(3, 4, 20, "violet");

    c.addShape(&l1);
    c.addShape(&c1);

    REQUIRE(!c.getVector().empty());

    c.clearShapes();

    REQUIRE(c.getVector().empty());
}