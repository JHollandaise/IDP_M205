#include <iostream>
#include <cstdlib>
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
	
	//Robot robot(rlink);
	//std::cout << robot.FollowLine() << std::endl;
	
	// parse node inputs

	/*
    std::vector<MotionControl::Node > node_args;

    for (int i = 1; i < argc; ++i)
    {

        node_args.push_back(static_cast<MotionControl::Node>(atoi(argv[i])));
    }
    */

    //stopwatch watch;

    //MotionControl controller(rlink);

    //controller.ControlMotion(MotionControl::Sl);


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

