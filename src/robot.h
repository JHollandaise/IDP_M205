#ifndef ROBOT_H
#define ROBOT_H

#include <robot_instr.h>
#include <robot_link.h>

#include "motor.h"
#include "ErrorLog.h"

class Robot
{
private:
    // Robot link for connecting to the robot
    robot_link rlink;

    // The front motors
    Motor motorLeft;
    Motor motorRight;

    // Determines what direction is "forward" for a given motor
    // True if **clockwise** is forward
    bool motorLeftDir;
    bool motorRightDir;

    // The distance between the wheels in meters
    float wheelSeparation;

    ErrorLog& errorLog;

    void SetMotor(Motor motor);



public:

    Robot(robot_link rlink, float wheelSeparation, Motor motorLeft, Motor motorRight);

    void MoveForward(unsigned float time, unsigned int speed) const;
    void MoveBackward(unsigned float time, unsigned int speed) const;

    void MoveDist(float distance) const;

    void TurnDegrees(float angle) const;
};

#endif