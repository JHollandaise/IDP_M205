#ifndef GLOBAL_H
#define GLOBAL_H

// Global header file

// Useful constant
#define PI 3.1415

// Wheel parameters
#define WHEEL_SEPARATION 0.0
#define WHEEL_DIAMETER 0.0

// Default values
#define DEFAULT_ROBOT_TURN_ANGLE 1.0
#define DEFAULT_MOTOR_SPEED 50
#define MAX_MOTOR_SPEED 127
#define LIGHT_SENSOR_THRESHOLD 127

// Sensor addresses
#define READ_LEFT_LIGHT_SENSOR READ_PORT_0
#define READ_CENTRE_LIGHT_SENSOR READ_PORT_1
#define READ_RIGHT_LIGHT_SENSOR READ_PORT_2

// Constants used in conversion
#define SPEED_TO_RPM 0.0
#define RPM_TO_RADS 0.10471975512

// Custom type definitions
typedef unsigned int uint;
typedef unsigned float ufloat;

#endif
