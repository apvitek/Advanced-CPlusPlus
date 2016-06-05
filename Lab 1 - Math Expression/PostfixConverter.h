//
//  PostfixConverter.h
//  Lab1
//
//  Created by Andrea Borghi on 4/27/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef __Lab1__PostfixConverter__
#define __Lab1__PostfixConverter__

#include <iostream>
#include <vector>
#include "InfixFormat.h"
#include "PostfixFormat.h"
#include "PrecedenceController.h"
#include "NumericContainer.h"
#include "SymbolsContainer.h"

using namespace std;

class PostfixConverter {
private:
    NumericContainer * numbers;
    SymbolsContainer * symbols;
    PrecedenceController * controller;
    
public:
    PostfixConverter();
    ~PostfixConverter();
    PostfixFormat * convertToPostfix(InfixFormat * expression);
};

#endif /* defined(__Lab1__PostfixConverter__) */
