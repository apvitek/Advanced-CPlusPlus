//
//  PrecedenceController.cpp
//  Lab1
//
//  Created by Andrea Borghi on 4/27/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include "PrecedenceController.h"

int PrecedenceController::compareOperators(string left, string right)
{
    if ((left == "*" || left == "/") && (right == "+" || right == "-")){
        return -1;
        
    } else if ((left == "+" || left == "-") && (right == "*" || right == "/")){
        return 1;
    }
    
    return 0;
}

bool PrecedenceController::isOperator(string character) {
    if (character == "+" || character == "-" || character == "*" || character == "/") {
        return true;
    }
    return false;
}

bool PrecedenceController::isOperand(string character) {
    if (!isOperator(character) && character != "(" && character != ")") {
        return true;
    }
    return false;
}