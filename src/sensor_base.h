#ifndef SENSOR_BASE_H
#define SENSOR_BASE_H

// Sensor abstract base class

class Sensor
{
public:
    Sensor(const robot_link& RLINK, const int& READ_NUMBER, const int& WRITE_NUMBER, const bool& STATUS = 1);

    void SetStatus(const bool& STATUS);
    void Toggle();

    virtual const int GetOutput() const = 0;
    virtual void WriteInput() const = 0;
    const bool GetStatus() const;

protected:
    robot_link rlink;
    const int& READ_PORT;
    const int& WRITE_PORT;
    bool sensorOn;
};

#endif
