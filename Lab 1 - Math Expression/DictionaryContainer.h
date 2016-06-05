//
//  DictionaryContainer
//  Lab1
//
//  Created by Andrea Borghi on 4/28/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef __Lab1__DictionaryContainer__
#define __Lab1__DictionaryContainer__

#include <iostream>
#include <map>

using namespace std;

class DictionaryContainer {
private:
    map<char, double> * symbolsMap;
    
public:
    DictionaryContainer();
    char getLetterForNumber(double number);
    double getNumberForLetter(char letter);
    void printContainer();
    ~DictionaryContainer();
};

#endif /* defined(__Lab1__DictionaryContainer__) */