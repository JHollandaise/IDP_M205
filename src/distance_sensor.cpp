#include <robot_link.h>
#include <robot_instr.h>
#include "distance_sensor.h"
#include "global.h"

// Distance sensor definitions

DistanceSensor::DistanceSensor(const robot_link& RLINK, const request_instruction& READ_NUMBER, const bool& STATUS):
Sensor(RLINK, READ_NUMBER, READ_NUMBER, STATUS)
{}

const int DistanceSensor::GetOutput()
{   // Reads the sensor output through a robot_link request
    return rlink.request(READ_PORT);
} 

void DistanceSensor::WriteInput()
{   /* Do nothing - the distance sensor cannot be written to */ }

const bool DistanceSensor::ObjectNearby(const int& THRESHOLD)
{   // Detects if an object is close to the robot
    return GetOutput() <= THRESHOLD;
}

