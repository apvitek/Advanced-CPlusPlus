//
//  SymbolicConverter.cpp
//  Lab1
//
//  Created by Andrea Borghi on 4/30/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include "SymbolicConverter.h"

SymbolicConverter::SymbolicConverter()
{
    controller = new PrecedenceController();
}

SymbolicConverter::~SymbolicConverter()
{
    delete controller;
}

void SymbolicConverter::convertToSymbolic(MathExpression *expression)
{
    for (auto it = expression -> infixElementsBegin(); it != expression -> infixElementsEnd(); ++it) {
        if (controller -> isOperand(*it)) {
            (*it) = expression -> getDictionaryContainer() -> getLetterForNumber(atof((*it).c_str()));
        }
    }
    
    for (auto it = expression -> postfixElementsBegin(); it != expression -> postfixElementsEnd(); ++it) {
        if (controller -> isOperand(*it)) {
            (*it) = expression -> getDictionaryContainer() -> getLetterForNumber(atof((*it).c_str()));
        }
    }
}

void SymbolicConverter::convertToNumerical(MathExpression *expression)
{
    for (auto it = expression -> infixElementsBegin(); it != expression -> infixElementsEnd(); ++it) {
        if (controller -> isOperand(*it)) {
            ostringstream convert;
            
            convert << expression -> getDictionaryContainer() -> getNumberForLetter((*it)[0]);
            
            (*it) = convert.str();
        }
    }
    
    for (auto it = expression -> postfixElementsBegin(); it != expression -> postfixElementsEnd(); ++it) {
        if (controller -> isOperand(*it)) {
            ostringstream convert;
            
            convert << expression -> getDictionaryContainer() -> getNumberForLetter((*it)[0]);
            
            (*it) = convert.str();
        }
    }
}