//
//  Parser.h
//  Lab1
//
//  Created by Andrea Borghi on 5/2/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef __Lab1__Parser__
#define __Lab1__Parser__

#include <iostream>
#include "InfixFormat.h"

using namespace std;

class Parser {
public:
    virtual InfixFormat * parseExpression(string expression) = 0;
    virtual ~Parser(){};
};

#endif /* defined(__Lab1__Parser__) */