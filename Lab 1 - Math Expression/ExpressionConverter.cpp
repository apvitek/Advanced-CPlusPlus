//
//  ExpressionConverter.cpp
//  Lab1
//
//  Created by Andrea Borghi on 4/27/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include "ExpressionConverter.h"

ExpressionConverter::ExpressionConverter()
{
    numbers = new NumericContainer();
    symbols = new SymbolsContainer();
    controller = new PrecedenceController();
}

ExpressionConverter::~ExpressionConverter()
{
    delete numbers;
    delete symbols;
    delete controller;
}

PostfixMathExpression * ExpressionConverter::convertToPostfix(InfixMathExpression * expression)
{
    vector<string> * exp = new vector<string>();
    
    for(vector<string>::iterator it = expression -> getIteratorBegin(); it != expression -> getIteratorEnd(); ++it){
        string nextElement = (* it);
        
        if (controller -> isOperand(nextElement)) {
            numbers -> push_back(atof(nextElement.c_str()));
            
            exp -> push_back(nextElement);
            
        } else if (controller -> isOperator(nextElement)) {
            while (!(symbols -> isEmpty()) && symbols -> peek() != "(" && controller -> compareOperators(symbols -> peek(), nextElement) <= 0) {
                exp -> push_back(symbols -> pop_front());
            }
            
            symbols -> push_on_top(nextElement);
            
        } else if (nextElement == "("){
            symbols -> push_on_top(nextElement);
            
        } else if (nextElement == ")"){
            while (!(symbols -> isEmpty())) {
                if (symbols -> peek() == "(") {
                    symbols -> pop_front();
                    
                    break;
                }
                
                exp -> push_back(symbols -> pop_front());
            }
        }
    }
    
    while (!(symbols -> isEmpty())) {
        exp -> push_back(symbols -> pop_front());
    }
    
    return new PostfixMathExpression(exp);
}