#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../headers/Line.hpp"

TEST_CASE("Test getters") {

    Line l1(2, 3, 4, 5, "black");

    REQUIRE_EQ(l1.getX1(), 2);
    REQUIRE_EQ(l1.getY1(), 3);
    REQUIRE_EQ(l1.getX2(), 4);
    REQUIRE_EQ(l1.getY2(), 5);

}

TEST_CASE("Test copy constructor") {

    Line l1(2, 3, 4, 5, "black");
    Line l2(l1);

    REQUIRE_EQ(l2.getX1(), l1.getX1());
    REQUIRE_EQ(l2.getY1(), l1.getY1());
    REQUIRE_EQ(l2.getX2(), l1.getX2());
    REQUIRE_EQ(l2.getY2(), l1.getY2());

}

TEST_CASE("Test setters") {

    Line l1(2, 3, 4, 5, "black");

    l1.setX(10, 10.5);

    REQUIRE_EQ(l1.getX1(), 10);
    REQUIRE_EQ(l1.getX2(), 10.5);

    l1.setY(20, 20.5);

    REQUIRE_EQ(l1.getY1(), 20);
    REQUIRE_EQ(l1.getY2(), 20.5);

}

TEST_CASE("Test clone function") {

    Line l1(2, 3, 4, 5, "black");

    REQUIRE_EQ(l1.clone()->getX1(), 2);
    REQUIRE_EQ(l1.clone()->getY1(), 3);
    REQUIRE_EQ(l1.clone()->getX2(), 4);
    REQUIRE_EQ(l1.clone()->getY2(), 5);

}

TEST_CASE("Test translate function") {

    Line l1(2, 3, 4, 5, "black");

    l1.translate(10, 20);
    
    REQUIRE_EQ(l1.getX1(), 12);
    REQUIRE_EQ(l1.getX2(), 14);
    REQUIRE_EQ(l1.getY1(), 23);
    REQUIRE_EQ(l1.getY2(), 25);

}

TEST_CASE("Test within function, case 1") {

    Line l1(2, 3, 4, 5, "black");

    REQUIRE(!l1.isWithinCircle(2, 3, 1));
    REQUIRE(l1.isWithinCircle(3, 3, 10));
}

TEST_CASE("Test within function, case 2") {

    Line l1(2, 3, 4, 5, "black");

    REQUIRE(!l1.isWithinRectangle(100, 100, 20, 25));
    REQUIRE(l1.isWithinRectangle(0, 0, 10, 10));
}