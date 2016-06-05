//
//  TaskManager.h
//  FinalLab
//
//  Created by Andrea Borghi on 6/21/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include <iostream>
#include <queue>
#include <chrono>
#include <thread>
#include "PharmaceuticalRobotArm.h"
#include "MotionCalculator.h"
#include "RobotCommand.h"
#include "Vector.h"
#include <cmath>

using namespace std;
using namespace chrono;

const int SPEED_MULT_FACTOR = 200;

class TaskManager {
private:
    PharmaceuticalRobotArm * robot;
    MotionCalculator * calculator;
    queue<RobotCommand> instructionsList;
    std::mutex printingMutex;
    condition_variable printingVariable;
    std::mutex stoppingMutex;
    condition_variable stoppingVariable;
    bool stopped;
    
    void moveXRobot(double distance, double rate) { robot->moveXMotor(distance, rate, printingMutex, printingVariable); }
    void moveYRobot(double distance, double rate) { robot->moveYMotor(distance, rate, printingMutex, printingVariable); }
    void moveZRobot(double distance, double rate) { robot->moveZMotor(distance, rate, printingMutex, printingVariable); }
    
    void printRobotPosition();
    Position parseCommand(RobotCommand newCommand);
    
public:
    TaskManager() : robot(new PharmaceuticalRobotArm()), calculator(new MotionCalculator(robot->getMotorsCircumference())), stopped(false) {}
    ~TaskManager() { delete robot; delete calculator; }
    
    void addCommand(RobotCommand pos) { instructionsList.push(pos); }
    void executeCommandList();
    void moveToPosition(Position p);
    void moveToPosition(double x, double y, double z) { moveToPosition(Position(x,y,z)); }
    void returnToOrigin() { moveToPosition(0, 0, 0); }
    void stopRobot();
    void restartRobot() {
        if (stopped) {
            stopped = false;
            
            robot->restart();
        }
    }
    bool isStopped() { return stopped; }
    Position getRobotPosition() { return robot->getCurrentPosition(); }
};

void TaskManager::printRobotPosition()
{
    std::unique_lock<std::mutex> lk(printingMutex);
    
    printingVariable.wait(lk, [&]() { return !stopped; });
    
    cout << "\tThe current robot position is " << robot->getCurrentPosition() << "." << endl;
}

Position TaskManager::parseCommand(RobotCommand newCommand)
{
    double randomX = calculator->convertRotationsToDistance(newCommand.getCommandRotationsForX());
    double randomY = calculator->convertRotationsToDistance(newCommand.getCommandRotationsForY());
    double randomZ = calculator->convertRotationsToDistance(newCommand.getCommandRotationsForZ());
    
    return Position(randomX, randomY, randomZ);
}

void TaskManager::executeCommandList()
{
    while (!instructionsList.empty() && !stopped) {
        moveToPosition(parseCommand(instructionsList.front()));
        
        instructionsList.pop();
    }
}

void TaskManager::stopRobot()
{
    stopped = true;
    
    cout << "\t*** EMERGENCY STOP! ***" << endl;
    
    robot->stop();
}

void TaskManager::moveToPosition(Position p)
{
    calculator->setInitial(robot->getCurrentPosition());
    calculator->setFinal(p);
    
    cout << "\nThe robot will move from " << robot->getCurrentPosition() << " to " << p << " (vector " << calculator->getMovement() << ")." << endl;
    
    std::thread xAxisThread(&TaskManager::moveXRobot, this, p.getX(), abs((calculator->getMovementInX() / calculator->getMagnitude()) * SPEED_MULT_FACTOR));
    std::thread yAxisThread(&TaskManager::moveYRobot, this, p.getY(), abs((calculator->getMovementInY() / calculator->getMagnitude()) * SPEED_MULT_FACTOR));
    std::thread zAxisThread(&TaskManager::moveZRobot, this, p.getZ(), abs((calculator->getMovementInZ() / calculator->getMagnitude()) * SPEED_MULT_FACTOR));
    std::thread positionThread(&TaskManager::printRobotPosition, this);

    xAxisThread.join();
    yAxisThread.join();
    zAxisThread.join();
    positionThread.join();
}