//
//  main.cpp
//  Lab0
//
//  Created by Andrea Borghi on 4/9/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include <iostream>
#include "Robot.h"
#include "RobotController.h"

using namespace std;

int main(int argc, const char * argv[])
{
    // Instantiate a new Robot
    Robot * robot = new Robot(true);
    
    // Instantiate a new RobotController
    RobotController * controller = new RobotController(robot);
    
    // Call a method to add RobotCommands
    controller -> addCommand();
    
    // Call a method to execute the RobotCommands list
    controller -> executeCommandList();
    
    // Deallocate controller object
    delete controller;
    
    // Deallocate robot object
    delete robot;
}