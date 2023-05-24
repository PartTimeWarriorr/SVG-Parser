#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../Circle.hpp"

TEST_CASE("Test getters") {

    Circle c1(2, 4, 30, "black");

    REQUIRE_EQ(c1.getX(), 2);
    REQUIRE_EQ(c1.getY(), 4);
    REQUIRE_EQ(c1.getRadius(), 30);

}

TEST_CASE("Test copy constructor") {

    Circle c1(2, 4, 30, "black");
    Circle c2(c1);

    REQUIRE_EQ(c2.getX(), c1.getX());
    REQUIRE_EQ(c2.getY(), c1.getY());
    REQUIRE_EQ(c2.getRadius(), c1.getRadius());

}

TEST_CASE("Test setters") {

    Circle c1(2, 4, 30, "black");

    c1.setX(8);
    c1.setY(10);

    REQUIRE_EQ(c1.getX(), 8);
    REQUIRE_EQ(c1.getY(), 10);
    REQUIRE_EQ(c1.getRadius(), 30);
}

TEST_CASE("Test clone function") {

    Circle c1(2, 4, 30, "black");

    REQUIRE_EQ(c1.clone()->getX(), 2);
    REQUIRE_EQ(c1.clone()->getY(), 4);
    REQUIRE_EQ(c1.clone()->getRadius(), 30);
}

TEST_CASE("Test translate function") {

    Circle c1(2, 4, 30, "black");

    c1.translate(10, 10);

    REQUIRE_EQ(c1.getX(), 12);
    REQUIRE_EQ(c1.getY(), 14);
}

TEST_CASE("Test within function, case 1") {

    Circle c1(2, 4, 30, "black");
    
    REQUIRE_FALSE(c1.isWithinCircle(2, 4, 10));
    REQUIRE_FALSE(!c1.isWithinCircle(2, 4, 50));
}

TEST_CASE("Test within function, case 2") {

    Circle c1(10, 10, 5, "black");

    REQUIRE_FALSE(c1.isWithinRectangle(5, 5, 1, 1));
    REQUIRE_FALSE(!c1.isWithinRectangle(5, 5, 10, 10));
}