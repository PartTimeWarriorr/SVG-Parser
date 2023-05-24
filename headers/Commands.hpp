#pragma once

#include "Collection.hpp"
#include <sstream> 
#include <exception> 

using std::cin;

class Commands {

    private:

    static bool validateColor(string color);

    public:

    static void open();
    static void close();
    static void save();
    static void saveAs();
    static void help();
    static void exit();

    static void print();
    static void create();
    static void erase();
    static void translate();
    static void within(); 

    static string command;
    static Collection collection;
    static bool fileOpened;
    static bool fileSaved;
    static string openedFileName;

};

