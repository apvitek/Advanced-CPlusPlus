//
//  MotionCalculator.h
//  FinalLab
//
//  Created by Andrea Borghi on 6/21/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include <iostream>
#include "Vector.h"

using namespace std;

#ifndef MotionCalculator_h
#define MotionCalculator_h

#define ROTATION_SECOND unsigned double
#define COMPLETE_ROTATION 360

class MotionCalculator {
private:
    Position initial, final;
    Vector movement;
    double millimetersPerRotation;
    
    void makeVector() { movement = Vector(initial, final); }
    
public:
    MotionCalculator(double millimetersPerRotation) { this->millimetersPerRotation = millimetersPerRotation; }
    
    void setInitial(Position i) { initial = i; }
    void setFinal(Position f) { final = f; }
    void setInitial(double x, double y, double z) { initial.setX(x); initial.setY(y); initial.setZ(z); }
    void setFinal(double x, double y, double z) { final.setX(x); final.setY(y); final.setZ(z); }
    
    Vector getMovement() { makeVector(); return movement; }
    
    double getMagnitude() { makeVector(); return movement.getMagnitude(); }
    double getMovementInX() { makeVector(); return movement.getI(); }
    double getMovementInY() { makeVector(); return movement.getJ(); }
    double getMovementInZ() { makeVector(); return movement.getK(); }
    
    Position getInitial() { return initial; }
    Position getFinal() { return final; }
    
    double convertDistanceToRotations(double distance) { return distance / millimetersPerRotation; }
    double convertRotationsToDistance(double rotations) { return rotations * millimetersPerRotation; }
};

#endif