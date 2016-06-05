//
//  RobotCommand.h
//  Lab0
//
//  Created by Andrea Borghi on 4/15/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef Lab0_RobotCommand_h
#define Lab0_RobotCommand_h

#include "Command.h"

class RobotCommand : public Command {
private:
    unsigned char speed;
    unsigned char rotation;
    
public:
    // Default constructor
    RobotCommand(){};
    RobotCommand(unsigned int instruction);
    
    // Setter functions
    void setCommandSpeed(unsigned char s);
    void setCommandRotation(unsigned char r);
    
    // Getter functions
    unsigned char getCommandSpeed();
    unsigned char getCommandRotation();
    unsigned char getCommand();
};

#endif
