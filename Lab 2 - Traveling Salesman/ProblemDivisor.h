//
//  ProblemDivisor.h
//  Lab2
//
//  Created by Andrea Borghi on 5/15/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef __Lab2__ProblemDivisor__
#define __Lab2__ProblemDivisor__

#include <iostream>
#include <vector>
#include <math.h>
#include "Location.h"

using namespace std;

class ProblemDivisor {
private:
    int maxProblemSize;
    const int minProblemSize = 4;
    
public:
    ProblemDivisor(int maxProbsize);
    vector<vector<Location>> breakProblem(vector<Location> * dataVector);
};

#endif /* defined(__Lab2__ProblemDivisor__) */