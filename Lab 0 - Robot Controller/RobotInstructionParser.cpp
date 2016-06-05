//
//  RobotInstructionParser.cpp
//  Lab0
//
//  Created by Andrea Borghi on 4/15/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include "RobotInstructionParser.h"
#include "Controller.h"

RobotCommand * RobotInstructionParser::parseInstruction(string instruction)
{
    // Instantiate a new empty RobotCommand
    RobotCommand * robotCommand = new RobotCommand();
    
    // Set the corresponding opcode for the command speed in robotCommand
    if (instruction[0] == 'l') {
        robotCommand -> setCommandSpeed(DDD);
        
    } else {
        robotCommand -> setCommandSpeed(EEE);
    }
    
    // Trim the first character of the instruction
    instruction.erase(instruction.begin());
    
    // Set the corresponding opcode for the command rotation in robotCommand
    if (instruction == "90") {
        robotCommand -> setCommandRotation(FFF);
    
    } else if (instruction == "180") {
        robotCommand -> setCommandRotation(GGG);
    
    } else if (instruction == "270"){
        robotCommand -> setCommandRotation(HHH);
    
    } else if (instruction == "360" || instruction == "0"){
        robotCommand -> setCommandRotation(JJJ);
    }
    
    return robotCommand;
}

// This function is a stub, not fully implemented
bool RobotInstructionParser::isValidInstruction(string instruction)
{
    return ((instruction[0] == 'h' || instruction[0] == 'l') && (instruction.length() <= 4));
}