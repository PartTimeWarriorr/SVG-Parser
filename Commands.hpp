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

string Commands::command = " ";
Collection Commands::collection;
bool Commands::fileOpened = false;
bool Commands::fileSaved = false;
string Commands::openedFileName = " ";

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

    if(Commands::fileOpened) {

        cout << "A file is already opened\n";
        return;
    }

    if(!Commands::collection.getVector().empty()) {

        string input;

        cout << "Opening a file will overwrite your current elements. Continue? (enter \"yes\" or \"no\")\n> ";
        cin >> input;
        cin.ignore();
        if(input == "yes") {}
        else if(input == "no") return;
        else {

            cout << "Invalid answer\n";
            return;   
        }

    }

    std::istringstream iss(command);
    string buffer, fileName;

    iss >> buffer >> fileName;

    if(fileName.compare("") == 0) {

        cout << "Please specify file name.\n";
        return;
    }

    ifstream ifile(fileName);

    if(!ifile.is_open()) {

        cout << "Error opening file\n";
        return;
    }

    while(!ifile.eof()) {

        ifile >> buffer;
        if(buffer == "<rect") {

            string x, y, width, height, color;
            double arg1, arg2, arg3, arg4;

            ifile >> buffer;
            x = buffer.substr(3, buffer.size() - 4); // magichesko chislo zashtoto s size() - 4 poluchava duljinata na chisloto (izvajda x=" i ")
            ifile >> buffer;
            y = buffer.substr(3, buffer.size() - 4);
            ifile >> buffer;
            width = buffer.substr(7, buffer.size() - 8);
            ifile >> buffer;
            height = buffer.substr(8, buffer.size() - 9);
            ifile >> buffer;
            color = buffer.substr(6, buffer.size() - 7);

            if(color[color.size() - 2] == '\"')
                color.erase(color.size() - 2);


            if(!validateColor(color)) {

                cout << "Unknown color: " << color << '\n';
                return;
            }

            try {
                
                arg1 = std::stod(x);
                arg2 = std::stod(y);
                arg3 = std::stod(width);
                arg4 = std::stod(height);

            }
            catch(std::invalid_argument) {

                cout << "Invalid file.\n";
                return;
            }


            Rectangle r1(arg1, arg2, arg3, arg4, color);

            Commands::collection.addShape(&r1);

        }

        if(buffer == "<circle") {
            
            string cx, cy, r, color;
            double arg1, arg2, arg3;

            ifile >> buffer;
            cx = buffer.substr(4, buffer.size() - 5);
            ifile >> buffer;
            cy = buffer.substr(4, buffer.size() - 5);
            ifile >> buffer;
            r = buffer.substr(3, buffer.size() - 4);
            ifile >> buffer;
            color = buffer.substr(6, buffer.size() - 7);

            if(color[color.size() - 2] == '\"')
                color.erase(color.size() - 2);

            if(!validateColor(color)) {

                cout << "Unknown color: " << color << '\n';
                return;
            }

            try {

                arg1 = std::stod(cx);
                arg2 = std::stod(cy);
                arg3 = std::stod(r);
            }
            catch(std::invalid_argument) {

                cout << "Invalid file\n";
                return;
            }

            Circle c1(arg1, arg2, arg3, color);

            Commands::collection.addShape(&c1);

        }

        if(buffer == "<line") {

            string x1, y1, x2, y2, color;
            double arg1, arg2, arg3, arg4;

            ifile >> buffer;
            x1 = buffer.substr(4, buffer.size() - 5);
            ifile >> buffer;
            y1 = buffer.substr(4, buffer.size() - 5);
            ifile >> buffer;
            x2 = buffer.substr(4, buffer.size() - 5);
            ifile >> buffer;
            y2 = buffer.substr(4, buffer.size() - 5);
            ifile >> buffer;
            color = buffer.substr(8, buffer.size() - 9);

            if(color[color.size() - 2] == '\"')
                color.erase(color.size() - 2);

            if(!validateColor(color)) {

                cout << "Unknown color: " << color << '\n';
                return;
            }

            try {

                arg1 = std::stod(x1);
                arg2 = std::stod(y1);
                arg3 = std::stod(x2);
                arg4 = std::stod(y2);
            }
            catch(std::invalid_argument) {

                cout << "Invalid file\n";
                return;
            }

            Line l1(arg1, arg2, arg3, arg4, color);

            Commands::collection.addShape(&l1);
            
        }

    }

    Commands::fileOpened = true;   
    Commands::openedFileName = fileName; 

    ifile.close();
}

void Commands::close() {

    if(!Commands::fileOpened) {

        cout << "Nothing to close!\n";
        return;
    }

    if(Commands::fileOpened && !Commands::fileSaved) {

        string input;

        cout << "Close file without saving? (enter \"yes\" or \"no\")\n> ";
        cin >> input;
        cin.ignore();

        if(input == "yes") {

            Commands::collection.clearShapes();

            Commands::fileOpened = false;
            Commands::openedFileName = " ";
            cout << "File closed\n";
            return;
        }

        if(input == "no") 
            return;
        else {
            cout << "Invalid answer\n";
            return;
        } 

    }

    if(Commands::fileOpened == Commands::fileSaved) {

        Commands::collection.clearShapes();
            
        Commands::fileOpened = false;
        Commands::fileSaved = false;
        Commands::openedFileName = " ";
        cout << "File closed\n";
        return;
    }

}

