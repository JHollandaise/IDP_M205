#ifndef LED_H
#define LED_H

#include <robot_instr.h>
#include <robot_link.h>
#include "global.h"

// LED class declaration
class LED
{
 public:
    LED(robot_link& RLINK, const command_instruction& PORT_NUMBER);

    void TurnOn();
    void TurnOff();
    void Toggle();

	enum STATUS {ON, OFF};

    STATUS GetStatus() const;
    

private:
    robot_link rlink;
    command_instruction WRITE_PORT;
    STATUS status;
};


#endif
