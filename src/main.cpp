#include <iostream>
#include <robot_instr.h>
#include <robot_link.h>
#include "robot.h"

#include "MotionControl.h"
int main()
{
	robot_link rlink;
	Robot robot(rlink);
	
	robot.MoveForward(50, 10.0);
	
    MotionControl controller(robot);

}

