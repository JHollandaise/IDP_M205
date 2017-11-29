#include <iostream>
#include <robot_instr.h>
#include <robot_link.h>
#include <stopwatch.h>
#include "robot.h"
#include "motor.h"

int main()
{
	robot_link rlink;
	
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

