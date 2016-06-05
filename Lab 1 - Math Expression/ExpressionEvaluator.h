//
//  ExpressionEvaluator.h
//  Lab1
//
//  Created by Andrea Borghi on 4/27/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef __Lab1__ExpressionEvaluator__
#define __Lab1__ExpressionEvaluator__

#include <iostream>
#include <stack>
#include <queue>
#include "PostfixFormat.h"
#include "PrecedenceController.h"

using namespace std;

class ExpressionEvaluator {
private:
    PrecedenceController * controller;

public:
    ExpressionEvaluator();
    double evaluateExpression(PostfixFormat * expression);
    ~ExpressionEvaluator();
};

#endif /* defined(__Lab1__ExpressionEvaluator__) */