#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../headers/Circle.hpp"

TEST_CASE("Test Point struct") {

    Point A;
    A.x = 2;
    A.y = 3;

    REQUIRE_EQ(A.x, 2);
    REQUIRE_EQ(A.y, 3);
}

TEST_CASE("Test distance between Points") {


    Circle c1(2,2,2,"black");
    Point A, B;
    A.x = 2;
    A.y = 3;
    B.x = 5;
    B.y = 0;

    REQUIRE_EQ(std::round(c1.getDistance(A, B) * 100000) / 100000 , 4.24264);
}

