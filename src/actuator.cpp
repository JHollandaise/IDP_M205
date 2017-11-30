#include <robot_instr.h>
#include <robot_link.h>
#include "actuator.h"

// Class constructor
Actuator::Actuator(robot_link& RLINK, const command_instruction& WRITE_NUMBER, const request_instruction& READ_NUMBER, const int& PIN_NUMBER):
    rlink(RLINK), WRITE_PORT(WRITE_NUMBER), READ_PORT(READ_NUMBER), PIN(PIN_NUMBER)
{}

void Actuator::PistonDown()
{   // Release pneumatic pressure in the actuator
    rlink.command(WRITE_PORT, (255 - PIN) & rlink.request(READ_PORT));
}

void Actuator::PistonUp()
{   // Pressurise actuator
    rlink.command(WRITE_PORT, PIN | rlink.request(READ_PORT));
}

