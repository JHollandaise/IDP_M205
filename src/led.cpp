#include <robot_instr.h>
#include <robot_link.h>
#include "global.h"
#include "led.h"

// Class constructor
LED::LED(robot_link& RLINK, const command_instruction& PORT_NUMBER):
    rlink(RLINK), WRITE_PORT(PORT_NUMBER), status(OFF)
{}

void LED::TurnOn()
{   // Light the LED continuously
    status = ON;
    rlink.command(WRITE_PORT, 1);
}

void LED::TurnOff()
{   // Turn the LED off
    status = OFF;
    rlink.command(WRITE_PORT, 0);
}

void LED::Toggle()
{   // Toggles the LED
    if (status == ON)
    {
        TurnOff();
    } else {
        TurnOn();
    }
}

LED::STATUS LED::GetStatus() const
{   // Function that tells user whether LED is on or off
    return status;
}

