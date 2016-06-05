//
//  ExpressionConverter.h
//  Lab1
//
//  Created by Andrea Borghi on 4/27/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef __Lab1__ExpressionConverter__
#define __Lab1__ExpressionConverter__

#include <iostream>
#include <vector>
#include "InfixMathExpression.h"
#include "PostfixMathExpression.h"
#include "PrecedenceController.h"
#include "NumericContainer.h"
#include "SymbolsContainer.h"

using namespace std;

class ExpressionConverter {
private:
    NumericContainer * numbers;
    SymbolsContainer * symbols;
    PrecedenceController * controller;
    
public:
    ExpressionConverter();
    ~ExpressionConverter();
    PostfixMathExpression * convertToPostfix(InfixMathExpression * expression);
};

#endif /* defined(__Lab1__ExpressionConverter__) */
