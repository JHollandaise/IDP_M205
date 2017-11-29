#include <robot_instr.h>
#include <robot_link.h>
#include "actuator.h"

// Class constructor
Actuator::Actuator(robot_link& RLINK, const command_instruction& PORT_NUMBER):
    rlink(RLINK), PORT(PORT_NUMBER)
{}

void Actuator::PistonDown()
{   // Release pneumatic pressure in the actuator
    rlink.command(PORT, 0);
}

void Actuator::PistonUp()
{   // Pressurise actuator
    rlink.command(PORT, 255);
}

