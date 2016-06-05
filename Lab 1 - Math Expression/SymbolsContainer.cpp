//
//  SymbolsContainer.cpp
//  Lab1
//
//  Created by Andrea Borghi on 4/27/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include "SymbolsContainer.h"

SymbolsContainer::SymbolsContainer()
{
    symbolsStack = new stack<string>();
}

void SymbolsContainer::push_on_top(string symbol)
{
    symbolsStack -> push(symbol);
}

string SymbolsContainer::pop_front()
{
    string front = symbolsStack -> top();
    
    symbolsStack -> pop();
    
    return front;
}

string SymbolsContainer::peek()
{
    return symbolsStack -> top();
}

bool SymbolsContainer::isEmpty()
{
    return symbolsStack -> empty();
}

SymbolsContainer::~SymbolsContainer()
{
    delete symbolsStack;
}