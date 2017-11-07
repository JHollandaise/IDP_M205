#ifndef robot_link.h
#include <robot_link.h>
#endif

// Useful constants
#define MAX_MOTOR_SPEED 127
#define MAX_MOTOR_REVERSE_SPEED 255

// Motor class declaration
class Motor
{
 public:
     Motor(const robot_link rlink, const int& motor_number, const int& motor_go_number);

     void MoveForward() const;
     void MoveForward(const uint& speed) const;
     void MoveBackward() const;
     void MoveBackward(const uint& speed) const;

 private:
     int m_DefaultSpeed;
     int m_MotorNumber;
     int m_MotorGo;
     const robot_link m_Rlink;
}


