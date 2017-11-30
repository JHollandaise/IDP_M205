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

    MotionControl controller(rlink);

    controller.robot.actuatorTop.PistonDown();
    wait(1);
    controller.robot.actuatorTop.PistonUp();
    wait(1);

//    while(true)
//    {s
//        std::cout<<controller.robot.LSensorCentre.Output();
//        wait(0.5);
//    }
//    controller.robot.chassis_pos = 0;
//    controller.robot.ChassisMidPos();
    //controller.ControlMotion(MotionControl::Sl);
    return 0;
}

