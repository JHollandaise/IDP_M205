# Automatically generated Makefile
main :  distance_sensor.o light_sensor.o main.o MotionControl.o motor.o robot.o sensor_base.o
	 g++ -L/export/teach/1BRobot -o main  distance_sensor.o  light_sensor.o  main.o  MotionControl.o  motor.o  robot.o  sensor_base.o  -lrobot

distance_sensor.o: distance_sensor.cpp distance_sensor.h global.h
	g++ -std=c++11 -Wall -g -I/export/teach/1BRobot -c distance_sensor.cpp
light_sensor.o: light_sensor.cpp light_sensor.h global.h
	 g++ -std=c++11 -Wall -g -I/export/teach/1BRobot -c light_sensor.cpp
main.o: main.cpp MotionControl.h
	 g++ -std=c++11 -Wall -g -I/export/teach/1BRobot -c main.cpp
MotionControl.o: MotionControl.cpp MotionControl.h
	 g++ -std=c++11 -Wall -g -I/export/teach/1BRobot -c MotionControl.cpp
motor.o: motor.cpp motor.h
	 g++ -std=c++11 -Wall -g -I/export/teach/1BRobot -c motor.cpp
robot.o: robot.cpp motor.h robot.h global.h
	 g++ -std=c++11 -Wall -g -I/export/teach/1BRobot -c robot.cpp
sensor_base.o: sensor_base.cpp sensor_base.h global.h
	 g++ -std=c++11 -Wall -g -I/export/teach/1BRobot -c sensor_base.cpp
