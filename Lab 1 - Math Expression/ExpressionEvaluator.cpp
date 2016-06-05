//
//  ExpressionEvaluator.cpp
//  Lab1
//
//  Created by Andrea Borghi on 4/27/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include "ExpressionEvaluator.h"

ExpressionEvaluator::ExpressionEvaluator()
{
    controller = new PrecedenceController();
}

double ExpressionEvaluator::evaluateExpression(PostfixFormat * expression)
{
    double result = 0;
    
    stack<double> * evaluate = new stack<double>();
    
    for(auto it = expression -> getIteratorBegin(); it != expression -> getIteratorEnd(); ++it){
        string nextElement = (* it);
        
        if (controller -> isOperand(nextElement)) {
            double number = atof(nextElement.c_str());
            
            evaluate -> push(number);
        
        } else if (controller -> isOperator(nextElement)){
            double number1, number2;
            
            number1 = evaluate -> top();
            evaluate -> pop();
            
            number2 = evaluate -> top();
            evaluate -> pop();
            
            if (nextElement == "+") {
                evaluate -> push(number2 + number1);
                
            } else if (nextElement == "-"){
                evaluate -> push(number2 - number1);
                
            } else if (nextElement == "/"){
                evaluate -> push(number2 / number1);
                
            } else if (nextElement == "*"){
                evaluate -> push(number2 * number1);
                
            }
        }
    }
    
    result = evaluate -> top();
    
    delete evaluate;
    
    return result;
}

ExpressionEvaluator::~ExpressionEvaluator()
{
    delete controller;
}