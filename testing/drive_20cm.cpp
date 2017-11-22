// Program to test robot movement

#include "../src/robot.h"
#include <robot_instr.h>
#include <robot_link.h>

int main()
{
    robot_link rlink;
    Robot robot(rlink);

    robot.MoveDist(0.2, false);    

    return 0;
}


