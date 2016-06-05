//
//  PostfixFormat.cpp
//  Lab1
//
//  Created by Andrea Borghi on 4/27/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include "PostfixFormat.h"

PostfixFormat::PostfixFormat(vector<string> * exp)
{
    expression = exp;
}

string PostfixFormat::toString()
{
    string expressionToString;
    
    for (vector<string>::iterator it = expression -> begin(); it != expression -> end(); ++it){
        expressionToString.append(* it);
        
        if (it != expression -> end() - 1) {
            expressionToString.append(" ");
        }
    }
    
    return expressionToString;
}