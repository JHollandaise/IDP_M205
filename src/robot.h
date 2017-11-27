#ifndef ROBOT_H
#define ROBOT_H

#include <robot_instr.h>
#include <robot_link.h>

#include "motor.h"
#include "light_sensor.h"
#include "distance_sensor.h"
#include "actuator.h"
#include "global.h"
<<<<<<< HEAD
=======
#include "MotionControl.h"

>>>>>>> development

class Robot
{
private:
    // Robot link for connecting to the robot
    robot_link rlink;

    // The front motors
    Motor motorLeft;
    Motor motorRight;

    // The motor used to lift the chassis
    Motor motorChassis;

    // The actuator used to clamp boxes
    Actuator actuator;

    // Determines what direction is "forward" for a given motor
    // True if **clockwise** is forward
    bool motorLeftDir;
    bool motorRightDir;
    bool motorChassisDir;

    // Speed the robot is currently travelling at
    int mSpeed;

    // The three light sensors
    LightSensor LSensorLeft;
    LightSensor LSensorCentre;
    LightSensor LSensorRight;

    // The distance sensor
    DistanceSensor DSensor;
    
    // The LEDs used for box detection
    LED LED1;
    LED LED2;
    LED LED3;

public:


    enum direction {
        LEFT,
        RIGHT,
        STRAIGHT
    };

    enum box_type {
        open,
        short_circ,
        res1,
        res2,
        res3
    };

    enum junction_type {
        start,
        standard,
        dropoff
    };

    Robot(robot_link& RLINK);


    //--------- Motion Methods -----------//

    void MoveForward(const uint& speed, const float& time = 0.0);
    void MoveBackward(const uint& speed, const float& time = 0.0);
    void StopMoving();

    void MoveDist(const float& distance, const bool& reverse = false);
    void TurnDegrees(const float& angle);

    const int FollowLine();

    int  JunctionAction(direction, junction_type);

    int StartJunctionAction(direction);

    const int CheckForTurntable();

    const int TurntableAction(direction direction);

    // function ensures the robot stops in the start box correctly
    void StopAtStart();

    //----- Box interaction Methods ------//

    void PickUpBoxes();

    void DropBoxes(bool bottom_box);


    Robot::box_type IdentifyBox();

    // determines whether the robot is to stop at the start nodes
    bool ReturnToStart = false;

};

#endif
