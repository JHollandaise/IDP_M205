#include <robot_instr.h>
#include <robot_link.h>

#include "motor.h"
#include "robot.h"


Robot::Robot(robot_link rlink, float wheelSeparation):
    rlink(rlink), wheelSeparation(wheelSeparation)
{}

void Robot::MoveForward(unsigned float time, unsigned int speed) const
{
    motorLeft.Rotate(speed, motorLeftDir);
    motorRight.Rotate(speed, motorRightDir);
}

void Robot::MoveBackward(unsigned float time, unsigned int speed) const {
    motorLeft.Rotate(speed, !motorLeftDir);
    motorRight.Rotate(speed, !motorRightDir);
}
