//
//  RobotInstructionGetter.cpp
//  Lab0
//
//  Created by Andrea Borghi on 4/15/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include "RobotInstructionGetter.h"

string RobotInstructionGetter::getInstruction()
{
    // Declare a temporary string variable
    string instruction;
    
    // Call the utlity member function to get the instruction's speed
    char speed = getInstructionSpeed();
    
    // Append the speed to the instruction
    instruction += speed;
    
    // Call the utlity member function to get the instruction's rotation
    int rotation = getInstructionRotation();
    
    // Append a string representation of the rotation to the instruction
    instruction += to_string(rotation);
    
    // Return the instruction
    return instruction;
}

// Utility function to get the speed of the command from user
char RobotInstructionGetter::getInstructionSpeed()
{
    // Variables declaration
    bool successful = false;
    char speed = 'l';
    
    while (!successful) {
        cout << "Command execution speed: enter 'l' for LOW and 'h' for HIGH." << endl;
		
        // Get user input
        cin >> speed;
        
		// Check input's range
        if (speed == 'l' || speed == 'h') {
            successful = true;
            
        } else {
            cout << "Invalid key. Please enter 'l' for LOW and 'h' for HIGH." << endl;
            cin.clear();
            cin.ignore(90, '\n');
        }
    }
    
    return speed;
}

// Utility function to get the rotation of the command from user
int RobotInstructionGetter::getInstructionRotation()
{
    // Variables declaration
    bool successful = false;
    int rotation = 0;
    
    while (!successful) {
        cout << "Command execution speed: enter '0', '90', '180', '270' or '360'." << endl;
		
        // Get user input
        cin >> rotation;
        
		// Check input's range
        if (rotation == 0 || rotation == 90 || rotation == 180 || rotation == 270 || rotation == 360) {
            successful = true;
            
        } else {
            cout << "Invalid value. Please enter '0', '90', '180', '270' or '360'." << endl;
            cin.clear();
            cin.ignore();
        }
    }

    return rotation;
}