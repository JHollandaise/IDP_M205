#include <robot_instr.h>
#include <robot_link.h>

class Robot
{
private:
    // Robot link for connecting to the robot
    robot_link rlink;

    // The front motors
    Motor MotorLeft(rlink);
    Motor MotorRight(rlink);
}




