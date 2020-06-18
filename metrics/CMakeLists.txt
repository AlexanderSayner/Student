# cmake_minimum_required(VERSION <specify CMake version here>)
project(metrics)

set(CMAKE_CXX_STANDARD 20)

add_executable(metrics main.cpp FIleReader.cpp FIleReader.h flower.h DataService.cpp DataService.h ControlPanel.cpp ControlPanel.h first/main.cpp)
