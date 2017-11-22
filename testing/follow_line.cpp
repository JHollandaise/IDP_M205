// Program to test the line-following algorithm

#include "../src/robot.h"
#include <robot_instr.h>
#include <robot_link.h>

int main()
{
    robot_link rlink;
    Robot robot(rlink);

    std::cout << robot.FollowLine() << std::endl;

    return 0;
}
