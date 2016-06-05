//
//  InstructionParser.h
//  Lab0
//
//  Created by Andrea Borghi on 4/15/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef Lab0_InstructionParser_h
#define Lab0_InstructionParser_h

#include <string>
#include "Command.h"
#include "RobotCommand.h"

using namespace std;

class InstructionParser { 
public:
    virtual Command * parseInstruction(string instruction) = 0;
    virtual bool isValidInstruction(string instruction) = 0;
    // Default destructor
    virtual ~InstructionParser() {};
};

#endif
