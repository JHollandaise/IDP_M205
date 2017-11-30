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
	Robot robot(rlink);
	
	/*
	while (true)
	{
		std::cout << robot.LSensorLeft.Output() << " " << robot.LSensorCentre.Output() << " " << robot.LSensorRight.Output() << std::endl;
		wait(1);
	}
	*/
	
	std::cout << robot.FollowLine() << std::endl;
	
	//std::cout << robot.IdentifyBox() << std::endl;

//    stopwatch watch;
//    watch.start();
//
//    int val;
//
//    val = rlink.request(READ_PORT_4) | 64;
//
//    rlink.command(WRITE_PORT_4, val);
//    while (watch.read() < 5000) {}
//
//    val = rlink.request(READ_PORT_4) & 191;
//    rlink.command(WRITE_PORT_4, val);

    return 0;
}

