// Andrea Borghi
// Lab2

#include <iostream>
#include <fstream>
#include <vector>
#include "FileParser.h"
#include "HamiltonianProblemSolver.h"

using namespace std;

void printLocation(Location s);

int main(int argc, const char * argv[])
{
    FileParser parser;
    HamiltonianProblemSolver problemSolver(6);
    
    vector<Location> * parsedStrings = new vector<Location>();
    
    fstream inputFile;
    
    inputFile.open("/Users/andreaborghi/Documents/DAC - Advanced C++/Lab2/Lab2/Restaurants.xml");
    
    if (!inputFile) {
        cout << "The input file could not be open!" << endl;
        
        exit(0);
    };
    
    parsedStrings = parser.parseFile(inputFile);
    
    inputFile.close();
    
    cout << "There are " << parsedStrings->size() << " locations in the input file." << endl << endl;
    
    for_each(parsedStrings->begin(), parsedStrings->end(), printLocation);
    
    problemSolver.solveProblem(parsedStrings);
    
    delete parsedStrings;
    
    return 0;
}

void printLocation(Location s)
{
    cout << s << endl << endl;
}