//
//  RobotCommandGenerator.h
//  LastLab
//
//  Created by Andrea Borghi on 6/26/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include <iostream>
#include "RobotCommand.h"
#include "MotionCalculator.h"

using namespace std;

class RobotCommandGenerator {
private:
    double maxX, maxY, maxZ;
    
public:
    RobotCommandGenerator(double maxHorizontal, double maxVertical, double maxRound) : maxX(maxHorizontal), maxY(maxVertical), maxZ(maxRound) {}
    
    RobotCommand generateCommand()
    {
        double randomX = rand() % (int)maxX;
        double randomY = rand() % (int)maxY;
        double randomZ = maxZ;
        
        if ((rand() % (int)maxZ) % 2 == 0) randomZ = -randomZ;
        
        return RobotCommand(randomX, randomY, randomZ);
    }
};