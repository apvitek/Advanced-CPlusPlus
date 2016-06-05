//
//  PrecedenceController.h
//  Lab1
//
//  Created by Andrea Borghi on 4/27/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef __Lab1__PrecedenceController__
#define __Lab1__PrecedenceController__

#include <iostream>

using namespace std;

class PrecedenceController {
public:
    int compareOperators(string left, string right);
    bool isOperator(string character);
    bool isOperand(string character);
};

#endif /* defined(__Lab1__PrecedenceController__) */
