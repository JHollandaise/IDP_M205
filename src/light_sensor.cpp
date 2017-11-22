#include <robot_link.h>
#include <robot_instr.h>
#include "light_sensor.h"
#include "global.h"

// Light sensor definitions

LightSensor::LightSensor(const robot_link& RLINK, const request_instruction& READ_NUMBER, const bool& STATUS):
Sensor(RLINK, READ_NUMBER, STATUS)
{}

const int LightSensor::GetOutput() 
{   // Reads the sensor output through a robot_link request
    if (rlink.request(READ_PORT) < LIGHT_SENSOR_THRESHOLD) return true;
    else return false;
} 

