//
//  Controller.h
//  Lab0
//
//  Created by Andrea Borghi on 4/15/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include "Robot.h"
#include "InstructionGetter.h"
#include "InstructionParser.h"

ROBOT_SDK_DEFINES(opcode)
ROBOT_SDK_CONTAINER(Container,queue,unsigned char)
ROBOT_SDK_AUTO(Robot,unsigned char)

using namespace std;

#ifndef Lab0_Controller_h
#define Lab0_Controller_h

class Controller {
protected:
    Container commandList;
    InstructionGetter * instructionGetter;
    InstructionParser * instructionParser;
    
public:
    virtual bool addCommand() = 0;
    virtual void executeCommandList() = 0;
};

#endif