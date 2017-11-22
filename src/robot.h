#ifndef ROBOT_H
#define ROBOT_H

#include <robot_instr.h>
#include <robot_link.h>

#include "motor.h"
#include "light_sensor.h"
#include "distance_sensor.h"
#include "global.h"
#include "MotionControl.h"


class Robot
{
private:
    // Robot link for connecting to the robot
    robot_link rlink;

    // The front motors
    Motor motorLeft;
    Motor motorRight;

    // Determines what direction is "forward" for a given motor
    // True if **clockwise** is forward
    bool motorLeftDir;
    bool motorRightDir;

    // Speed the robot is currently travelling at
    int mSpeed;

    // The three light senssors
    LightSensor LSensorLeft;
    LightSensor LSensorCentre;
    LightSensor LSensorRight;

    // The distance sensor
    DistanceSensor DSensor;


public:

    enum direction {
        LEFT,
        RIGHT,
        STRAIGHT
    };

    Robot(const robot_link& rlink);


<<<<<<< HEAD
=======



>>>>>>> master
    //--------- Motion Methods -----------//

    void MoveForward(const uint& speed, const float& time = 0.0) const;
    void MoveBackward(const uint& speed, const float& time = 0.0) const;
    void StopMoving() const;

    void MoveDist(const float& distance, const bool& reverse = false) const;
    void TurnDegrees(const float& angle) const;

    const int FollowLine(const bool& stop = false) const;

    int  JunctionAction(direction) const;

    int StartJunctionAction(direction);

    const int CheckForTurntable() const;

    const int TurntableAction(direction direction) const;

    // function ensures the robot stops in the start box correctly
    void StopAtStart();

    //----- Box interaction Methods ------//

    void PickUpBoxes(int num_boxes) const;

    void DropBoxes(bool bottom_box) const;

    MotionControl::box_type IdentifyBox();


    // determines whether the robot is to stop at the start nodes
    bool ReturnToStart = false;

<<<<<<< HEAD
    
=======
>>>>>>> master

};

#endif
