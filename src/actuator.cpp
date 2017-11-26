#include <robot_instr.h>
#include <robot_link.h>
#include "motor.h"
#include "global.h"

// Class constructor
Actuator::Actuator(robot_link& RLINK):
    rlink(RLINK)
{}

void Actuator::PistonDown()
{   // Release pneumatic pressure in the actuator
    rlink.command();
}

void Actuator::PistonUp()
{   // Pressurise actuator
    rlink.command();
}

