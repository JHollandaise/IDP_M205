#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#include "sensor_base.h"

class LightSensor : public Sensor
{
public:
    LightSensor(const robot_link& RLINK, const request_instruction& READ_NUMBER,  int sensor_val, const bool& STATUS = 1);
   
    const int sensor_val;

	const bool Output();
    const int GetOutput();
}; 

#endif
