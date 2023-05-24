#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../Rectangle.hpp"

TEST_CASE("Test getters") {

    rns::Rectangle r1(2, 3, 40, 60, "black");

    REQUIRE_EQ(r1.getX(), 2);
    REQUIRE_EQ(r1.getY(), 3);
    REQUIRE_EQ(r1.getWidth(), 40);
    REQUIRE_EQ(r1.getHeight(), 60);
    
}

TEST_CASE("Test copy constructor") {

    rns::Rectangle r1(2, 3, 40, 60, "black");
    rns::Rectangle r2(r1);

    REQUIRE_EQ(r1.getX(), r2.getX());
    REQUIRE_EQ(r1.getY(), r2.getY());
    REQUIRE_EQ(r1.getWidth(), r2.getWidth());
    REQUIRE_EQ(r1.getHeight(), r2.getHeight());

}

TEST_CASE("Test setters") {

    rns::Rectangle r1(2, 4, 50, 20, "black");

    r1.setX(10);
    r1.setY(30);

    REQUIRE_EQ(r1.getX(), 10);
    REQUIRE_EQ(r1.getY(), 30);

}

TEST_CASE("Test clone function") {

    rns::Rectangle r1(2, 4, 50, 20, "black");

    REQUIRE_EQ(r1.clone()->getX(), 2);
    REQUIRE_EQ(r1.clone()->getY(), 4);
    REQUIRE_EQ(r1.clone()->getWidth(), 50);
    REQUIRE_EQ(r1.clone()->getHeight(), 20);

}

TEST_CASE("Test translate function") {

    rns::Rectangle r1(2, 4, 50, 20, "black");

    r1.translate(10, 30);

    REQUIRE_EQ(r1.getX(), 12);
    REQUIRE_EQ(r1.getY(), 34);

}

TEST_CASE("Test within function, case 1") {

    rns::Rectangle r1(2, 4, 10, 10, "black");

    REQUIRE_FALSE(r1.isWithinCircle(2, 4, 2));
    REQUIRE_FALSE(!r1.isWithinCircle(2, 4, 50));
}

TEST_CASE("Test within function, case 2") {

    rns::Rectangle r1(2, 4, 10, 10, "black");

    REQUIRE_FALSE(r1.isWithinRectangle(0, 0, 20, 5));
    REQUIRE_FALSE(!r1.isWithinRectangle(0, 0, 100, 100));
}