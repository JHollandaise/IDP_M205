# Automatically generated Makefile
main :  distance_sensor.o light_sensor.o main.o  motor.o  sensor_base.o robot.o  MotionControl.o  global.o  actuator.o  led.o
	 g++ -L/export/teach/1BRobot -o main  distance_sensor.o  light_sensor.o  main.o  motor.o  sensor_base.o  MotionControl.o  robot.o  global.o  actuator.o  led.o -lrobot
actuator.o: actuator.cpp motor.h global.h
	 g++ -std=c++11 -Wall -g -I/export/teach/1BRobot -c actuator.cpp
distance_sensor.o: distance_sensor.cpp distance_sensor.h global.h
	 g++ -std=c++11 -Wall -g -I/export/teach/1BRobot -c distance_sensor.cpp
global.o: global.cpp global.h
	 g++ -std=c++11 -Wall -g -I/export/teach/1BRobot -c global.cpp
led.o: led.cpp motor.h global.h
	 g++ -std=c++11 -Wall -g -I/export/teach/1BRobot -c led.cpp
light_sensor.o: light_sensor.cpp light_sensor.h global.h
	 g++ -std=c++11 -Wall -g -I/export/teach/1BRobot -c light_sensor.cpp
main.o: main.cpp robot.h MotionControl.h
	 g++ -std=c++11 -Wall -g -I/export/teach/1BRobot -c main.cpp
MotionControl.o: MotionControl.cpp MotionControl.h
	 g++ -std=c++11 -Wall -g -I/export/teach/1BRobot -c MotionControl.cpp
motor.o: motor.cpp motor.h global.h
	 g++ -std=c++11 -Wall -g -I/export/teach/1BRobot -c motor.cpp
robot.o: robot.cpp motor.h robot.h global.h
	 g++ -std=c++11 -Wall -g -I/export/teach/1BRobot -c robot.cpp
sensor_base.o: sensor_base.cpp sensor_base.h global.h
	 g++ -std=c++11 -Wall -g -I/export/teach/1BRobot -c sensor_base.cpp
