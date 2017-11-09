#ifndef ROBOT_H
#define ROBOT_H

#include <robot_instr.h>
#include <robot_link.h>

#include "motor.h"
#include "light_sensor.h"
#include "ErrorLog.h"
#include "global.h"


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

    // Speed the robot is currently travelling at
    int mSpeed;

    // The three light senssors
    LightSensor LSensorLeft;
    LightSensor LSensorCentre;
    LightSensor LSensorRight;

    ErrorLog& errorLog;

public:

    Robot(const robot_link& rlink);

    void MoveForward(const uint& speed, const ufloat& time = 0.0) const;
    void MoveBackward(const uint& speed, const ufloat& time = 0.0) const;
    void StopMoving() const;

    void MoveDist(const ufloat& distance, const bool& reverse = false) const;
    void TurnDegrees(const float& angle) const;

    void FollowLine(const uint& strategy = 0) const;
};

#endif
