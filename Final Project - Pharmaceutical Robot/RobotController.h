//
//  RobotController.h
//  LastLab
//
//  Created by Andrea Borghi on 6/22/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include <iostream>
#include "TaskManager.h"
#include "OperationalSpace.h"
#include "RobotCommandGenerator.h"

using namespace std;

class RobotController {
private:
    TaskManager * manager;
    OperationalSpace * workingArea;
    RobotCommandGenerator * generator;
    mutex locker;
    
    RobotCommand generateRandomCommand() { return generator->generateCommand(); }
    char getUserInput();
    void getStopCommand();
    
public:
    RobotController() : manager(new TaskManager()), workingArea(new OperationalSpace()), generator(new RobotCommandGenerator(workingArea->getLength() / 100, workingArea->getHeight() / 100, 1)) {}
    ~RobotController() { delete manager; delete workingArea; delete generator; }
    
    void turnOn();
    void start();
    void stop();
};

char RobotController::getUserInput()
{
    char input;
    
    cin.get(input);
    
    return input;
}

void RobotController::getStopCommand()
{
    if (cin.get()) {
        cin.clear();
        cin.ignore(256, '\n');
        
        stop();
    }
}

void RobotController::turnOn()
{
    char loop;
    
    while (loop != 'n') {
        cout << "Would you like to start the robot? Press 'y' for yes, press 'n' to quit." << endl;
        cout << "At any time doing the robot movement, press any hey and return to stop it." << endl;
        cout << "The execution time of the robot's movements printed on screen does not match the real time intentionally for demostrantion purposes." << endl;
        
        loop = getUserInput();
        
        if (loop == 'y') {
            cin.clear();
            cin.ignore(256, '\n');
            
            if (manager->isStopped()) manager->restartRobot();
            
            start();
        }
    }
    
    cout << "Goodbye!" << endl;
}

void RobotController::start()
{
    thread getInput(&RobotController::getStopCommand, this);
    
    for (int i = 0; i < 100; ++i) manager->addCommand(generateRandomCommand());
    
    getInput.detach();
    
    manager->addCommand(RobotCommand(0, 0, 0));
    
    manager->executeCommandList();
}

void RobotController::stop()
{
    manager->stopRobot();
}