//#define DEBUG_FILE_IO

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
//#include "hong_ping.h"

using std::ifstream;
using std::ofstream;
using std::string;
using std::stringstream;

const string INPUT_FILE_NAME = "input.txt";
const string OUTPUT_FILE_NAME = "output.txt";
const int MAX_STRING = 32;

void startInterface(ifstream &inputFile, ofstream &outputFile);

int main()
{
    std::ifstream inputFile;
    inputFile.open(INPUT_FILE_NAME, std::fstream::in);

    std::ofstream outputFile;
    outputFile.open(OUTPUT_FILE_NAME, std::fstream::out);

    startInterface(inputFile, outputFile);

    inputFile.close();
    outputFile.close();

    return EXIT_SUCCESS;
}

void startInterface(ifstream &inputFile, ofstream &outputFile)
{
    string command;
    
    string menu_level_1, menu_level_2;
    bool is_program_exit = false;

#ifdef DEBUG_FILE_IO
    getline(inputFile, command);
    while (!inputFile.eof() && !is_program_exit)
    {
        outputFile << command << '\n';
        getline(inputFile, command);
    }
#endif

    while (getline(inputFile, command) && !is_program_exit)
    {
        stringstream ss(command);
        ss >> menu_level_1 >> menu_level_2;
        
        switch(stoi(menu_level_1))
        {
            case 1:
            {}
            case 2:
            {}
            case 3:
            {}
            case 4:
            {}
            case 5:
            {}
            case 6:
            {}
            default:
            {}
        }
    }
}