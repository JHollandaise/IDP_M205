#include <robot_link.h>
#include <robot_instr.h>
#include "sensor_base.h"
#include "global.h"

<<<<<<< HEAD
Sensor::Sensor(const robot_link& rlink, const request_instruction& READ_NUMBER, const request_instruction& WRITE_NUMBER, const bool& STATUS):
rlink(RLINK), READ_PORT(READ_NUMBER), WRITE_PORT(WRITE_NUMBER), sensorOn(STATUS)
{}
=======
>>>>>>> master

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

