//
//  RobotCommand.h
//  Lab0
//
//  Created by Andrea Borghi on 4/15/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef RobotCommand_h
#define RobotCommand_h

#include <iostream>

using namespace std;

class Command {
protected:
    unsigned char command;
    
public:
    virtual unsigned char getCommand() = 0;
};

class RobotCommand : public Command {
private:
    double rotationsInX, rotationsInY, rotationsInZ;
    
public:
    RobotCommand(){};
    RobotCommand(unsigned int instruction) { command = instruction; }
    RobotCommand(double x, double y, double z) { rotationsInX = x; rotationsInY = y; rotationsInZ = z; }
    
    void setCommandRotationsForX(double x) {rotationsInX = x; }
    void setCommandRotationsForY(double y) {rotationsInX = y; }
    void setCommandRotationsForZ(double z) {rotationsInX = z; }
    
    double getCommandRotationsForX() { return rotationsInX; }
    double getCommandRotationsForY() { return rotationsInY; }
    double getCommandRotationsForZ() { return rotationsInZ; }
    
    unsigned char getCommand() { return command; }
};

#endif