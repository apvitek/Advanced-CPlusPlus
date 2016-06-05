//
//  Vector.h
//  LastLab
//
//  Created by Andrea Borghi on 6/21/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <iomanip>
#include "Position.h"

using namespace std;

#define DEGREES double
#define PI 3.14159265

#ifndef Vector_h
#define Vector_h

const int FULL_ROTATION = 360;

class Vector {
private:
    double i, j, k;
    double magnitude;
    DEGREES direction;
    
    void calculateMagnitude() { magnitude = sqrt(pow(i, 2) + pow(j, 2) + pow(k, 2)); }
    void calculateDirection() {
        direction = (atan2(j, i) * 180) / PI;
        
        if (direction < 0) direction = FULL_ROTATION + direction;
    }
    
public:
    Vector(): i(0), j(0), k(0), magnitude(0), direction(0) {}
    Vector(int i, int j, int k): i(i), j(j), k(k) { calculateMagnitude(); calculateDirection(); }
    Vector(Position initial, Position final): i(floor(final.getX() - initial.getX())), j(floor(final.getY() - initial.getY())), k(floor(final.getZ() - initial.getZ())) { calculateMagnitude(); calculateDirection(); }
    
    int getI() { return i; }
    int getJ() { return j; }
    int getK() { return k; }
    
    double getMagnitude() { calculateMagnitude(); return magnitude; }
    double getSlope() { return j / i; }
    
    friend ostream& operator << (ostream& os, const Vector& v) { return os << "<" << v.i << ", " << v.j << ", " << v.k << "> magnitude: " << v.magnitude << " direction: " << v.direction << " degrees"; }
};

#endif