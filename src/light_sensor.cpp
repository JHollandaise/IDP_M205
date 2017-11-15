#include "light_sensor.h"
#include "global.h"

// Light sensor definitions

LightSensor::LightSensor(const bool& STATUS)
{
    Sensor(STATUS);
    sensorCount += 1;
}

const bool GetOutput() const
{
    
}

const uint GetSensorCount() const
{   // Returns the number of sensor of this type
    return sensorCount;
}

