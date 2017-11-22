// Program to test robot movement

#include "../src/robot.h"
#include <robot_instr>
#include <robot_link>

int main()
{
    robot_link rlink;
    Robot robot(rlink);

    robot.MoveDist(0.2);    

    return 0;
}


