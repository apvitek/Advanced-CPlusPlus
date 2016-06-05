//
//  OneFile.cpp
//  Lab0
//
//  Created by Andrea Borghi on 4/21/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

#define ROBOT_SDK_DEFINES(name) enum name {AAA = 0x00,BBB = 0x01,CCC = 0x02,DDD = 0x04,EEE = 0x08,FFF = 0x10,GGG = 0x20,HHH = 0x40,JJJ = 0x80,KKK = 0xFF};

#define ROBOT_SDK_CONTAINER(name,container,type) class name : container<type> { public: type get() { type t = front(); pop(); return t; } void set( type t ) { push(t); } bool empty() { return container::empty(); } };

#define ROBOT_SDK_AUTO(name,type) class name { bool b; public: name(bool f=false) : b(f) { cout<<"Robot starting..."<< endl; } void execute(Container& c) { type t=0; while(!c.empty()){ type tt=c.get(); if(tt==KKK) { action(t); t=0; } else { t += tt; if (b) { string s = bits(t); string ss = bits(tt); cout << "command " << s << "\topcode " << ss << endl; }}}} ~Robot() { cout << "Robot stopped...." << endl; } void action(type t){ if ( t & BBB ) { cout << "Executing BBB" << endl; return; } switch (t) { case CCC+DDD+FFF:cout << "Executing Low speed 90" << endl; break; case CCC+EEE+FFF:cout << "Executing High speed 90" << endl; break;case CCC+DDD+GGG:cout << "Executing Low speed 180" << endl; break;case CCC+EEE+GGG:cout << "Executing High speed 180" << endl; break;case CCC+DDD+HHH:cout << "Executing Low speed 270" << endl; break;case CCC+EEE+HHH:cout << "Executing High speed 270" << endl; break;case CCC+DDD+JJJ:cout << "Executing Low speed 360" << endl; break;case CCC+EEE+JJJ:cout << "Executing High speed 360" << endl; break;default:cout << "Invalid command " << (int)t << endl; }} string bits(unsigned char cmd){string s = "00000000";int i = 0x01;for (int x=0; x<0x08; x++){ if ( i & cmd )s[0x07-x] = 0x31;i <<= 0x01;}return s;} };

ROBOT_SDK_DEFINES(opcode)
ROBOT_SDK_CONTAINER(Container,queue,unsigned char)
ROBOT_SDK_AUTO(Robot,unsigned char)

class Command {
protected:
    unsigned char command;
    
public:
    virtual unsigned char getCommand() = 0;
};

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

class InstructionGetter {
public:
    virtual string getInstruction() = 0;
    virtual ~InstructionGetter(){};
};

class RobotInstructionGetter : public InstructionGetter {
private:
    char getInstructionSpeed();
    int getInstructionRotation();
    
public:
    string getInstruction();
    // Default destructor
    ~RobotInstructionGetter(){};
};

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

class InstructionParser {
public:
    virtual Command * parseInstruction(string instruction) = 0;
    virtual bool isValidInstruction(string instruction) = 0;
    // Default destructor
    virtual ~InstructionParser() {};
};

class RobotInstructionParser : public InstructionParser {
private:
    
public:
    RobotCommand * parseInstruction(string instruction);
    bool isValidInstruction(string instruction);
    // Default destructor
    ~RobotInstructionParser(){};
};

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

class Controller {
protected:
    Container commandList;
    InstructionGetter * instructionGetter;
    InstructionParser * instructionParser;
    
public:
    virtual bool addCommand() = 0;
    virtual void executeCommandList() = 0;
};

class RobotController : public Controller {
private:
    // Private variables
    Robot * robot; // To store a pointer to a Robot object
    
public:
    // Default constructor
    RobotController(Robot * aRobot);
    bool addCommand();
    void executeCommandList();
    // Default destructior
    ~RobotController();
};

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