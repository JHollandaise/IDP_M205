#ifndef MOTOR_H
#define MOTOR_H

#include <robot_instr.h>
#include <robot_link.h>
#include "global.h"

// Motor class declaration

class Motor
{
 public:
    friend void Wait(const float& time);

    Motor(robot_link& RLINK, const request_instruction& motor_number, const command_instruction& motor_go_number);
    
    void Rotate(bool direction);
    void Rotate(const unsigned int &speed, bool direction);
    void RotateAngle(const float& angle, const int& speed = MAX_MOTOR_SPEED);

private:
    request_instruction motorNumber;
    command_instruction motorGo;
    robot_link rlink;

};

#endif
