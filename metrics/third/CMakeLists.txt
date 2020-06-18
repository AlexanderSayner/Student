cmake_minimum_required(VERSION 3.13)
project(third)

set(CMAKE_CXX_STANDARD 20)

add_executable(third main.cpp FIleReader.cpp FIleReader.h DataService.cpp DataService.h ControlPanel.cpp ControlPanel.h)