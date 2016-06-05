//
//  InfixFormat.cpp
//  Lab1
//
//  Created by Andrea Borghi on 4/27/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include "InfixFormat.h"

InfixFormat::InfixFormat(vector<string> * exp)
{
    expression = exp;
}

string InfixFormat::toString()
{
    string expressionToString;
    
    for (vector<string>::iterator it = expression -> begin(); it != expression -> end(); ++it){
        expressionToString.append(* it);
        
        if (it != expression -> end() - 1 && (* it) != "(" && (* next(it)) != ")") {
            expressionToString.append(" ");
        }
    }

    return expressionToString;
}