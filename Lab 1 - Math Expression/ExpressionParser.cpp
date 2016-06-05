//
//  ExpressionParser.cpp
//  Lab1
//
//  Created by Andrea Borghi on 4/27/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include "ExpressionParser.h"

ExpressionParser::ExpressionParser(const string expressionPattern)
{
    parsingPattern = expressionPattern;
}

InfixFormat * ExpressionParser::parseExpression(string expression)
{
    vector<string> * parsedExpression = new vector<string>();
    
	sregex_token_iterator end;
    
	regex pattern(parsingPattern);
    
	for (sregex_token_iterator iter(expression.begin(), expression.end(), pattern);iter != end; ++iter){
		if ((*iter).length() > 0){
            parsedExpression -> push_back(* iter);
		}
	}
    
    return new InfixFormat(parsedExpression);
}