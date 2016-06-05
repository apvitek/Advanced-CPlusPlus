//
//  SymbolicConverter.h
//  Lab1
//
//  Created by Andrea Borghi on 4/30/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef __Lab1__SymbolicConverter__
#define __Lab1__SymbolicConverter__

#include <iostream>
#include <sstream>
#include "MathExpression.h"
#include "PrecedenceController.h"
#include "DictionaryContainer.h"

using namespace std;

class SymbolicConverter {
private:
    PrecedenceController * controller;
    
public:
    SymbolicConverter();
    void convertToSymbolic(MathExpression * expression);
    void convertToNumerical(MathExpression * expression);
    ~SymbolicConverter();
};

#endif /* defined(__Lab1__SymbolicConverter__) */
