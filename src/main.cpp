#include <robot_link.h>
#include <robot_instr.h>

#include <iostream>

#include "MotionControl.h"
int main()
{

    MotionControl controller;

    std::cout<< controller.GetShortestPath("D1","P2");
    return 0;
}