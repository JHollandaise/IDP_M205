#include <iostream>
#include <robot_instr.h>
#include <robot_link.h>
#include "MotionControl.h"
#include <stopwatch.h>

int main(int argc, char** argv)
{
	// parse node inputs

    std::vector<MotionControl::Node > node_args;

    for (int i = 1; i < argc; ++i)
    {

        node_args.push_back(static_cast<MotionControl::Node>(atoi(argv[i])));
    }




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


    stopwatch watch;

    MotionControl controller(rlink);

    controller.ControlMotion(MotionControl::Sl);


//    // raise to see line
//    rlink.command(MOTOR_1_GO,127 + 128);
//    while(!(rlink.request(READ_PORT_5) & 2)){}
//    Wait(0.2);
//    rlink.command(MOTOR_1_GO,0);
//
//    rlink.command(MOTOR_2_GO,120);
//    rlink.command(MOTOR_3_GO,120+128);
//
//
//
//    rlink.command(MOTOR_1_GO,127 + 128);
//    Wait(2);
//    rlink.command(MOTOR_1_GO,0);
//    Wait(5);
//
//    rlink.command(MOTOR_1_GO,127);
//    while(!(rlink.request(READ_PORT_5) & 2)){}
//    rlink.command(MOTOR_1_GO,0);


//    while(rlink.request(READ_PORT_4) & 32)
//    {}
//
//    std::cout<<"time to stop " << watch.stop() << std::endl;

//    MotionControl controller(rlink);



	return 0;
}

