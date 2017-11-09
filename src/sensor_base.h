#ifndef SENSOR_BASE.H
#define SENSOR_BASE.H

// Sensor base class

class Sensor
{
public:
    // @TODO finish implementation
    Sensor(const bool& STATUS = 1);

    void SetStatus(const bool& STATUS);
    void Toggle();

    virtual const bool GetOutput() const = 0;
    const bool GetStatus() const;

protected:
    bool sensorOn;
};

#endif
