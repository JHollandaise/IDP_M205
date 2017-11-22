#include <robot_link.h>
#include <robot_instr.h>
#include "sensor_base.h"
#include "global.h"

Sensor::Sensor(const robot_link& RLINK, const request_instruction& READ_NUMBER, const bool& STATUS):
rlink(RLINK), READ_PORT(READ_NUMBER), sensorOn(STATUS)
{}

void Sensor::SetStatus(const bool& STATUS)
{   // Turn sensor on or off
    sensorOn = STATUS;
}

void Sensor::Toggle()
{   // Toggle sensor state
    sensorOn = !sensorOn;
}

const bool& Sensor::GetStatus() const
{   // Get current sensor status
    return sensorOn;
}

