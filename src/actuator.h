#ifndef ACTUATOR_H
#define ACTUATOR_H

#include <robot_instr.h>
#include <robot_link.h>
#include "global.h"

// Actuator class declaration
// @TODO: figure out how to operate actuator and implement functionality

class Actuator
{
 public:

    Actuator(robot_link& RLINK, const command_instruction& PORT_NUMBER, const int& PIN_NUMBER);

    explicit Actuator(robot_link& RLINK);

    void PistonDown();
    void PistonUp();

private:
    robot_link rlink;
    command_instruction PORT;
    int PIN;

};

#endif
