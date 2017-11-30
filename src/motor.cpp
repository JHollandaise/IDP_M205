#include <robot_instr.h>
#include <robot_link.h>
#include "motor.h"
#include "global.h"

// Class constructor
Motor::Motor(robot_link& RLINK, const request_instruction& motor_number, const command_instruction& motor_go_number):
    rlink(RLINK), motorNumber(motor_number), motorGo(motor_go_number) 
{}


void Motor::Rotate(const unsigned int &speed)
{
    // Drives motor forward at 'speed'

    // speed magnitude is given between 0-MAX_MOTOR_SPEED

    // the direction variable determines whether the motor will spin in the clockwise or anti-clockwise direction
    // direction true is **clockwise**

    // motor_speed variable is passed to command to microcontroller
    int motor_speed = speed;

    if (motor_speed > 255)
    {
        // errorLog.Log(ErrorLog::ErrorType::MOTOR_SPEED);
    } else {

        rlink.command(motorGo, motor_speed);
    }
}

void Motor::Rotate(const unsigned int &speed, bool direction)
{
    // Drives motor forward at 'speed'

    // speed magnitude is given between 0-MAX_MOTOR_SPEED

    // the direction variable determines whether the motor will spin in the clockwise or anti-clockwise direction
    // direction true is **clockwise**

    // motor_speed variable is passed to command to microcontroller
    int motor_speed = speed;

    if (motor_speed > MAX_MOTOR_SPEED)
    {
        // errorLog.Log(ErrorLog::ErrorType::MOTOR_SPEED);
    } else {

        // checks for direction and if reverse sets 8th bit of motor_speed
        if (!direction) motor_speed += 128;

        rlink.command(motorGo, motor_speed);
    }
}

void Motor::RotateAngle(const float& angle, const int& speed)
{   // Rotate motor through the specified angle (in degrees) at the given speed
   const float time = (angle * DEG_TO_RAD) / (speed * SPEED_TO_RPM * RPM_TO_RAD_PER_S);     
    
    if (angle > 0)
    {
        Rotate(speed, true);
    } else {
        Rotate(speed, false);
    }

    // Wait for the amount of time required to complete the rotation
    wait(time);

    Rotate(0, true);
}

