cmake_minimum_required(VERSION 4.3)
project(PA1UNO)

set(CMAKE_CXX_STANDARD 20)

add_executable(PA1UNO main.cpp
        Stack.h
        Card.h
        Card.cpp
        Player.cpp)
