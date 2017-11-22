#ifndef MOTOR_H
#define MOTOR_H

#include <robot_instr.h>
#include <robot_link.h>
#include "global.h"

// Motor class declaration

class Motor
{
 public:
    Motor(robot_link& RLINK, const request_instruction& motor_number, const command_instruction& motor_go_number);

    void Rotate(bool direction);
    void Rotate(const unsigned int &speed, bool direction);

private:
    request_instruction motorNumber;
    command_instruction motorGo;
    robot_link rlink;

};

#endif
