#ifndef DISTANCE_SENSOR_H
#define DISTANCE_SENSOR_H

#include "sensor_base.h"


class DistanceSensor : public Sensor
{
 public:
    DistanceSensor(const robot_link& RLINK, const request_instruction& READ_NUMBER, const bool& STATUS = 1);
    
    const int GetOutput();

    const bool ObjectNearby(const int& THRESHOLD = DISTANCE_SENSOR_THRESHOLD);
};


#endif
