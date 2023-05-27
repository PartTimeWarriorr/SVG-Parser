#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../headers/Commands.hpp"

TEST_CASE("Test open function") {

    Commands::fileOpened = true;
    Commands::command = "open base.svg";
    Commands::open();

    REQUIRE(Commands::collection.getVector().empty());
}

TEST_CASE("Test open function 2") {

    Commands::fileOpened = false;
    Commands::command = "open";
    Commands::open();

    REQUIRE(Commands::collection.getVector().empty());
}

TEST_CASE("Test open function 3") {

    Commands::fileOpened = false;
    Commands::command = "open base.svg";
    Commands::open();

    REQUIRE(!Commands::collection.getVector().empty());
}

TEST_CASE("Test save function") {

    Commands::openedFileName = "";
    Commands::fileOpened = false;
    Commands::command = "save";
    Commands::save();

    REQUIRE(!Commands::fileSaved);
}

TEST_CASE("Test save function 2") {

    Commands::openedFileName = "s.svg";
    Commands::fileOpened = true;
    Commands::fileSaved = false;
    Commands::command = "save";
    Commands::save();

    REQUIRE(Commands::fileSaved);
}

TEST_CASE("Test save as function") {

    Commands::fileOpened = false;
    Commands::fileSaved = false;
    Commands::command = "save as";
    Commands::saveAs();

    REQUIRE(!Commands::fileSaved);
}

TEST_CASE("Test save as function 2") {

    Commands::fileOpened = true;
    Commands::command = "save as s.svg";
    Commands::saveAs();

    REQUIRE(Commands::fileSaved);
}

TEST_CASE("Test close function") {

    Commands::collection.clearShapes();

    Commands::fileOpened = false;
    Commands::command = "open s.svg";
    Commands::fileSaved = false;
    Commands::open();
    Commands::fileSaved = true;

    REQUIRE(!Commands::collection.getVector().empty());

    Commands::close();

    REQUIRE(Commands::collection.getVector().empty());
}