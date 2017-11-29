#include <iostream>
#include <robot_instr.h>
#include <robot_link.h>
#include <stopwatch.h>
#include "global.h"
#include "robot.h"
#include "motor.h"
#include "MotionControl.h"


int main()
{
	robot_link rlink = setup_link();
	
	while (true)
	{
		std::cout << "High" << std::endl;
		rlink.command(WRITE_PORT_5, 255);
		wait(1);
		std::cout << "Low" << std::endl;
		rlink.command(WRITE_PORT_5, 0);
		wait(1);
	}

    return 0;
}

