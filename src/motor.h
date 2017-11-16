#ifndef MOTOR_H
#define MOTOR_H

#include <robot_link.h>
#include "ErrorLog.h"

// Useful constants
#define MAX_MOTOR_SPEED 127
#define DEFAULT_MOTOR_SPEED 50

// Motor class declaration

class Motor
{
 public:
    Motor(const robot_link rlink, const int& motor_number, const int& motor_go_number);

    void Rotate(bool direction) const;
    void Rotate(const unsigned int &speed, bool direction) const;

private:
    int motorNumber;
    int motorGo;
    const robot_link rlink;

    ErrorLog& errorLog;

};

#endif
