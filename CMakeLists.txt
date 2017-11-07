cmake_minimum_required(VERSION 3.8)
project(IDP_M205)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/main.cpp
        src/motor.cpp
        src/motor.h
        src/robot.h
        testing/init_test.cpp src/robot.cpp src/ErrorLog.cpp src/ErrorLog.h)

add_executable(IDP_M205 ${SOURCE_FILES})