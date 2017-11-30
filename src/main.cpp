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

