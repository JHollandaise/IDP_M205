#ifndef LIGHT_SENSOR_h
#define LIGHT_SENSOR_h

#include "sensor_base.h"

class LightSensor : public Sensor
{
public:
    LightSensor(const robot_link& RLINK, const int& READ_NUMBER, const bool& STATUS = 1);
   
    const int GetOutput() const;
    const uint GetSensorCount() const;

private:
    static uint sensorCount;
} 

#endif
