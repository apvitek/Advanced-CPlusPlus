/*
 Purpose:  To use the new C++ threading techniques
 
 Problem:
 
 *	Design a robotic "arm".  You may use my robotic code from lab1 as a starting point.  These robots have the ability to rotate 0 - 360 degrees in 1 degree increments.  A complete 360 rotation moves the robot a linear 100 mm and these robots only respond to start and stop commands.
 
 *	This robotic arm is composed of 3 robots.
 The first moves on the X axis:  Think of a "rotation" on this arm as moving from point A to point B in a horizontal line.
 The second on the Y axis:  Think of this as a "rotation" on this arm as moving from point A to point B on a vertical line.
 The third on the Z axis:  Think of this as a "rotation" around either the X or Y axis's.
 A positive value rotates clockwise, and a negative value rotates counter-clockwise.
 
 *	The controller issues start and stop commands.  It knows the distance (translate to rotations) needed for the robot to travel in X, Y, and Z coordinates, and issues the appropriate commands taking acceleration and deceleration into consideration.  Each of the 3 robot components are launched on separate threads.  The robots report their 'status' (number of complete rotations including fractional rotations) at either specified or unscheduled intervals.  The controller gets the status from the robot threads in order to issue appropriate start and stop commands.
 
 *	The controller must take control of a thread at exact time (a short amount of milliseconds) for the acceleration factors to be effective, as being by more than 1 degree can be too much.  Timing is everything.  You can makeup your own start/stop scheme.  For example, at slow speed, full acceleration and deceleration stops in 1 rotation; medim 2 rotations; high 3 rotations.  To complete simultaneous movement, robots will need to 'rotate' at different speeds.  For example:  If robot X must move 270 degrees and robot Y must only move 90 degrees, robot X needs to rotate faster than Y.
 
 *	If the robots don't use threading operations to control their movement, the X robot would start and complete, before the Y robot started and completed, followed by the Z robot.  This behavior is inefficient and looks amateurish.  Ideally, each robot should complete their movements simultaneously, though hitting the exact time can be difficult because of asynchronous operations.
 
 The robot runs in a Pharmaceutical container with dimensions of 3 meters long and 2 meters high.  There are pill dispensers on either side of the robot, meaning the Z robot will typically have to rotate at most 180 degrees.
 
 The base core of this assignment is to use C++ threading techniques.  However, another purpose is to demonstrate your mastery of C++ by using other advanced techniques learned in this course.  Use STL/TR1 code as much as possible instead of "rolling your own" - don't use the data structure code you've been writing in CIS22C.
*/

#include <iostream>
#include "RobotController.h"

using namespace std;

int main(int argc, const char * argv[])
{
    RobotController * controller = new RobotController();

    controller->turnOn();
    
    delete controller;
    
    return 0;
}