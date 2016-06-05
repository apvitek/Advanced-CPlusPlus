//
//  DictionaryContainer.cpp
//  Lab1
//
//  Created by Andrea Borghi on 4/28/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include "DictionaryContainer.h"

DictionaryContainer::DictionaryContainer()
{
    symbolsMap = new map<char, double>();
}

DictionaryContainer::~DictionaryContainer()
{
    delete symbolsMap;
}

char DictionaryContainer::getLetterForNumber(double number)
{
    int counter = 0;
    char character = 'A';
    
    if (symbolsMap -> size() != 0) {
        for (auto it : *symbolsMap) {
            // If already present in the list, return the letter associated with the number
            if (it.second == number)
                return it.first;
            
            ++counter;
        }
        
        character = counter + 65;
    }
    
    (*symbolsMap)[character] = number;
    
    return character;
}

double DictionaryContainer::getNumberForLetter(char letter)
{
    double number = 0;
    map<char, double>::iterator it;
    
    it = symbolsMap -> find(letter);
    
    if (it != symbolsMap -> end()) {
        number = it -> second;
    }
    
    return number;
}

// Utility function
void DictionaryContainer::printContainer()
{
    cout << "The container is :" << endl;
    
    for (auto it : *symbolsMap){
        cout << it.first << " " << it.second << endl;
    }
}