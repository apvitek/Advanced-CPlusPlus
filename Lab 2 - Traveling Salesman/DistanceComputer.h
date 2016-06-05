//
//  DistanceComputer.h
//  Lab2
//
//  Created by Andrea Borghi on 5/10/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef __Lab2__DistanceComputer___
#define __Lab2__DistanceComputer___

#include <iostream>
#include <cmath>

using namespace std;

class DistanceComputer {
private:
    struct firstLocation
    {
        double latitude;
        double longitude;
    };
    
    struct secondLocation
    {
        double latitude;
        double longitude;
    };
    
public:
    double operator()(double th1, double ph1, double th2, double ph2);
};

#endif /* defined(__Lab2__DistanceComputer___) */
