//
//  RobotController.h
//  Lab0
//
//  Created by Andrea Borghi on 4/11/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef __Lab0__RobotController__
#define __Lab0__RobotController__

#include <iostream>
#include <string>
#include "Robot.h"
#include "Controller.h"
#include "RobotInstructionGetter.h"
#include "RobotInstructionParser.h"

using namespace std;

class RobotController : public Controller {
private:
    // Private variables
    Robot * robot; // To store a pointer to a Robot object
    
public:
    // Default constructor
    RobotController(Robot * aRobot);
    bool addCommand();
    void executeCommandList();
    // Default destructior
    ~RobotController();
};

#endif /* defined(__Lab0__RobotController__) */