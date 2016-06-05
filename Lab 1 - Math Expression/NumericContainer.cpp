//
//  NumericContainer.cpp
//  Lab1
//
//  Created by Andrea Borghi on 4/27/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include "NumericContainer.h"

NumericContainer::NumericContainer()
{
    numberQueue = new queue<double>();
}

void NumericContainer::push_back(double number)
{
    numberQueue -> emplace(number);
}

double NumericContainer::pop_front()
{
    double front = numberQueue -> front();
    
    numberQueue -> pop();
    
    return front;
}

double NumericContainer::peek()
{
    return numberQueue -> front();
}

bool NumericContainer::isEmpty()
{
    return numberQueue -> empty();
}

NumericContainer::~NumericContainer()
{
    delete numberQueue;
}