#include "sensor_base.h"
#include "global.h"

T

void Sensor::SetStatus(const bool& STATUS)
{   // Turn sensor on or off
    sensorOn = STATUS;
}

void Sensor::Toggle()
{   // Toggle sensor state
    sensorOn = !sensorOn;
}

const bool& Sensor::GetStatus() const
{   // Get current sensor status
    return sensorOn;
}



