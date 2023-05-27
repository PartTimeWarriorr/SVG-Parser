#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../headers/Commands.hpp"

TEST_CASE("Test create function, case 1") {

    Commands::command = "create rectangle 10 10 10 violet";
    Commands::create();

    REQUIRE(Commands::collection.getVector().empty());

}

TEST_CASE("Test create function, case 2") {

    Commands::command = "create retangle 10 10 10 10 violet";
    Commands::create();

    REQUIRE(Commands::collection.getVector().empty());
}

TEST_CASE("Test create function, case 3") {

    Commands::command = "create circle 20 2 3";
    Commands::create();

    REQUIRE(Commands::collection.getVector().empty());
}

TEST_CASE("Test create function, case 4") {

    Commands::command = "create line 1 s 3 4 violet";
    Commands::create();

    REQUIRE(Commands::collection.getVector().empty());
}

TEST_CASE("Test erase function") {

    Commands::command = "create rectangle 2 4 50 20 violet";
    Commands::create();
    Commands::command = "erase 1";
    Commands::erase();

    REQUIRE(Commands::collection.getVector().empty());
}

TEST_CASE("Test create function, case 5") {

    Commands::command = "create line 1 1 2 2 violet";
    Commands::create();

    REQUIRE(!Commands::collection.getVector().empty());
}