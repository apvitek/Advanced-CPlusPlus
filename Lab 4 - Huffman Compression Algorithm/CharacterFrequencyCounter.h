//
//  CharacterFrequencyCounter.h
//  Lab4
//
//  Created by Andrea Borghi on 5/31/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef Lab4_CharacterFrequencyCounter_h
#define Lab4_CharacterFrequencyCounter_h

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <sstream>

using namespace std;

class CharacterFrequencyCounter {
private:
    // Private variables
    map<char, int> frequencyMap;
    vector<char> charactersList;
    string bitsSequence;
    
    // Private functions
    bool parseLine(string &inputLine);
    
public:
    bool parseSingleLine(string& inputLine);
    bool parseFile(fstream& inputFile);
    int getFrequencyForCharacter(char& character);
    void printCharactersAndFrequencies();
    vector<char> getCharactersList() { return charactersList; };
    map<char, int> getFrequencyMap() { return frequencyMap; }
    string getBitsSequence() { return bitsSequence; }
};

bool CharacterFrequencyCounter::parseLine(string &inputLine)
{
    for (int i = 0; i < inputLine.length(); ++i) {
        char currentChar = inputLine[i];
        
        stringstream ss;
        
        ss << bitset<8>((int)currentChar);
        
        bitsSequence += ss.str();
        
        auto it = frequencyMap.find(currentChar);
        
        if (it == frequencyMap.end()) {
            frequencyMap.emplace(currentChar, 1);
            
            charactersList.push_back(currentChar);
            
        } else {
            // Increase frequency of character
            it->second += 1;
        }
    }
    
    return true;
}

bool CharacterFrequencyCounter::parseSingleLine(string &inputLine)
{
    return parseLine(inputLine);
}

bool CharacterFrequencyCounter::parseFile(fstream &inputFile)
{
    string inputLine;
    bool success = false;
    
    while (getline(inputFile, inputLine)) success = parseLine(inputLine);
    
    return success;
}

int CharacterFrequencyCounter::getFrequencyForCharacter(char &character)
{
    int frequency = -1;
    
    auto it = frequencyMap.find(character);
    
    if (it != frequencyMap.end()) frequency = it->second;
    
    return frequency;
}

void CharacterFrequencyCounter::printCharactersAndFrequencies()
{
    for (auto it = frequencyMap.begin(); it != frequencyMap.end(); ++it) {
        cout << it->first << " => " << it->second << '\n';
    }
}

#endif
