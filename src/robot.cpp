#include <robot_instr.h>
#include <robot_link.h>
#include <ctime>

#include "motor.h"
#include "robot.h"
#include "global.h"


Robot::Robot(const robot_link& rlink):
    rlink(rlink)
{
    // Initialise the front motors
    motorLeft = Motor(rlink, MOTOR_1, MOTOR_1_GO);
    motorRight = Motor(rlink, MOTOR_2, MOTOR_2_GO);
    
    // Set motor directions - random for now
    motorLeftDir = true;
    motorRightDir = false;

    // Initialise light sensors
    LSensorLeft = LightSensor(1);
    LSensorCentre = LightSensor(1);
    LSensorRight = LightSensor(1);
}

void Robot::MoveForward(const uint& speed, const ufloat& time) const
{   // Move the robot forward at the given speed for the given amount of time (or indefinitely if 'time' is 0.0)

    motorLeft.Rotate(speed, motorLeftDir);
    motorRight.Rotate(speed, motorRightDir);

    if (time > 0.0)
    {
        Wait(time);
        StopMoving();
    }
}

void Robot::MoveBackward(const uint& speed, const ufloat& time) const
{   // Move the robot backward at the given speed for the given amount of time (or indefinitely if 'time' is 0.0)
    motorLeft.Rotate(speed, !motorLeftDir);
    motorRight.Rotate(speed, !motorRightDir);

    if (time > 0.0)
    {
        Wait(time);
        StopMoving();
    }
}

void Robot::StopMoving() const
{   // Stops the front motors
    motorLeft.Rotate(0, motorLeftDir);
    motorRight.Rotate(0, motorRightDir);
}

void Robot::MoveDist(const float& distance, const bool& reverse) const
{   // Move the robot forward by the specified distance
    // @TODO check how loading affects RPM
    uint speed = mSpeed

    const ufloat time = distance / ((WHEEL_DIAMETER/2) * (speed * SPEED_TO_RPM * RPM_TO_RADS))

    if (reverse) MoveBackward(time, speed);
    else MoveForward(time, speed);
}

void Robot::TurnDegrees(const float& angle) const
{   // Turns the robot **clockwise** through the specified angle
            
}

const int Robot::FollowLine(const uint& strategy, const bool& stop) const
{   // Line-following algorithm using straddling extreme sensors and a central sensor on the line - sensors are off if they are on the line
    const bool left_on = LSensorLeft.GetOutput();     // normally true
    const bool centre_on = LSensorCentre.GetOutput();     // normally false
    const bool right_on = LSensorRight.GetOutput();   // normally true

    while (!stop)
    {
        // Continue current path
        if (left_on && !centre_on && right_on) {}
        // Turn left
        else if (!left_on && right_on) TurnDegrees(-DEFAULT_ROBOT_TURN_ANGLE);
        // Turn right
        else if (left_on && !right_on) TurnDegrees(DEFAULT_ROBOT_TURN_ANGLE);
        else if (!left_on && !right_on)
        {   // The robot has hit a junction - a decision has to be made here
            switch(strategy)
            {
            case 0:
                // Continue current path
                return 0;
                break;

            case 1:
                // Turn left
                TurnDegrees(-DEFAULT_ROBOT_TURN_ANGLE)
                return 1;
                break;

            case 2:
                // Turn right
                TurnDegrees(DEFAULT_ROBOT_TURN_ANGLE)
                return 2;
                break;

            case 3:
                // Reverse by a certain distance
                MoveDist(-1.0);
                return 4;
                break;

            default:
                // Log this as an error - the above list is exhaustive
                // @TODO add error log entry here
                return -1;
                break;
            }
        }

        else
        {   // The robot has lost the line completely - log this
            // @TODO add error log entry here
            return 5;
        }
    }

    // The algorithm was overriden manually
    return 6;
}

void Robot::StopAtStart() {

}


// Robot friend functions
void Wait(const ufloat& time)
{   // Wait by the specified amount of time
    clock_t t1;

    // Wait until the time has elapsed
    while (float(clock() - t1)/CLOCKS_PER_SEC < time) {};
}
