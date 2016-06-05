//
//  RobotInstructionParser.h
//  Lab0
//
//  Created by Andrea Borghi on 4/15/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef __Lab0__RobotInstructionParser__
#define __Lab0__RobotInstructionParser__

#include "InstructionParser.h"

#include <iostream>

class RobotInstructionParser : public InstructionParser {
private:
    
public:
    RobotCommand * parseInstruction(string instruction);
    bool isValidInstruction(string instruction);
    // Default destructor
    ~RobotInstructionParser(){};
};

#endif /* defined(__Lab0__RobotInstructionParser__) */
