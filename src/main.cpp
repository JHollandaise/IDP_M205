#include <iostream>
#include <robot_instr.h>
#include <robot_link.h>
#include <stopwatch.h>
#include "gloabl.h"
#include "robot.h"
#include "motor.h"


int main()
{
	robot_link rlink = setup_link();
	
	while (true)
	{
		std::cout << "High" << std::endl;
		rlink.command(WRITE_PORT_5, 255);
		Wait(1);
		std::cout << "Low" << std::endl;
		rlink.command(WRITE_PORT_5, 0);
		Wait(1);
	}

    //MotionControl controller();

	return 0;
}

