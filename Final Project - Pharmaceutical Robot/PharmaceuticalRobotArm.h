//
//  PharmaceuticalRobotArm.h
//  LastLab
//
//  Created by Andrea Borghi on 6/26/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include <iostream>
#include "RobotMotor.h"

using namespace std;

class RobotArm {
private:
    RobotMotor * motor;
    
public:
    RobotArm() : motor(new RobotMotor()) {};
    ~RobotArm() { delete motor; }
    
    virtual Position getCurrentPosition() { return Position(motor->getCurrentPositionOnAxis(), 0 ,0); }
    virtual void moveMotor(double position, double rate, mutex& mu, condition_variable& cv) { motor->moveToPosition(position, rate, mu, cv); }
    virtual void stop() { motor->stop(); }
    virtual void restart() { motor->restartMotor(); }
};

class PharmaceuticalRobotArm : public RobotArm {
private:
    RobotMotor * XMotor;
    RobotMotor * YMotor;
    RobotMotor * ZMotor;
    
public:
    PharmaceuticalRobotArm() : XMotor(new RobotMotor('x')), YMotor(new RobotMotor('y')), ZMotor(new RobotMotor('z')) {}
    ~PharmaceuticalRobotArm() { delete XMotor; delete YMotor; delete ZMotor; }
    
    Position getCurrentPosition() { return Position(XMotor->getCurrentPositionOnAxis(), YMotor->getCurrentPositionOnAxis(), ZMotor->getCurrentPositionOnAxis()); }
    
    void moveXMotor(double position, double rate, mutex& mu, condition_variable& cv) { XMotor->moveToPosition(position, rate, mu, cv); }
    void moveYMotor(double position, double rate, mutex& mu, condition_variable& cv) { YMotor->moveToPosition(position, rate, mu, cv); }
    void moveZMotor(double position, double rate, mutex& mu, condition_variable& cv) { ZMotor->moveToPosition(position, rate, mu, cv); }
    
    void stop() { XMotor->stop(); YMotor->stop(); ZMotor->stop(); }
    void restart() { XMotor->restartMotor(); YMotor->restartMotor(); ZMotor->restartMotor(); }
    double getMotorsCircumference() { return XMotor->getMotorCircumference(); }
};