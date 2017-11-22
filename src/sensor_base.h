#ifndef SENSOR_BASE_H
#define SENSOR_BASE_H

#include <robot_instr.h>
#include <robot_link.h>
#include "global.h"

// Sensor abstract base class

class Sensor
{
public:
    void SetStatus(const bool& STATUS);
    void Toggle();

    virtual const int GetOutput() = 0;
    const bool& GetStatus() const;

protected:
    
    Sensor(const robot_link& RLINK, const request_instruction& READ_NUMBER, const bool& STATUS = 1);

    robot_link rlink;
    const request_instruction& READ_PORT;
    bool sensorOn;
};

#endif
