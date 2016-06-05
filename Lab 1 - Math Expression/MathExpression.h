//
//  MathExpression.h
//  Lab1
//
//  Created by Andrea Borghi on 4/27/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef __Lab1__MathExpression__
#define __Lab1__MathExpression__

#include <iostream>
#include "Format.h"
#include "Parser.h"
#include "ExpressionParser.h"
#include "PostfixConverter.h"
#include "ExpressionEvaluator.h"
#include "DictionaryContainer.h"

using namespace std;

class MathExpression {
private:
    InfixFormat * infix;
    PostfixFormat * postfix;
    Parser * parser;
    PostfixConverter * converter;
    ExpressionEvaluator * evaluator;
    DictionaryContainer * container;
    
public:
    MathExpression(string expression);
    string infixToString();
    string postfixToString();
    vector<string>::iterator infixElementsBegin();
    vector<string>::iterator infixElementsEnd();
    vector<string>::iterator postfixElementsBegin();
    vector<string>::iterator postfixElementsEnd();
    DictionaryContainer * getDictionaryContainer() const;
    double evaluate();
    ~MathExpression();
};

#endif /* defined(__Lab1__MathExpression__) */
