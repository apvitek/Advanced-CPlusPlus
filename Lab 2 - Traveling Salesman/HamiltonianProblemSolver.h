//
//  HamiltonianProblemSolver.h
//  Lab2
//
//  Created by Andrea Borghi on 5/16/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef __Lab2__HamiltonianProblemSolver__
#define __Lab2__HamiltonianProblemSolver__

#include <iostream>
#include "LocationContainer.h"
#include "ProblemDivisor.h"

using namespace std;

class HamiltonianProblemSolver {
private:
    ProblemDivisor * divisor;
    
public:
    HamiltonianProblemSolver(int maxProblemSize);
    ~HamiltonianProblemSolver();
    void solveProblem(vector<Location> * parsedStrings);
    
};

#endif /* defined(__Lab2__HamiltonianProblemSolver__) */
