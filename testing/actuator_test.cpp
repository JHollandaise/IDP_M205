#include <robot_link.h>
#include <robot_instr.h>
#include "../src/robot.h"
#include "../src/global.h"

int main()
{
    robot_link rlink = setup_link();

    while (true)
    {
        std::cout << "High" << std::endl;
        rlink.command(WRITE_PORT_5, 255);
        Wait(1);
        std::cout << "Low" << std::endl;
        Wait(1);
    }

    return 0;
}

