#ifndef LIGHT_SENSOR.h
#define LIGHT_SENSOR.h

#include "sensor_base.h"

class LightSensor : public Sensor
{
public:
    LightSensor(const bool& STATUS = 1);
   
    const bool GetOutput() const;
    const uint GetSensorCount() const;

private:
    static uint sensorCount;
} 

#endif
