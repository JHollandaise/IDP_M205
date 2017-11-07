#ifndef MOTOR_H
#define MOTOR_H

#include <robot_link.h>
#include "ErrorLog.h"

// Useful constants
#define MAX_MOTOR_SPEED 127


// Motor class declaration

class Motor
{
 public:
    Motor(const robot_link rlink, const int& motor_number, const int& motor_go_number);

    int Rotate(bool direction) const;
    int Rotate(const unsigned int &speed, bool direction) const;

private:
    unsigned int m_DefaultSpeed;
    int m_MotorNumber;
    int m_MotorGo;
    const robot_link m_Rlink;

    ErrorLog& errorLog;


};

#endif
