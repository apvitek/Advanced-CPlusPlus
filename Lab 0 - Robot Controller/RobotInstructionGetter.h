//
//  RobotInstructionGetter.h
//  Lab0
//
//  Created by Andrea Borghi on 4/15/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef __Lab0__RobotInstructionGetter__
#define __Lab0__RobotInstructionGetter__

#include <iostream>
#include "InstructionGetter.h"

class RobotInstructionGetter : public InstructionGetter {
private:
    char getInstructionSpeed();
    int getInstructionRotation();
    
public:
    string getInstruction();
    // Default destructor
    ~RobotInstructionGetter(){};
};

#endif /* defined(__Lab0__RobotInstructionGetter__) */
