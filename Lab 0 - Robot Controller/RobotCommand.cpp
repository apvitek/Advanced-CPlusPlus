//
//  RobotCommand.cpp
//  Lab0
//
//  Created by Andrea Borghi on 4/15/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include "RobotCommand.h"

RobotCommand::RobotCommand(unsigned int instruction)
{
    command = instruction; 
}

void RobotCommand::setCommandSpeed(unsigned char s)
{
    speed = s;
    command = speed | rotation;
}

void RobotCommand::setCommandRotation(unsigned char r)
{
    rotation = r;
    command = speed | rotation;
}

unsigned char RobotCommand::getCommandSpeed()
{
    return speed;
}

unsigned char RobotCommand::getCommandRotation()
{
    return rotation;
}

unsigned char RobotCommand::getCommand()
{
    return command;
}