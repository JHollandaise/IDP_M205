// Program to test sensor input and output
#include <iostream>
#include <robot_instr.h>
#include <robot_link.h>
#include <vector>
#define ROBOT_NUM 8     // The id number (see below)

using namespace std;
robot_link rlink;      // datatype for the robot link

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
    int last_reading = rlink.request(READ_PORT_0);    
    cout << last_reading << endl;    

    while (last_reading != 129)
    { 
	if (rlink.request(READ_PORT_0) != last_reading)
	{ 	
	    last_reading = rlink.request(READ_PORT_0);
	    cout << last_reading << endl;   
	} 
    }
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

