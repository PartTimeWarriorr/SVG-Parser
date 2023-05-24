#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../Commands.hpp"

TEST_CASE("Test open function") {

    Commands::fileOpened = true;
    Commands::command = "open base.svg";
    Commands::open();

    REQUIRE_FALSE(!Commands::collection.getVector().empty());

}

TEST_CASE("Test open function 2") {

    Commands::command = "open";
    Commands::open();

    REQUIRE_FALSE(!Commands::collection.getVector().empty());
}

TEST_CASE("Test save function") {

    Commands::fileOpened = false;
    Commands::command = "save";
    Commands::save();

    REQUIRE_FALSE(Commands::fileSaved);
}

TEST_CASE("Test create function, case 1") {

    Commands::command = "create rectangle 10 10 10 violet";
    Commands::create();

    REQUIRE_FALSE(!Commands::collection.getVector().empty());

}

TEST_CASE("Test create function, case 2") {

    Commands::command = "create retangle 10 10 10 10 violet";
    Commands::create();

    REQUIRE_FALSE(!Commands::collection.getVector().empty());

}

TEST_CASE("Test create function, case 3") {

    Commands::command = "create circle 20 2 3";
    Commands::create();

    REQUIRE_FALSE(!Commands::collection.getVector().empty());

}

TEST_CASE("Test create function, case 4") {

    Commands::command = "create line 1 s 3 4 violet";
    Commands::create();

    REQUIRE_FALSE(!Commands::collection.getVector().empty());

}

TEST_CASE("Test erase function") {

    rns::Rectangle r1(2, 4, 50, 20, "violet");

    Commands::collection.addShape(&r1);

    Commands::command = "erase 1";
    Commands::erase();

    REQUIRE_FALSE(!Commands::collection.getVector().empty());
}
