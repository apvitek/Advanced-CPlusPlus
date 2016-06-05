//
//  NumericContainer.h
//  Lab1
//
//  Created by Andrea Borghi on 4/27/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef __Lab1__NumericContainer__
#define __Lab1__NumericContainer__

#include <iostream>
#include <queue>

using namespace std;

class NumericContainer {
private:
    queue<double> * numberQueue;
    
public:
    NumericContainer();
    void push_back(double number);
    double pop_front();
    double peek();
    bool isEmpty();
    ~NumericContainer();
};

#endif /* defined(__Lab1__NumericContainer__) */
