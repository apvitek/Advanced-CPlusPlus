//
//  ExpressionParser.h
//  Lab1
//
//  Created by Andrea Borghi on 4/27/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef __Lab1__ExpressionParser__
#define __Lab1__ExpressionParser__

#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include "Parser.h"

class ExpressionParser : public Parser {
private:
    string parsingPattern = "[-+*/()]|[0-9.]+";
    
public:
    ExpressionParser(){};
    ExpressionParser(const string expressionPattern);
    InfixFormat * parseExpression(string expression);
};

#endif /* defined(__Lab1__ExpressionParser__) */
