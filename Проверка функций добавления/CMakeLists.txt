cmake_minimum_required(VERSION 3.10)
project(532)
add_executable(${PROJECT_NAME} main.cpp)
target_sources(${PROJECT_NAME} PRIVATE list.cpp list.h)
