cmake_minimum_required(VERSION 3.8)
project(IDP_M205)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/distance_sensor.cpp
        src/distance_sensor.h
        src/global.h
        src/light_sensor.cpp
        src/light_sensor.h
        src/main.cpp
        src/MotionControl.cpp
        src/MotionControl.h
        src/motor.cpp
        src/motor.h
        src/robot.cpp
        src/robot.h
        src/sensor_base.cpp
        src/sensor_base.h
        src/actuator.cpp
        src/actuator.h
        src/led.cpp
        src/led.h
        testing/drive_20cm.cpp
        testing/init_test.cpp
        testing/sensor_simulation.cpp
        testing/test_main.cpp
        testing/time_test.cpp src/global.cpp)

add_executable(IDP_M205 ${SOURCE_FILES})