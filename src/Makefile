# Automatically generated Makefile
<<<<<<< HEAD
main :  actuator.o distance_sensor.o global.o led.o light_sensor.o main.o motor.o robot.o sensor_base.o
	 g++ -L/export/teach/1BRobot -o main  actuator.o  distance_sensor.o  global.o  led.o  light_sensor.o  main.o motor.o  robot.o  sensor_base.o  -lrobot

actuator.o: actuator.cpp global.h actuator.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c actuator.cpp
=======
main :  distance_sensor.o light_sensor.o main.o  motor.o  sensor_base.o robot.o  MotionControl.o  global.o  actuator.o  led.o
	 g++ -L/export/teach/1BRobot -o main  distance_sensor.o  light_sensor.o  main.o  motor.o  sensor_base.o  MotionControl.o  robot.o  global.o  actuator.o  led.o -lrobot
actuator.o: actuator.cpp motor.h global.h
	 g++ -std=c++11 -Wall -g -I/export/teach/1BRobot -c actuator.cpp
>>>>>>> master
distance_sensor.o: distance_sensor.cpp distance_sensor.h global.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c distance_sensor.cpp
global.o: global.cpp global.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c global.cpp
led.o: led.cpp global.h led.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c led.cpp
light_sensor.o: light_sensor.cpp light_sensor.h global.h
<<<<<<< HEAD
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c light_sensor.cpp
main.o: main.cpp robot.h motor.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c main.cpp
=======
	 g++ -std=c++11 -Wall -g -I/export/teach/1BRobot -c light_sensor.cpp
main.o: main.cpp robot.h MotionControl.h
	 g++ -std=c++11 -Wall -g -I/export/teach/1BRobot -c main.cpp
MotionControl.o: MotionControl.cpp MotionControl.h
	 g++ -std=c++11 -Wall -g -I/export/teach/1BRobot -c MotionControl.cpp
>>>>>>> master
motor.o: motor.cpp motor.h global.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c motor.cpp
robot.o: robot.cpp motor.h robot.h global.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c robot.cpp
sensor_base.o: sensor_base.cpp sensor_base.h global.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c sensor_base.cpp
