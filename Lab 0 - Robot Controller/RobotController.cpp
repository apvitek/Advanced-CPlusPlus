//
//  RobotController.cpp
//  Lab0
//
//  Created by Andrea Borghi on 4/11/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include "RobotController.h"

// Default constructor
RobotController::RobotController(Robot * aRobot)
{
    // Assign the pointer parameter to the instance pointer variable robot
    robot = aRobot;
    
    // Dynamically allocate memory for instructionGetter and instructionParser member classes
    instructionGetter = new RobotInstructionGetter();
    instructionParser = new RobotInstructionParser();
}

bool RobotController::addCommand()
{
    // Variables declaration
    bool cont = true; // To control the while loop execution
    char yesOrNo = 'y'; // To store the user's choice to stop the loop or not
    
    // While loop to control the amount of commands added to the robotCommandList
    while (cont) {
        // Set flag variable to false
        cont = false;
        
        // Prompt the user wether to add another command or not
        cout << "Would you like to add a command? Enter y for YES and any other key for no." << endl;
        
        // Get user inpit
        cin >> yesOrNo;
        
        // If the character entered by the user is 'y' or 'Y', set flag variable to true and call a private function to get the command
        if (yesOrNo == 'y' || yesOrNo == 'Y') {
            // Set the flag variable to true
            cont = true;
            
            // Get instruction from the member object instructionGetter and store it in a temporary variable
            string instruction = instructionGetter -> getInstruction();
            
            // Allocate a new RobotCommand
            RobotCommand * command = new RobotCommand();
            
           // Assign to the new RobotCommand the result created by the instructionParser
            command = static_cast<RobotCommand *>((instructionParser -> parseInstruction(instruction)));
            
            // Add the command to turn on the robot to the list
            commandList.set(CCC);
            
            // Add the command related to the speed to the list
            commandList.set(command -> getCommandSpeed());
            
            // Add the command related to the rotation to the list
            commandList.set(command -> getCommandRotation());
            
            // Add the execute command
            commandList.set(KKK);
        }
    };
    
    return cont;
}

void RobotController::executeCommandList()
{
    robot -> execute(commandList);
}

RobotController::~RobotController()
{
    delete instructionGetter;
    delete instructionParser;
}