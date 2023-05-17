#pragma once

#include "Collection.hpp"
#include <sstream> 
#include <fstream>
#include <exception> // Handle incorrect conversions: display error message: "Invalid arguments"

using std::cin;

using std::ifstream;
using std::ofstream;

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
    static void within(); // Specify whether circle or rectangle region

    static string command;
    static Collection collection;

};

string Commands::command = " ";
Collection Commands::collection;

bool Commands::validateColor(string color) {

    string buffer;
    ifstream txt("colors.txt");
    if(!txt.is_open()) {

        cout << "Error opening file\n";
        return false;
    }

    while(!txt.eof()) {

        getline(txt, buffer);
        if(color == buffer) return true;
    }

    return false;

}

void Commands::open() {


}

void Commands::close() {


}

void Commands::save() {


}

void Commands::saveAs() {


}

void Commands::help() {


}

void Commands::exit() {

    cout << "Exiting program..\n";

}

void Commands::print() {

    Commands::collection.printCollection();
}

void Commands::create() {

    std::istringstream iss(command);
    string buffer, shape;
    string str1, str2, str3, str4, str5;

    iss >> buffer >> shape;
    iss >> str1 >> str2 >> str3 >> str4 >> str5;

    if(shape.compare("rectangle") == 0) {

        if(str4.compare("") == 0 || str3.compare("") == 0 || str2.compare("") == 0 || str1.compare("") == 0 || str5.compare("") == 0) {

            cout << "Not enough arguments\n";
            return;
        }

        if(!validateColor(str5)) {

            cout << "Invalid color\n";
            return;
        }

        double arg1 = std::stod(str1), arg2 = std::stod(str2), arg3 = std::stod(str3), arg4 = std::stod(str4);

        if(arg3 <= 0 || arg4 <= 0) {

            cout << "Invalid width and/or height\n";
            return;
        }

        Rectangle r1(arg1, arg2, arg3, arg4, str5);

        Commands::collection.addShape(&r1);
        cout << "Successfully created rectangle " << Commands::collection.getVector().size() << '\n';
    }

    else if(shape.compare("line") == 0) {

        if(str4.compare("") == 0 || str3.compare("") == 0 || str2.compare("") == 0 || str1.compare("") == 0 || str5.compare("") == 0) {

            cout << "Not enough arguments\n";
            return;
        }

        if(!validateColor(str5)) {

            cout << "Invalid color\n";
            return;
        }

        double arg1 = std::stod(str1), arg2 = std::stod(str2), arg3 = std::stod(str3), arg4 = std::stod(str4);

        Line l1(arg1, arg2, arg3, arg4, str5);

        Commands::collection.addShape(&l1);
        cout << "Successfully created line " << Commands::collection.getVector().size() << '\n';

    }

    else if(shape.compare("circle") == 0) {

        if(str3.compare("") == 0 || str2.compare("") == 0 || str1.compare("") == 0 || str4.compare("") == 0) {

            cout << "Not enough arguments\n";
            return;
        }

        if(!validateColor(str4)) {

            cout << "Invalid color\n";
            return;
        }

        double arg1 = std::stod(str1), arg2 = std::stod(str2), arg3 = std::stod(str3);

        if(arg3 <= 0) {

            cout << "Invalid radius\n";
            return;
        }

        Circle c1(arg1, arg2, arg3, str4);

        Commands::collection.addShape(&c1);
        cout << "Successfully created circle " << Commands::collection.getVector().size() << '\n';
    }

    else
        cout << "Invalid shape name\n";
    
}

void Commands::erase() {

    std::istringstream iss(command);
    string buffer;
    string index;

    iss >> buffer >> index;

    if(Commands::collection.getVector().empty()) {

        cout << "Nothing to delete\n";
        return;
    }

    if(index.compare("") == 0) {

        cout << "Please specify index of element to be removed.\n";
        return;
    }

    int arg = std::stoi(index);

    if(arg > Commands::collection.getVector().size() - 1 || arg < 0) {

        cout << "Invalid index\n";
        return;
    }

    Commands::collection.eraseShape(arg);
}

void Commands::translate() {

    string indStr;
    bool all = false;
    double horizontal, vertical;

    cout << "Please specify element to translate (Enter \"all\" to translate all elements)\n";
    cin >> indStr;
    if(!indStr.compare("all")) 
        all = true;
    

    cout << "Enter translate values: \n";
    cin >> horizontal >> vertical;
    cin.ignore();

    if(all) {

        for(size_t i = 0; i < Commands::collection.getVector().size(); ++i)
            Commands::collection.translateShape(i, horizontal, vertical);
        
        return;
    }

    int index = std::stoi(indStr);
    
    if(index > Commands::collection.getVector().size() - 1 || index < 0) {

        cout << "Invalid index\n";
        return;
    }

    Commands::collection.translateShape(index, horizontal, vertical);

}

