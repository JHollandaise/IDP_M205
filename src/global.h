#ifndef GLOBAL_H
#define GLOBAL_H

// Global header file containing useful global constants

// Useful constant
#define PI 3.1415


// Wheel parameters
#define WHEEL_SEPARATION 0.0
#define WHEEL_DIAMETER 0.0


// Default values - @TODO: find empirically
#define DEFAULT_ROBOT_TURN_ANGLE 1.0
#define DEFAULT_MOTOR_SPEED 50
#define MAX_MOTOR_SPEED 127

#define LIGHT_SENSOR_THRESHOLD 127
#define DISTANCE_SENSOR_THRESHOLD 100
#define DISTANCE_SENSOR_MARGIN 20
#define DETECTION_MARGIN 2 

#define CHASSIS_LIFT_ANGLE 90   // @TODO: find empirically 


// Sensor addresses
#define READ_LEFT_LIGHT_SENSOR READ_PORT_5
#define READ_CENTRE_LIGHT_SENSOR READ_PORT_5
#define READ_RIGHT_LIGHT_SENSOR READ_PORT_5

#define READ_DISTANCE_SENSOR ADC4

#define LED_1_PORT WRITE_PORT_0
#define LED_2_PORT WRITE_PORT_0
#define LED_3_PORT WRITE_PORT_0

#define ROBOT_NUM 8


// Time constants (in ms) for box detection
#define OPEN_TC 0.0
#define SHORT_CIRC_TC 0.0
#define CIRC_1_TC 0.0
#define CIRC_2_TC 0.0
#define CIRC_3_TC 0.0


// Constants used in conversion
#define SPEED_TO_RPM 0.01  // @TODO: find empirically
#define RPM_TO_RAD_PER_S 0.10471975512
#define DEG_TO_RAD 0.01745


// Custom type definitions
typedef unsigned int uint;

void wait(const float&);
robot_link setup_link();

#endif

