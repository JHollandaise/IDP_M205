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
    explicit Actuator(robot_link& RLINK);
    void PistonDown();
    void PistonUp();

private:
    robot_link rlink;

};

#endif
