#include <iostream>
#include <robot_instr.h>
#include <robot_link.h>
#include <ctime>
#include <cstdlib>

#include "motor.h"
#include "robot.h"
#include "actuator.h"
#include "led.h"
#include "global.h"




// Robot member functions

Robot::Robot(robot_link& RLINK):
rlink(RLINK), motorLeft(Motor(rlink, MOTOR_1, MOTOR_1_GO)), motorRight(Motor(rlink, MOTOR_2, MOTOR_2_GO)), motorChassis(rlink, MOTOR_3, MOTOR_3_GO), actuator(Actuator(rlink)), LSensorLeft(LightSensor(rlink, READ_LEFT_LIGHT_SENSOR, 1)), LSensorCentre(LightSensor(rlink, READ_CENTRE_LIGHT_SENSOR, 2)), LSensorRight(LightSensor(rlink, READ_RIGHT_LIGHT_SENSOR, 4)), DSensor(DistanceSensor(rlink, READ_DISTANCE_SENSOR)), LED1(LED(rlink, LED_1_PORT)), LED2(LED(rlink, LED_2_PORT)), LED3(LED(rlink, LED_3_PORT))
{   
	/* 
    // Initialise the robot link
    #ifdef __arm__
        // Set up link on the ARM microprocessor
        if (!rlink.initialise ()) {
            rlink.print_errs("  ");
        } else {
			std::cout << "Connection successful" << std::endl;
		}
    #else
        // Set up link from the computer
        if (!rlink.initialise (ROBOT_NUM)) {
            rlink.print_errs("  ");
        } else {
			std::cout << "Connection established" << std::endl;
		}
    #endif
    */

    // Set motor directions - random for now
    motorLeftDir = true;
    motorRightDir = false;
    motorChassisDir = true;
}

void Robot::MoveForward(const uint& speed, const float& time)
{   // Move the robot forward at the given speed for the given amount of time (or indefinitely if 'time' is 0.0)

    motorLeft.Rotate(speed, motorLeftDir);
    motorRight.Rotate(speed, motorRightDir);

    if (time > 0.0)
    {
        Wait(time);
        StopMoving();
    }
}

void Robot::MoveBackward(const uint& speed, const float& time)
{   // Move the robot backward at the given speed for the given amount of time (or indefinitely if 'time' is 0.0)
    motorLeft.Rotate(speed, !motorLeftDir);
    motorRight.Rotate(speed, !motorRightDir);

    if (time > 0.0)
    {
        Wait(time);
        StopMoving();
    }
}

void Robot::StopMoving()
{   // Stops the front motors
    motorLeft.Rotate(0, motorLeftDir);
    motorRight.Rotate(0, motorRightDir);
}

void Robot::MoveDist(const float& distance, const bool& reverse)
{   // Move the robot forward by the specified distance (in m)
    // @TODO check how loading affects RPM
    uint speed = mSpeed;

    const float time = distance / ((WHEEL_DIAMETER/2) * (speed * SPEED_TO_RPM * RPM_TO_RAD_PER_S));

    if (reverse) MoveBackward(time, speed);
    else MoveForward(time, speed);
}

void Robot::TurnDegrees(const float& angle)
{   // Turns the robot **clockwise** through the specified angle
    int speed_left = 0;
    int speed_right = 0;
    float velocity = 0;

    // Express angle in radians and use the wheel separation as the radius of curvature to determine the arc length of the curve taken
    const uint arc_length = PI*abs(angle)/180 * WHEEL_SEPARATION;

    if (angle > 0)
    {   // Drive the left wheel faster than the right for an amount of time
        speed_left = MAX_MOTOR_SPEED;
        velocity = (WHEEL_DIAMETER/2) * (speed_left * SPEED_TO_RPM * RPM_TO_RAD_PER_S);

    } else if (angle < 0) {
        // Drive the right wheel faster than the left for an amount of time
        speed_right = MAX_MOTOR_SPEED;
        velocity = (WHEEL_DIAMETER/2) * (speed_right * SPEED_TO_RPM * RPM_TO_RAD_PER_S);
    }         

    const float time = arc_length/velocity;

    // Make the turn
    motorLeft.Rotate(speed_left, motorLeftDir);
    motorRight.Rotate(speed_right, motorRightDir);

    Wait(time);

    // Turn finished - drive motors at the same speed again
    MoveForward(mSpeed);
}

const int Robot::FollowLine()
{   // Line-following algorithm using straddling extreme sensors and a central sensor on the line - sensors are off if they are on the line
    int left_on;     // normally true
    int centre_on;    // normally false
    int right_on;   // normally true

    bool box_nearby;

    while (true)
    {
        left_on = LSensorLeft.GetOutput();
        centre_on = LSensorCentre.GetOutput(); 
        right_on = LSensorRight.GetOutput();

        box_nearby = DSensor.GetOutput();

        if (box_nearby)
        {   // The robot is near a box - a decision has to be made here
            return 0;
        } else if (left_on && !centre_on && right_on) {} // Continue path 
        // Turn left
        else if (!left_on && right_on) TurnDegrees(-DEFAULT_ROBOT_TURN_ANGLE);
        // Turn right
        else if (left_on && !right_on) TurnDegrees(DEFAULT_ROBOT_TURN_ANGLE);
        else if (!left_on && !right_on)
        {   // The robot has hit a junction - a decision has to be made here
            return 0;
        } else {   
            // The robot has lost the line completely - log this
            // @TODO add error log entry here
            return -1;
        }
    }

    // Code should never reach this line
    return -2;
}

void Robot::StopAtStart() 
{

}

int Robot::StartJunctionAction(Robot::direction) 
{
    return 0;
}

int Robot::JunctionAction(Robot::direction)
{

    return 0;
}

const int Robot::TurntableAction(Robot::direction direction) {
    return 0;
}

const int Robot::CheckForTurntable() {
    return 0;
}

void Robot::PickUpBoxes()
{   // Pick up a box by pressurising the actuators and raising the chassis
      actuator.PistonUp();
      motorChassis.RotateAngle(CHASSIS_LIFT_ANGLE);
}

void Robot::DropBoxes(bool bottom_box)
{   // Drop a box by lowering the chassis and depressurising the actuators
    motorChassis.RotateAngle(-CHASSIS_LIFT_ANGLE);
    actuator.PistonDown();
}

Robot::box_type Robot::IdentifyBox()
{   // Identify the box type by passing a current through the box circuitry and matching the voltage signature to pre-defined cases. Light the correct LEDs to show the box type

    // @TODO: talk to electrical about the identification details
    box_type box;

    switch(box)
    {   // Light LEDs in different patterns (depending on box type)
    case open:
        LED1.TurnOn();
        LED2.TurnOff();
        LED3.TurnOn();
        break;

    case short_circ:
        LED1.TurnOn();
        LED2.TurnOn();
        LED3.TurnOn();
        break;

    case res1:
        LED1.TurnOn();
        LED2.TurnOff();
        LED3.TurnOff();
        break;

    case res2:
        LED1.TurnOff();
        LED2.TurnOn();
        LED3.TurnOff();
        break;

    case res3:
        LED1.TurnOn();
        LED2.TurnOff();
        LED3.TurnOn();
        break;

    default:
        //@TODO Error log here
        break;
    }

    return box;
}