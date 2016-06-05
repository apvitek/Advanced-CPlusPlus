//
//  Position3D.h
//  LastLab
//
//  Created by Andrea Borghi on 6/21/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include <iostream>

#ifndef Position_h
#define Position_h

using namespace std;

class Position {
private:
    double x, y, z;
public:
    Position() : x(0), y(0), z(0) {}
    Position(double x, double y, double z) : x(x), y(y), z(z) {}
    
    void setX(double inputX) { x = inputX; }
    void setY(double inputY) { y = inputY; }
    void setZ(double inputZ) { z = inputZ; }
    
    double getX() { return x; }
    double getY() { return y; }
    double getZ() { return z; }
    
    friend ostream& operator << (ostream& os, const Position& pos) { return os << "(" << pos.x << ", " << pos.y << ", " << pos.z << ")"; }
};

#endif