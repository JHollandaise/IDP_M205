#include <iostream>
#include "MotionControl.h"
int main()
{


    MotionControl controller;

    auto a = controller.GetAllPaths(MotionControl::P1,MotionControl::Sl);
    auto b = controller.GetShortestPath(a);
    int c = 4;
    return 0;
}