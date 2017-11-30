#include <iostream>
#include <robot_instr.h>
#include <robot_link.h>
#include <ctime>
#include <cstdlib>
#include <stopwatch.h>

#include "motor.h"
#include "robot.h"
#include "actuator.h"
#include "led.h"
#include "global.h"



// Robot member functions

Robot::Robot(robot_link& RLINK):
rlink(RLINK), motorLeft(Motor(rlink, MOTOR_1, MOTOR_1_GO)), motorRight(Motor(rlink, MOTOR_2, MOTOR_2_GO)), motorChassis(rlink, MOTOR_3, MOTOR_3_GO), actuatorTop(rlink, WRITE_PORT_5, READ_PORT_5, 32), actuatorBottom(rlink, WRITE_PORT_5, READ_PORT_5, 64), LSensorLeft(LightSensor(rlink, READ_LEFT_LIGHT_SENSOR, 1)), LSensorCentre(LightSensor(rlink, READ_CENTRE_LIGHT_SENSOR, 2)), LSensorRight(LightSensor(rlink, READ_RIGHT_LIGHT_SENSOR, 4)), DSensor(DistanceSensor(rlink, READ_DISTANCE_SENSOR)), LED1(LED(rlink, LED_1_PORT)), LED2(LED(rlink, LED_2_PORT)), LED3(LED(rlink, LED_3_PORT))
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
    
    mSpeed = DEFAULT_MOTOR_SPEED;
    l_speed = mSpeed;
    r_speed = mSpeed;
}

void Robot::MoveForward(const uint& speed, const float& time)
{   // Move the robot forward at the given speed for the given amount of time (or indefinitely if 'time' is 0.0)
    motorLeft.Rotate(speed, motorLeftDir);
    motorRight.Rotate(speed, motorRightDir);

	mSpeed = speed;

    if (time > 0.0)
    {
        wait(time);
        StopMoving();
    }
}

void Robot::MoveBackward(const uint& speed, const float& time)
{   // Move the robot backward at the given speed for the given amount of time (or indefinitely if 'time' is 0.0)
    motorLeft.Rotate(speed, !motorLeftDir);
    motorRight.Rotate(speed, !motorRightDir);

	mSpeed = speed;

    if (time > 0.0)
    {
        wait(time);
        StopMoving();
    }
}

void Robot::StopMoving()
{   // Stops the front motors
    motorLeft.Rotate(0, motorLeftDir);
    motorRight.Rotate(0, motorRightDir);
    
    mSpeed = 0;
}

void Robot::MoveDist(const float& distance, const bool& reverse)
{   // Move the robot forward by the specified distance (in m)
    // @TODO check how loading affects RPM
    uint speed = DEFAULT_MOTOR_SPEED;

    const float time = distance / ((WHEEL_DIAMETER/2) * (speed * SPEED_TO_RPM * RPM_TO_RAD_PER_S));
	std::cout << time << std::endl;

    if (reverse) MoveBackward(speed, time);
    else MoveForward(speed, time);
}

void Robot::TurnDegrees(const float& angle, const bool& both_wheels)
{   // Turns the robot **clockwise** through the specified angle
    int speed_left = 0;
    int speed_right = 0;
    float velocity = 0;

    // Express angle in radians and use the wheel separation as the radius of curvature to determine the arc length of the curve taken
    const float arc_length = abs(angle)* DEG_TO_RAD * WHEEL_SEPARATION;

    if (angle > 0)
    {   // Drive the left wheel faster than the right for an amount of time
        speed_left = MAX_MOTOR_SPEED;
        velocity = (WHEEL_DIAMETER/2) * ((speed_left + speed_right) * SPEED_TO_RPM * RPM_TO_RAD_PER_S);
        if (both_wheels) speed_right = MAX_MOTOR_SPEED + 128; velocity *= 2;

    } else if (angle < 0) {
        // Drive the right wheel faster than the left for an amount of time
        speed_right = MAX_MOTOR_SPEED;
        velocity = (WHEEL_DIAMETER/2) * (speed_right * SPEED_TO_RPM * RPM_TO_RAD_PER_S);
        if (both_wheels) speed_left = MAX_MOTOR_SPEED + 128; velocity *= 2;
    }         

    const float time = arc_length/velocity;

	std::cout << time << std::endl;
	std::cout << speed_left << " " << speed_right << std::endl;

    // Make the turn
    motorLeft.Rotate(speed_left, motorLeftDir);
    motorRight.Rotate(speed_right, motorRightDir);

    wait(time);

    // Turn finished - drive motors at the same speed again
    MoveForward(mSpeed);
}

void Robot::SmoothTurn(const bool& clockwise)
{	// Performs a smooth turn by introducing a differential speed between the robot's wheels
	if (clockwise) { l_speed += DEFAULT_SMOOTH_ANGLE; r_speed -= DEFAULT_SMOOTH_ANGLE; }
	else { l_speed -= DEFAULT_SMOOTH_ANGLE; r_speed += DEFAULT_SMOOTH_ANGLE; }
	
	motorLeft.Rotate(l_speed, motorLeftDir);
	motorRight.Rotate(r_speed, motorRightDir);
}

