#include <robot_link.h>
#include "motor.h"

// Class constructor
Motor::Motor(const robot_link rlink, const int& motor_number, const int& motor_go_number):
    rlink(rlink), motorNumber(motor_number), motorGo(motor_go_number) 
{}

void Motor::Rotate(bool direction) const
{
    // Drives motor forward at the default speed
    Rotate(MOTOR_DEFAULT_SPEED, direction);
}

void Motor::Rotate(const unsigned int &speed, bool direction) const
{
    // Drives motor forward at 'speed'

    // speed magnitude is given between 0-MAX_MOTOR_SPEED

    // the direction variable determines whether the motor will spin in the clockwise or anti-clockwise direction
    // direction true is **clockwise**

    // motor_speed variable is passed to command to microcontroller
    int motor_speed = speed;

    if (motor_speed > MAX_MOTOR_SPEED)
    {
        errorLog.Log(ErrorLog::ErrorType::MOTOR_SPEED);
    } else {

        // checks for direction and if reverse sets 8th bit of motor_speed
        if (!direction) motor_speed += 128;

        rlink.command(motorGo, motor_speed);
    }
}
