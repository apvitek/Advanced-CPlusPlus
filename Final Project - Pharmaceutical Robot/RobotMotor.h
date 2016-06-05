//
//  RobotMotor.h
//  FinalLab
//
//  Created by Andrea Borghi on 6/21/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include <iostream>
#include <mutex>
#include <cmath>
#include "MotionCalculator.h"

const char DEFAULT_AXIS = 'x';
const double DEFAULT_RADIUS = 3.9894;
const int MILLISECONDS = 100;

using namespace std;

class RobotMotor {
private:
    char axis;
    double radius;
    double currentPositionOnAxis;
    double currentRate; // In millimeters/second
    double currentDistance;
    double totalTimeInSecond;
    double totalDistance;
    bool positiveDirection;
    double targetPosition;
    mutex * privateMutex;
    condition_variable * condition;
    bool stopped;
    string currentStatus;
    
    void accelerate(double maxRate);
    void decelerate(bool isStopped);
    double decelerationFormula(double velocity, double distance) { return -(pow(velocity, 2) / (distance * 2)); }
    
public:
    RobotMotor(double radius, char axis) : radius(radius), axis(axis), currentPositionOnAxis(0), currentRate(0), stopped(false) {
        if (axis != 'x' && axis != 'y' && axis != 'z') {
            cout << "Wrong axis specified, setting to default " << DEFAULT_AXIS << "." << endl;
            
            axis = DEFAULT_AXIS;
        }
    }
    
    RobotMotor(char axis) : RobotMotor(DEFAULT_RADIUS, axis) {}
    RobotMotor() : RobotMotor(DEFAULT_RADIUS, DEFAULT_AXIS) {}
    
    double getCurrentPositionOnAxis() { return currentPositionOnAxis; }
    double getCurrentRate() { return currentRate; }
    void moveToPosition(double p, double rate, mutex& mu, condition_variable& cv);
    void returnToOrigin(double rate, std::mutex& mu, condition_variable& cv) { moveToPosition(0, rate, mu, cv); }
    void stop();
    double getMotorCircumference() { return ceil(2 * PI * pow(radius, 2)); }
    string getCurrentStatus() { return currentStatus; }
    void restartMotor() { if (stopped) stopped = false; }
};

void RobotMotor::moveToPosition(double p, double maxRate, mutex& mu, condition_variable& cv)
{
    privateMutex = &mu;
    condition = &cv;
    targetPosition = p;
    currentDistance =  p - currentPositionOnAxis;
    totalTimeInSecond = 0.0;
    totalDistance = currentDistance;
    
    unique_lock<mutex> lk(*privateMutex);
    
    //cout << "\nCalculating distance on " << axis << " axis... " << p << " - " << currentPositionOnAxis << " = " << currentDistance << endl;
    
    if (totalDistance < 0) totalDistance = -totalDistance;
    
    if (currentDistance == 0) {
        lk.unlock();
        
        return;
    }
    
    positiveDirection = true;
    
    if (currentDistance < 0) {
        positiveDirection = false;
        
        currentDistance = abs(currentDistance);
    }
    
    lk.unlock();

    accelerate(maxRate);
    
    while (currentDistance >= 0 && !stopped) {
        lk.lock();
        
        positiveDirection ? currentPositionOnAxis += currentRate : currentPositionOnAxis -= currentRate;
        
        currentDistance -= currentRate;
        
        cout << axis << ": position " << currentPositionOnAxis << " @ " << maxRate << " mm/second" << endl;
        
        if (abs(currentDistance - currentRate) < currentRate) {
            lk.unlock();
            
            decelerate(stopped);
            
            break;
        }
        
        this_thread::sleep_for(chrono::milliseconds(MILLISECONDS));
        
        totalTimeInSecond += 1;
        
        lk.unlock();
    }
    
    lk.lock();
    
    if (!stopped) {
        cout << "\tARRIVED!\n\tMoving " << totalDistance << " millimeters on the " << axis << " axis took " << totalTimeInSecond << " seconds." << endl;
        cout << "***************************************************************" << endl;
    }
    
    currentRate = 0;
    
    lk.unlock();
    
    condition->notify_one();
}

void RobotMotor::accelerate(double maxRate)
{
    unique_lock<mutex> lk(*privateMutex);
    
    double acceleration = maxRate / 2;
    
    lk.unlock();
    
    while (currentRate < maxRate && !stopped) {
        lk.lock();
        
        currentRate += acceleration;
        
        if (positiveDirection) {
            currentDistance -= currentRate;
            currentPositionOnAxis += currentRate;
            
        } else {
            currentDistance -= currentRate;
            currentPositionOnAxis -= currentRate;
        }
        
        cout << axis << ": (ACCELERATING) position " << currentPositionOnAxis << " @ " << currentRate << " mm/second" << endl;
        
        this_thread::sleep_for(chrono::milliseconds(MILLISECONDS));
        
        totalTimeInSecond += 1;
        
        lk.unlock();
    }
    
    currentRate = maxRate;
}

void RobotMotor::decelerate(bool isStopped)
{
    unique_lock<mutex> lk(*privateMutex);
    
    double deceleration = decelerationFormula(currentRate, currentDistance);
    
    if (deceleration > 0) deceleration = -deceleration;
    
    //cout << "The deceleration required on the " << axis << " axis is " << deceleration << " mm/s" << endl;
    
    lk.unlock();
    
    while (currentDistance > 0 && !isStopped) {
        lk.lock();
        
        currentRate += deceleration;
        
        if (abs(currentRate) > currentDistance || currentRate + deceleration < 0) {
            currentRate = currentDistance;
        }
        
        if (positiveDirection) {
            currentDistance -= currentRate;
            currentPositionOnAxis += currentRate;
            
        } else {
            currentDistance -= currentRate;
            currentPositionOnAxis -= currentRate;
        }
        
        lk.unlock();
        
        lk.lock();
        
        cout << axis << ": (DECELERATING) position " << currentPositionOnAxis << " @ " << currentRate << " mm/second" << endl;
        
        this_thread::sleep_for(chrono::milliseconds(MILLISECONDS));
        
        totalTimeInSecond += 1;
        
        lk.unlock();
    }
}

void RobotMotor::stop()
{
    stopped = true;
    
    privateMutex->unlock();
    
    decelerate(false);
    
    privateMutex->lock();
    cout << "\n\t*** " << axis << " MOTOR STOPPED! ***" << endl;
    privateMutex->unlock();
    
    condition->notify_one();
}