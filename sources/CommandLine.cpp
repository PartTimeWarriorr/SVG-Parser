#include "../headers/CommandLine.hpp"


void CommandLine::run() {

    while(true) {

        cout << "> ";
        getline(cin, Commands::command);

        if(!Commands::command.compare(0, 5, "open ") || !Commands::command.compare(0, 4, "open"))
            Commands::open();
        else if(!Commands::command.compare("close"))
            Commands::close();
        else if(!Commands::command.compare("save"))
            Commands::save();
        else if(!Commands::command.compare(0, 8, "save as ") || !Commands::command.compare(0, 7, "save as"))
            Commands::saveAs();
        else if(!Commands::command.compare("help"))
            Commands::help();
        else if(!Commands::command.compare("exit")) {
            Commands::exit();
            break;
        }
        
        else if(!Commands::command.compare("print"))
            Commands::print();
        else if(!Commands::command.compare(0, 7, "create ") || !Commands::command.compare(0, 6, "create"))
            Commands::create();
        else if(!Commands::command.compare(0, 6, "erase ") || !Commands::command.compare(0, 5, "erase"))
            Commands::erase();
        else if(!Commands::command.compare("translate") || !Commands::command.compare(0, 9, "translate"))
            Commands::translate();
        else if(!Commands::command.compare(0, 7, "within ") || !Commands::command.compare(0, 6, "within"))
            Commands::within();

        else {

            cout << "Invalid command. Enter \"help\" to get information about the available commands.\n";

        }
    }
    
}