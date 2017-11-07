#include <robot_link.h>
#include "motor.h"

// Class constructor
Motor::Motor(const robot_link rlink, const int& motor_number, const int& motor_go_number):
    m_Rlink(rlink), m_DefaultSpeed(50), m_MotorNumber(motor_number), m_MotorGo(motor_go_number) 
{}

void Motor::MoveForward() const
{   // Drives motor forward at data member 'm_DefaultSpeed'
    this->MoveForward(m_DefaultSpeed);
}

void Motor::MoveForward(const uint& speed) const
{   // Drives motor forward at 'speed'

    // Ensure that the selected speed does not exceed the maximum permitted
    if (speed > MOTOR_MAX_SPEED) { speed = MOTOR_MAX_SPEED; }

    this->m_Rlink.command(this->m_MotorGoNumber, this->speed);
}    

void Motor::MoveBackward() const
{   // Drives motor backwards at data member 'm_DefaultSpeed'
    this->MoveBacward(m_DefaultSpeed + MOTOR_MAX_SPEED);
}

void Motor::MoveBackward(const uint& speed) const
{   // Move motor backwards at 'speed'
    uint reverse_speed = speed + MOTOR_MAX_SPEED

    // Ensure that the speed does not exceed the maximum permitted value
    if (reverse_speed > MOTOR_MAX_REVERSE_SPEED) { reverse_speed = MOTOR_MAX_REVERSE_SPEED; }
    this->MoveForward(reverse_speed);
}

