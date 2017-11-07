#include <robot_link.h>
#include "motor.h"

// Class constructor
Motor::Motor(const robot_link rlink, const int& motor_number, const int& motor_go_number):
    m_Rlink(rlink), m_DefaultSpeed(50), m_MotorNumber(motor_number), m_MotorGo(motor_go_number) 
{}

int Motor::Rotate(bool direction) const
{
    // Drives motor forward at data member 'm_DefaultSpeed'
    return Rotate(m_DefaultSpeed, direction);
}

int Motor::Rotate(const unsigned int &speed, bool direction) const
{
    // Drives motor forward at 'speed'

    // speed magnitude is given between 0-MAX_MOTOR_SPEED

    // the direction variable determines whether the motor will spin in the clockwise or anti-clockwise direction
    // direction true is **clockwise**

    // Ensure that the selected speed does not exceed the maximum permitted

    // motor_speed variable is passed to command to microcontroller
    int motor_speed = speed;

    if ((speed > MAX_MOTOR_SPEED))
    {
        errorLog.Log(ErrorLog::ErrorType::MOTOR_SPEED);
        return 0;
    }

    // checks for direction and if reverse sets 8th bit of motor_speed
    if (!direction) motor_speed += 128;

    m_Rlink.command(m_MotorGo, motor_speed);
}
