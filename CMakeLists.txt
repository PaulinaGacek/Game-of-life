cmake_minimum_required(VERSION 3.17)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)

add_executable(GameOfLife src/main.cpp src/console/ConsoleBoard.cpp src/console/ConsoleBoard.h src/common/Algorithm.cpp src/common/Algorithm.h src/common/config.txt)