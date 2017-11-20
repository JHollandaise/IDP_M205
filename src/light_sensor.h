#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#include "sensor_base.h"

class LightSensor : public Sensor
{
public:
    LightSensor(const robot_link& RLINK, const int& READ_NUMBER, const bool& STATUS = 1);
   
    const bool GetOutput() const;
    void WriteInput() const;
    const uint GetSensorCount() const;

private:
    static uint sensorCount;
} 

#endif
