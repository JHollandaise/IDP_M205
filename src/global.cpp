#include <robot_link.h>
#include <robot_instr.h>
#include <ctime>
#include "global.h"

void Wait(const float& time)
{   // Wait by the specified amount of time
    clock_t t1 = clock();

    // Wait until the time has elapsed
    while (float(clock() - t1)/CLOCKS_PER_SEC < time) {};
}

robot_link setup_link()
{	// Initialise a robot link
    robot_link rlink;

    #ifdef __arm__
        // Set up link on the ARM microprocessor
        if (!rlink.initialise ()) {
            rlink.print_errs("  ");
        } else {
			std::cout << "Connection successful" << std::endl;
		}
    #else
        // Set up link from the computer
        if (!rlink.initialise (ROBOT_NUM)) {
            rlink.print_errs("  ");
        } else {
			std::cout << "Connection established" << std::endl;
		}
    #endif

    return rlink;
}

