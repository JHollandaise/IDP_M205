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
//    MotionControl controller(rlink);
    int val;
    while(true)
    {
        val = rlink.request(READ_PORT_4);
//        rlink.command(WRITE_PORT_4, val | 64);
        rlink.command(WRITE_PORT_4, 255);
        wait(1);

        val = rlink.request(READ_PORT_4);
        std::cout<<(val & 64)<<std::endl;
//        rlink.command(WRITE_PORT_4, val & 191);
        rlink.command(WRITE_PORT_4, 0);
        std::cout<<(rlink.request(READ_PORT_4))<<std::endl;
        wait(2);
    }


//
//    controller.robot.chassis_pos = 2;
//    controller.robot.ChassisMidPos();
//    controller.ControlMotion(MotionControl::Sl);
    return 0;
}

