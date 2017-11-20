#ifndef DISTANCE_SENSOR_H
#define DISTANCE_SENSOR_H

#include "sensor_base.h"


class DistanceSensor : public Sensor
{
public:
    DistanceSensor(const robot_link& RLINK, const int& READ_NUMBER, const bool& STATUS = 1);
   
    const uint GetOutput() const;
    void WriteInput() const;

    const bool ObjectNearby(const uint& THRESHOLD = DISTANCE_SENSOR_THRESHOLD) const;
}


#endif
