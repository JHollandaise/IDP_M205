// Program to test the line-following algorithm

#include "../src/robot.h"
#include "../src/global.h"
#include <robot_instr.h>
#include <robot_link.h>

int main()
{
    robot_link rlink = setup_link();
    Robot robot(rlink);

    std::cout << robot.FollowLine() << std::endl;

    return 0;
}