void Commands::save() {

    if(!Commands::fileOpened) {

        cout << "No file to save to\n";
        return;
    }

    ofstream ofile(Commands::openedFileName, std::ios::trunc);

    if(!ofile.is_open()) {

        cout << "Problem saving file\n";
        return;
    }

    ofile << "<?xml version=\"1.0\" standalone=\"no\"?>\n"
             "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n"
             "  \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n";

    ofile << "<svg>\n";

    Commands::collection.printAllInFile(ofile);
    
    ofile << "</svg>";

    Commands::fileSaved = true;

    ofile.close();

}

void Commands::saveAs() {

    std::istringstream iss(command);
    string buffer, fileName;

    iss >> buffer >> buffer >> fileName;

    if(fileName == " ") {

        cout << "Please specify file name\n";
        return;
    }

    ofstream ofile(fileName, std::ios::trunc);

    if(!ofile.is_open()) {

        cout << "Problem opening file\n";
        return;
    }

    ofile << "<?xml version=\"1.0\" standalone=\"no\"?>\n"
             "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n"
             "  \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n";

    ofile << "<svg>\n";

    Commands::collection.printAllInFile(ofile);
    
    ofile << "</svg>";

    if(Commands::fileOpened) 
        Commands::fileSaved = true;

    ofile.close();

}

void Commands::help() {

    cout << "The following commands are supported:\n"
            "open <file>                opens file\n"
            "close                      closes currently opened file\n"
            "save                       saves currently opened file\n"
            "save as <file>             saves currently opened file in specified file\n"
            "help                       prints information about supported commands\n"
            "exit                       exits programme\n"
            "=================================================================================\n"
            "print                      prints current list of elements\n"
            "create <shape-name> <...>  creates new element\n"
            "erase <index>              erases element at index <index>\n"
            "translate                  starts translation function\n"
            "within <shape-name> <...>  returns all elements found in the specified region\n";
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

        double arg1, arg2, arg3, arg4;

        try {

            arg1 = std::stod(str1), arg2 = std::stod(str2), arg3 = std::stod(str3), arg4 = std::stod(str4);

        }
        catch(std::invalid_argument) {
            
            cout << "You have entered an invalid argument\n";
            return;

        }

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

        double arg1, arg2, arg3, arg4;

        try {

            arg1 = std::stod(str1), arg2 = std::stod(str2), arg3 = std::stod(str3), arg4 = std::stod(str4);

        }
        catch(std::invalid_argument) {

            cout << "You have entered an invalid argument\n";
            return;
        }


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

        double arg1, arg2, arg3;

        try {

            arg1 = std::stod(str1), arg2 = std::stod(str2), arg3 = std::stod(str3);

        }
        catch(std::invalid_argument) {

            cout << "You have entered an invalid argument\n";
            return;
        }

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

    int arg;

    try {

        arg = std::stoi(index);

    }
    catch(std::invalid_argument) {

        cout << "Invalid index\n";
        return;
    }

    if(arg - 1 > Commands::collection.getVector().size() - 1 || arg - 1 < 0) {

        cout << "Invalid index\n";
        return;
    }

    Commands::collection.eraseShape(arg - 1);
}

void Commands::translate() {

    if(Commands::collection.getVector().empty()) {

        cout << "Nothing to translate\n";
        return;
    }

    string indStr;
    bool all = false;
    double horizontal, vertical;

    cout << "Please specify element to translate (Enter \"all\" to translate all elements)\n> ";
    cin >> indStr;
    if(!indStr.compare("all")) 
        all = true;
    

    cout << "Enter translate values: \n> ";
    cin >> horizontal >> vertical;
    cin.ignore();

    if(all) {

        for(size_t i = 0; i < Commands::collection.getVector().size(); ++i)
            Commands::collection.translateShape(i, horizontal, vertical);
        
        return;
    }
    
    int index;

    try {
        
        index = std::stoi(indStr);
    }
    catch(std::invalid_argument) {

        cout << "You have entered an invalid index\n";
        return;
    }


    if(index - 1 > Commands::collection.getVector().size() - 1 || index - 1 < 0) {

        cout << "Invalid index\n";
        return;
    }

    Commands::collection.translateShape(index - 1, horizontal, vertical);

}

void Commands::within() {

    std::istringstream iss(command);
    string buffer;
    string region, str1, str2, str3, str4;

    iss >> buffer >> region;
    iss >> str1 >> str2 >> str3 >> str4;

    if(region == "rectangle") {

        if(str4.compare("") == 0 || str3.compare("") == 0 || str2.compare("") == 0 || str1.compare("") == 0) {

            cout << "Not enough arguments\n";
            return;
        }

        double arg1, arg2, arg3, arg4;

        try {

            arg1 = std::stod(str1), arg2 = std::stod(str2), arg3 = std::stod(str3), arg4 = std::stod(str4); 
        }
        catch(std::invalid_argument) {

            cout << "You have entered an invalid argument\n";
            return;
        }

        if(arg3 <= 0 || arg4 <= 0) {

            cout << "Invalid width and/or height\n";
            return;
        }

        Rectangle r1(arg1, arg2, arg3, arg4, "black");

        // logika za within (member commandi na trite shapes klasa)

    }

    else if(region == "circle") {

        if(str3.compare("") == 0 || str2.compare("") == 0 || str1.compare("") == 0) {

            cout << "Not enough arguments\n";
            return;
        }

        double arg1, arg2, arg3;

        try {

            arg1 = std::stod(str1), arg2 = std::stod(str2), arg3 = std::stod(str3);

        }
        catch(std::invalid_argument) {

            cout << "You have entered an invalid argument\n";
            return;
        }

        if(arg3 <= 0) {

            cout << "Invalid radius\n";
            return;
        }

        Circle c1(arg1, arg2, arg3, "black");

        // logika za within (member commandi na trite shapes klasa)
    }

    else
        cout << "Invalid shape name\n";

    
    cout << "No elements found in region\n";
    return;
}
