#ifndef ROBOT_H
#define ROBOT_H

#include <robot_instr.h>
#include <robot_link.h>

#include "motor.h"
#include "light_sensor.h"
#include "ErrorLog.h"
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

    ErrorLog& errorLog;




public:

    enum direction {
        LEFT,
        RIGHT,
        STRAIGHT
    };

    Robot(const robot_link& rlink);



    //--------- Motion Methods -----------//

    void MoveForward(const uint& speed, const ufloat& time = 0.0) const;
    void MoveBackward(const uint& speed, const ufloat& time = 0.0) const;
    void StopMoving() const;

    void MoveDist(const ufloat& distance, const bool& reverse = false) const;
    void TurnDegrees(const float& angle) const;

    const int FollowLine(const uint& strategy = 0, const bool& stop = false) const;

    void  JunctionAction(direction direction) const;

    const int CheckForTurntable() const;




    //----- Box interaction Methods ------//

    void PickUpBoxes(int num_boxes) const;

    void DropBoxes(int drop_type) const;

    std::vector<MotionControl::box_type> IdentifyBoxes(int num_boxes);

};

#endif
