//
//  ProblemDivisor.cpp
//  Lab2
//
//  Created by Andrea Borghi on 5/15/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include "ProblemDivisor.h"

ProblemDivisor::ProblemDivisor(int maxProbSize)
{
    maxProblemSize = maxProbSize;
}

vector<vector<Location>> ProblemDivisor::breakProblem(vector<Location> * dataVector)
{
    int vectorsAmount = ((int)dataVector->size() / maxProblemSize) + 1;
    
    int dataPerVector = (int)dataVector->size() / (int)vectorsAmount;
    
    dataPerVector = (int)dataVector->size() / vectorsAmount;
    
    dataPerVector++;
    
    if (dataPerVector > maxProblemSize) {
        dataPerVector = maxProblemSize;
        
    } else if (dataPerVector < minProblemSize) {
        dataPerVector = minProblemSize;
    }
    
    vector<vector<Location>> dividedData(vectorsAmount);
    
    int i = 0;
    int maxElems = 0;
    
    for (auto it = dataVector->begin(); it != dataVector->end(); ++it) {
        dividedData[i].push_back(*it);
        
        ++maxElems;
        
        if (maxElems == dataPerVector) {
            maxElems = 0;
            
            ++i;
        }
    }
    
    while (dividedData[dividedData.size() - 1].size() <= 1) {
        dividedData.resize(dividedData.size() - 1);
    }
    
    return dividedData;
}