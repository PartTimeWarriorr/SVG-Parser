#pragma once

#include "Collection.hpp"

class Commands {

    public:

    void open();
    void close();
    void save();
    void saveAs();
    void help();
    void exit();

    void print();
    void create();
    void erase(unsigned int index);
    void translate(unsigned int index);
    void within(); // Specify whether circle or rectangle region

};
