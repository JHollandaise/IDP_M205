// Program for timing the complete operation of an instruction
#include <iostream>
#include <robot_instr.h>
#include <robot_link.h>
#include <stopwatch.h>
#define ROBOT_NUM 8

using namespace std;
robot_link rlink;    // Link to the robot


int main ()
{
int val;                              // data from microprocessor
if (!rlink.initialise (ROBOT_NUM)) { // setup the link
  cout << "Cannot initialise link" << endl;
  rlink.print_errs("  ");
  return -1;
}
val = rlink.request (TEST_INSTRUCTION); // send test instruction
if (val == TEST_INSTRUCTION_RESULT) {   // check result
    // Start the timer
    stopwatch watch;
    watch.start();

    // Send a request ITER times
    const int ITER = 1000;
    for (int i = 0; i < ITER; i++)
        {   rlink.request(STATUS);  }

    // Stop timer and record time taken
    const float time = float(watch.stop())/float(ITER);
    cout << "Test passed at " << time << " ms/iteration" << endl;

  return 0;                            // all OK, finish
}
else if (val == REQUEST_ERROR) {
  cout << "Fatal errors on link:" << endl;
  rlink.print_errs();
}
else
  cout << "Test failed (bad value returned)" << endl;
return -1;                          // errorLog, finish
}

