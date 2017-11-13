#ifndef LIGHT_SENSOR_h
#define LIGHT_SENSOR_h

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
