#pragma once

#include "Commands.hpp"

using std::cout;
using std::cin;

class CommandLine {

    public:

    static void run();

};

void CommandLine::run() {

    while(true) {

        cout << "> ";
        getline(cin, Commands::command);

        if(!Commands::command.compare(0, 5, "open "))
            break;
        else if(!Commands::command.compare("close"))
            break;
        else if(!Commands::command.compare("save"))
            break;
        else if(!Commands::command.compare(0, 8, "save as "))
            break;
        else if(!Commands::command.compare("help"))
            break;
        else if(!Commands::command.compare("exit")) {
            Commands::exit();
            break;
        }
        
        else if(!Commands::command.compare("print"))
            Commands::print();
        else if(!Commands::command.compare(0, 7, "create "))
            Commands::create();
        else if(!Commands::command.compare(0, 6, "erase ") || !Commands::command.compare(0, 5, "erase"))
            Commands::erase();
        else if(!Commands::command.compare("translate"))
            Commands::translate();
        else if(!Commands::command.compare(0, 7, "within "))
            break;

        else {

            cout << "Invalid command. Enter \"help\" to receive information about the available commands.\n";

        }
    }
    
}