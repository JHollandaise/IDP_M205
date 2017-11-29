# Automatically generated Makefile
main :  actuator.o distance_sensor.o global.o led.o light_sensor.o main.o motor.o robot.o sensor_base.o
	 g++ -L/export/teach/1BRobot -o main  actuator.o  distance_sensor.o  global.o  led.o  light_sensor.o  main.o motor.o  robot.o  sensor_base.o  -lrobot

actuator.o: actuator.cpp global.h actuator.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c actuator.cpp
distance_sensor.o: distance_sensor.cpp distance_sensor.h global.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c distance_sensor.cpp
global.o: global.cpp global.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c global.cpp
led.o: led.cpp global.h led.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c led.cpp
light_sensor.o: light_sensor.cpp light_sensor.h global.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c light_sensor.cpp
main.o: main.cpp robot.h motor.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c main.cpp
motor.o: motor.cpp motor.h global.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c motor.cpp
robot.o: robot.cpp motor.h robot.h global.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c robot.cpp
sensor_base.o: sensor_base.cpp sensor_base.h global.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c sensor_base.cpp
