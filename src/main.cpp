#include <iostream>
#include <robot_instr.h>
#include <robot_link.h>
#include "robot.h"
#include "motor.h"
#include "MotionControl.h"

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
    
    std::cout << "Port 0: " << rlink.request(READ_PORT_0) << std::endl;
    std::cout << "Port 1: " << rlink.request(READ_PORT_1) << std::endl;
    std::cout << "Port 2: " << rlink.request(READ_PORT_2) << std::endl;
    
    MotionControl controller(rlink);
    int val = controller.robot.FollowLine();
	
	std::cout << "Exited with code " << val << std::endl;
	
    //MotionControl controller();

	return 0;
}

