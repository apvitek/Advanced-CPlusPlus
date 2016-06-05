//
//  MathExpression.cpp
//  Lab1
//
//  Created by Andrea Borghi on 4/27/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include "MathExpression.h"

MathExpression::MathExpression(string expression)
{
    parser = new ExpressionParser();
    converter = new PostfixConverter();
    evaluator = new ExpressionEvaluator();
    container = new DictionaryContainer();
    
    infix = parser -> parseExpression(expression);
    
    postfix = converter -> convertToPostfix(infix);
}

string MathExpression::infixToString()
{
    return infix -> toString();
}

string MathExpression::postfixToString()
{
    return postfix -> toString();
}

vector<string>::iterator MathExpression::infixElementsBegin()
{
    return infix -> getIteratorBegin();
}

vector<string>::iterator MathExpression::infixElementsEnd()
{
    return infix -> getIteratorEnd();
}

vector<string>::iterator MathExpression::postfixElementsBegin()
{
    return postfix -> getIteratorBegin();
}

vector<string>::iterator MathExpression::postfixElementsEnd()
{
    return postfix -> getIteratorEnd();
}

DictionaryContainer * MathExpression::getDictionaryContainer() const
{
    return container;
}

double MathExpression::evaluate()
{
    return evaluator -> evaluateExpression(postfix);
}

MathExpression::~MathExpression()
{
    delete parser;
    delete converter;
    delete evaluator;
    delete infix;
    delete postfix;
    delete container;
}