#include <robot_link.h>
#include <robot_instr.h>
#include "light_sensor.h"
#include "global.h"

// Light sensor definitions

LightSensor::LightSensor(const robot_link& RLINK, const request_instruction& READ_NUMBER, int sensor_val, const bool& STATUS):
Sensor(RLINK, READ_NUMBER, STATUS), sensor_val(sensor_val)
{}

const bool LightSensor::Output()
{
	return GetOutput() == 0;
}

const int LightSensor::GetOutput()
{   // Reads the sensor output through a robot_link request
    return rlink.request(READ_PORT_5) & sensor_val;
}

