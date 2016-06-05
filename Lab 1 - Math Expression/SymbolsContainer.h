//
//  SymbolsContainer.h
//  Lab1
//
//  Created by Andrea Borghi on 4/27/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef __Lab1__SymbolsContainer__
#define __Lab1__SymbolsContainer__

#include <iostream>
#include <stack>

using namespace std;

class SymbolsContainer {
private:
    stack<string> * symbolsStack;
    
public:
    SymbolsContainer();
    void push_on_top(string symbol);
    string pop_front();
    string peek();
    bool isEmpty();
    ~SymbolsContainer();
};

#endif /* defined(__Lab1__SymbolsContainer__) */