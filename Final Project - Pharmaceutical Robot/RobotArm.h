//
//  RobotArm.h
//  FinalLab
//
//  Created by Andrea Borghi on 6/21/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

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
    void stop() { motor->stop(); }
};