const int Robot::FollowLine(const float& time)
{   // Line-following algorithm using straddling extreme sensors and a central sensor on the line - sensors are off if they are on the line
    bool left_on;     // normally true
    bool centre_on;    // normally false
    bool right_on;   // normally true

    bool box_nearby;

    stopwatch follow_timer;

	mSpeed = 100;
	l_speed = mSpeed;
	r_speed = mSpeed;

	MoveForward(mSpeed, 0.0);

    if (time) follow_timer.start();
    while (time == 0.0 || follow_timer.read() < time)
    {	
        left_on = LSensorLeft.Output();
        centre_on = LSensorCentre.Output();
        right_on = LSensorRight.Output();

        //box_nearby = DSensor.ObjectNearby();

		box_nearby = false;

        if (box_nearby)
        {   // The robot is near a box - a decision has to be made here
            return 1;
        } else if (left_on && !centre_on && right_on) { 
			// Continue path 
			l_speed = mSpeed; 
			r_speed = mSpeed;
			
			MoveForward(mSpeed, 0.0);	
		}
        // Turn left
        else if (!left_on && right_on) SmoothTurn(false);
        // Turn right
        else if (left_on && !right_on) SmoothTurn(true);
        else if (!left_on && !right_on)
        {   // The robot has hit a junction - a decision has to be made here
            return 0;
        } else {   
            // The robot has lost the line completely - log this
            // @TODO add error log entry here
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

int Robot::JunctionAction(Robot::direction turn_dir, Robot::junction_type junction_t)
{
    if(junction_t == dropoff)
    {
        if(turn_dir == LEFT)
        {
            MoveDist(0.23);
            TurnDegrees(-76,true);
            FindLine(false);
            return 0;
        }

        if(turn_dir == RIGHT)
        {
            MoveDist(0.22);
            TurnDegrees(80,true);
            FindLine(true);
            return 0;
        }

        if(turn_dir == STRAIGHT)
        {
            MoveDist(0.01);
            return 0;
        }
    }

    if(junction_t == start)
    {

    }

    if(junction_t == standard)
    {

    }


    return 1;
}

const int Robot::TurntableAction(Robot::direction direction) {
    return 0;
}

const int Robot::CheckForTurntable() {
    return 0;
}

void Robot::ChassisMidPos() {
    if(chassis_pos==2)
    {
        while(!LSensorCentre.Output())
        {
            motorChassis.Rotate(127+128);
        }
    }

    if(chassis_pos==0)
    {
        while(!LSensorCentre.Output())
        {
            motorChassis.Rotate(127);
        }
    }
    motorChassis.Rotate(0);
    chassis_pos=1;
}

void Robot::ChassisTopPos()
{
    if(chassis_pos==0)
    {
        while(!LSensorCentre.Output())
        {
            motorChassis.Rotate(127);
        }
        wait(0.1);
    }
    if(chassis_pos==1||chassis_pos==0)
    {
        while(LSensorCentre.Output())
        {
            motorChassis.Rotate(127);
        }
    }

    wait(2);
    motorChassis.Rotate(0);
    chassis_pos=2;
}

void Robot::ChassisBottomPos()
{

    if(chassis_pos==2)
    {
        while(!LSensorCentre.Output())
        {
            motorChassis.Rotate(127+128);
        }
        wait(0.1);
    }


    if (chassis_pos==1||chassis_pos==2)
    {
        while(LSensorCentre.Output())
        {
            motorChassis.Rotate(127+128);
        }
        motorChassis.Rotate(0);
    }

    chassis_pos=0;

}

void Robot::PickUpBoxes()
{   // Pick up a box by pressurising the actuators and raising the chassis
    ChassisBottomPos();
    actuatorTop.PistonUp();
    actuatorBottom.PistonUp();

    wait(0.5);
    ChassisMidPos();
}

void Robot::DropBoxes(const bool& top_box)
{   // Drop a box by lowering the chassis and depressurising the actuators
    ChassisBottomPos();
    actuatorBottom.PistonDown();
    if (top_box) actuatorTop.PistonDown();
    ChassisMidPos();
}

Robot::box_type Robot::IdentifyBox()
{   // Identify the box type by passing a current through the box circuitry and matching the response time to known circuit reponse times. Light the correct LEDs to show the box type

    return open;


    int val = rlink.request(READ_PORT_4);

	// Flush signals
	rlink.command(WRITE_PORT_4, 191 & val);
	wait(0.1);
	
    // Set pin 7 (the pin connected to the box)
    rlink.command(WRITE_PORT_4, 64 | val);
	wait(5);
	rlink.command(WRITE_PORT_4, 191 & val);
	
	stopwatch watch;
    watch.start();

    // Measure the time taken for the response to get to the correct level
    while (rlink.request(READ_PORT_4) & 32)
    {}

    int time = watch.stop();
	std::cout << time << std::endl;

    box_type box;

    // Identify the circuit
    if (time > OPEN_TC - DETECTION_MARGIN && time < OPEN_TC + DETECTION_MARGIN) box = open;
    else if (time > SHORT_CIRC_TC - DETECTION_MARGIN && time < SHORT_CIRC_TC + DETECTION_MARGIN) box = short_circ;
    else if (time > CIRC_1_TC - DETECTION_MARGIN && time < CIRC_1_TC + DETECTION_MARGIN) box = res1;
    else if (time > CIRC_2_TC - DETECTION_MARGIN && time < CIRC_2_TC + DETECTION_MARGIN) box = res2;
    else if (time > CIRC_3_TC - DETECTION_MARGIN && time < CIRC_3_TC + DETECTION_MARGIN) box = res3;
    else std::cout << "Box identification failed" << std::endl; return error;

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

void Robot::FindLine(const bool& clockwise) {
    while(!LSensorCentre.Output())
    {
        if (clockwise) TurnDegrees(DEFAULT_ROBOT_TURN_ANGLE, true);
        else TurnDegrees(-DEFAULT_ROBOT_TURN_ANGLE, true);
    }
}


